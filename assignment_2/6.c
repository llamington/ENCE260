#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

// Common declarations
#define MAX_TEXTFILE_SIZE 4096
#define MAX_FILENAME_LENGTH 80
#define MAX_NUMBER_AGENTS 15
#define MAX_AGENTNAME_LENGTH 45
#define MAX_LINE_LENGTH 96

typedef struct
{
    char name[MAX_AGENTNAME_LENGTH];
    size_t key;
} Agent;

typedef struct
{
    size_t size;
    size_t next;
    Agent pool[MAX_NUMBER_AGENTS];
} AgentPool;

size_t readText(FILE *file, char text[], size_t maxTextSize);
size_t readCipherBook(FILE *file, char text[], size_t maxTextSize);
size_t readMessage(FILE *file, char text[], size_t maxTextSize);

void initAgentPool(AgentPool *agentPool);
Agent *newAgent(AgentPool *agentPool);
void deleteAgent(Agent *agent, AgentPool *agentPool);
Agent *readAgent(FILE *file, AgentPool *agentPool);
Agent *findAgent(char name[], AgentPool *agentPool);
void readAgentName(char agentName[], size_t maxAgentNameLength);

void encryptMessage(char book[], size_t bookLength, Agent *agent, char message[], size_t messageLength) {
    int key = agent->key % bookLength;
    for (int i = 0; i < messageLength; i++) {
        message[i] = (book[key++] + message[i]) % 98;
        key = key % bookLength;
    }
}

void decryptMessage(char book[], size_t bookLength, Agent *agent, char message[], size_t messageLength) {
    int key = agent->key % bookLength;
    for (int i = 0; i < messageLength; i++) {
        message[i] = (((message[i] - book[key++]) % 98) + 98) % 98;
        key = key % bookLength;
        if (1 <= message[i] && message[i] <= 95) {
            message[i] += 31;
        } else if (message[i] == 96) {
            message[i] = '\t';
        } else if (message[i] == 97) {
            message[i] = '\n';
        }
    }
}

int main(void)
{
    char filename[80] = "";
    char agentname[MAX_AGENTNAME_LENGTH] = "";
    FILE *file = NULL;
    char book[MAX_TEXTFILE_SIZE] = "";
    char message[MAX_TEXTFILE_SIZE] = "";
    size_t bookLength = 0;
    size_t messageLength = 0;
    AgentPool agentPool;
    Agent *agent = NULL;

    // Read in the cipher book
    scanf("%80s", filename);
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found... program will fail with segmentation fault\n");
    }
    bookLength = readCipherBook(file, book, MAX_TEXTFILE_SIZE);
    fclose(file);

    // Read in the message
    scanf("%80s", filename);
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found... program will fail with segmentation fault\n");
    }
    messageLength = readMessage(file, message, MAX_TEXTFILE_SIZE);
    fclose(file);

    scanf("%80s", filename);
    initAgentPool(&agentPool);
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found... program will fail with segmentation fault\n");
    }
    while (!feof(file))
    {
        readAgent(file, &agentPool);
    }
    fclose(file);

    getchar();
    readAgentName(agentname, MAX_AGENTNAME_LENGTH);
    agent = findAgent(agentname, &agentPool);
    if (agent != NULL)
    {
        encryptMessage(book, bookLength, agent, message, messageLength);
        printf("Secret message is: ");
        for (size_t i = 0; i < messageLength; i++)
        {
            printf(" %d", message[i]);
        }
        decryptMessage(book, bookLength, agent, message, messageLength);
        printf("\nDecrypted message is: %s\n", message);
    }
    else
    {
        printf("No Agent found by the name %s\n", agentname);
    }
    return 0;
}

Agent *findAgent(char name[], AgentPool *agentPool)
{
    // returns reference to agent matching name, or NULL if name not in agentPool
    for (int i = 0; i < MAX_NUMBER_AGENTS; i++)
    {
        if (strncmp(name, agentPool->pool[i].name, MAX_AGENTNAME_LENGTH) == 0)
        {
            return &agentPool->pool[i];
        }
    }
    return NULL;
}

// A function to initialise an AgentPool structure
void initAgentPool(AgentPool *agentPool)
{
    agentPool->size = MAX_NUMBER_AGENTS;
    agentPool->next = 0;
}

// A function to read a file with agent data in it, adding the agent to a agentlist and returning a reference to the agent
Agent *readAgent(FILE *file, AgentPool *agentPool)
{
    char line[MAX_LINE_LENGTH];
    int successAgentName = 0;
    int successAgentKey = 0;
    Agent *agent = newAgent(agentPool);

    if (fgets(line, MAX_LINE_LENGTH, file) && agent)
    {
        size_t i;
        for (i = 0; i < strlen(line) && line[i] != ',' && i < MAX_AGENTNAME_LENGTH - 1; i++)
        {
            agent->name[i] = line[i];
        }
        agent->name[i] = '\0';
        while (i < strlen(line) && line[i] != ',')
        {
            i++;
        }
        if (line[i] == ',' && strlen(agent->name) > 0)
        {
            i++;
            successAgentName = 1;
            successAgentKey = sscanf(line + i, "%zu", &agent->key) == 1;
        }
    }
    if (agent && !(successAgentName && successAgentKey))
    {
        deleteAgent(agent, agentPool);
        agent = NULL;
    }
    return agent;
}

// A function to delete an agent from an AgentPool
void deleteAgent(Agent *agent, AgentPool *agentPool)
{
    int i;
    int move = 0;
    for (i = 0; i < agentPool->next - 1; i++)
    {
        if (move || &agentPool->pool[i] == agent)
        {
            move = 1;
            agentPool->pool[i] = agentPool->pool[i + 1];
        }
    }

    agentPool->next--;
}

void readAgentName(char agentName[], size_t maxAgentNameLength)
{
    char c;
    size_t i;

    c = getchar();
    for (i = 0; i < maxAgentNameLength - 1 && c != '\n'; i++)
    {
        agentName[i] = c;
        c = getchar();
    }
    agentName[i] = '\0';
}

Agent *newAgent(AgentPool *agentPool)
{
    Agent *next_available;
    if (agentPool->next != agentPool->size)
    {
        next_available = agentPool->pool + agentPool->next;
        agentPool->next++;
        return next_available;
    }
    else
    {
        return NULL;
    }
}

size_t readText(FILE *file, char text[], size_t maxTextSize)
{
    int i = 0;
    int c;
    while (i < maxTextSize - 1 && (c = fgetc(file)) != EOF)
    {
        text[i++] = c;
    }
    text[i] = '\0';
    return i;
}

size_t readMessage(FILE *file, char text[], size_t maxTextSize)
{
    size_t text_size = readText(file, text, maxTextSize);
    char transformed_text[maxTextSize];
    int transformed_text_index = 0;
    int c;
    for (int i = 0; i < text_size; i++)
    {
        c = text[i];
        if (c >= ' ' && c <= '~')
        {
            transformed_text[transformed_text_index++] = c - 31;
        }
        else if (c == '\t')
        {
            transformed_text[transformed_text_index++] = 96;
        }
        else if (c == '\n')
        {
            transformed_text[transformed_text_index++] = 97;
        }
    }
    transformed_text[transformed_text_index] = '\0';
    strncpy(text, transformed_text, maxTextSize);
    return transformed_text_index;
}

size_t readCipherBook(FILE *file, char text[], size_t maxTextSize)
{
    size_t text_size = readText(file, text, maxTextSize);
    int reduced_text_size = 0;
    int c;
    char text_no_spaces[maxTextSize];
    for (int i = 0; i < text_size; i++)
    {
        c = text[i];
        if (!isspace(c))
        {
            text_no_spaces[reduced_text_size++] = c;
        }
    }
    text_no_spaces[reduced_text_size] = '\0';
    strncpy(text, text_no_spaces, maxTextSize);
    return reduced_text_size;
}