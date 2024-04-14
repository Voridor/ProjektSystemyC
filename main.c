#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void passwordGenerator(int N, bool special, bool big, bool small, bool numbersB)
{
    int i = 0;

    int randomizer = 0;
    srand((unsigned int)(time(NULL)));

    char numbers[] = "0123456789";

    char letter[] = "abcdefghijklmnoqprstuvwyzx";

    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    char symbols[] = "!@#$^&*?";

    char password[N];

    randomizer = rand() % 5;

    for (i = 0; i < N; i++) {

        if (randomizer == 1 && numbersB) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 5;
            printf("%c", password[i]);
        }
        else if (randomizer == 2&& special) {
            password[i] = symbols[rand() % 8];
            randomizer = rand() % 5;
            printf("%c", password[i]);
        }
        else if (randomizer == 3 && big) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 5;
            printf("%c", password[i]);
        }
        else if (randomizer == 4 && small) {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 5;
            printf("%c", password[i]);
        }
        else {
            randomizer = rand() % 5;
            i--;
        }
    }
}
int main()
{
    int N = 10;
    char temp = ' ';

    bool special = false;
    bool big = false;
    bool small = false;
    bool numbers = false;

    printf("Jaka dlugosc powinno miec haslo?(bazowo 10 znakow): \n");
    scanf("%d", &N);
    printf("Czy haslo ma zawierac znaki specjalne? (t/n): \n");
    scanf(" %c", &temp);
    if (temp == 't') {
        special = true;
    }
    temp == ' ';
    printf("Czy haslo ma zawierac wielkie litery? (t/n): \n");
    scanf(" %c", &temp);
    if (temp == 't') {
        big = true;
    }
    temp == ' ';
    printf("Czy haslo ma zawierac male litery? (t/n): \n");
    scanf(" %c", &temp);
    if (temp == 't') {
        small = true;
    }
    temp == ' ';
    printf("Czy haslo ma zawierac numery? (t/n): \n");
    scanf(" %c", &temp);
    if (temp == 't') {
        numbers = true;
    }
    temp == ' ';
    passwordGenerator(N, special, big, small,numbers);
    return 0;
}