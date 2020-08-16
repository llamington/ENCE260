#include "stdio.h"

int isWonRow(char player, char game[3][3], int rowNum) {
    int num_chars = 0;
    for(int i = 0; i < 3; i++) {
        if(game[rowNum][i] == player) {
            num_chars++;
        }
    }
    if(num_chars == 3) {
        return 1;
    } else
    {
        return 0;
    }
    
}

int main(int argc, char const *argv[])
{
    char game[3][3] = {{'X', 'O', ' '}, {'X', 'X', 'X'}, {' ', ' ', ' '}};
    printf("%d\n", isWonRow('X', game, 1));
    return 0;
}
