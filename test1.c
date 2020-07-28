#include <stdio.h>

int value = 11;

int main(void) {
    switch (value) {
        case 11:
            putchar('J');
        case 12:
            putchar('Q');
        case 13:
            putchar('K');
    }
}
