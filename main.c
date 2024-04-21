#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Funkcja generująca hasło
//N - długość hasła
//special - czy hasło ma zawierać znaki specjalne
//big - czy hasło ma zawierać wielkie litery
//small - czy hasło ma zawierać małe litery
//numbersB - czy hasło ma zawierać cyfry
//seed - ziarno dla generatora liczb losowych
void passwordGenerator(int N, bool special, bool big, bool small, bool numbersB, int seed)
{
    int i = 0;

    int randomizer = 0;
    //Ustawienie ziarna dla generatora liczb losowych
    if (seed != 0) {
        srand(seed);
    }
    else{
        srand((unsigned int)(time(NULL)));
    }
    char numbers[] = "0123456789";

    char letter[] = "abcdefghijklmnoqprstuvwyzx";

    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    char symbols[] = "!@#$^&*?";

    char password[N];

    randomizer = rand() % 5;
    //Generowanie hasła
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

    int seed =0;

    bool special = true;
    bool big = true;
    bool small = true;
    bool numbers = true;

    char input[100];

    //Pytanie o długość hasła
    printf("Jaka dlugosc powinno miec haslo?(bazowo 10 znakow): \n");
    char temp2[] = "";
    scanf( "%s", temp2);
    N = atoi(temp2);
    if (N == 0) {
        N = 10;
    }
    //Pytanie o ziarno dla generatora liczb losowych
    printf("Jakie powinno byc nasiono?(losowe dla 0): \n");
    scanf( "%s", temp2);
    seed = atoi(temp2);
    if (seed == 0) {
        seed = 0;
    }
    //Pytanie o zawieranie znaków specjalnych
    printf("Czy haslo ma zawierac znaki specjalne? (t/n)(bazowo t): \n");
    scanf(" %s", &temp);
    if (temp == 'n') {
        special = false;
    }
    temp = ' ';
    //Pytanie o zawieranie wielkich liter
    printf("Czy haslo ma zawierac wielkie litery? (t/n)(bazowo t): \n");
    scanf(" %s", &temp);
    if (temp == 'n') {
        big = false;
    }
    temp = ' ';
    //Pytanie o zawieranie małych liter
    printf("Czy haslo ma zawierac male litery? (t/n)(bazowo t): \n");
    scanf(" %s", &temp);
    if (temp == 'n') {
        small = false;
    }
    temp = ' ';
    //Pytanie o zawieranie cyfr
    printf("Czy haslo ma zawierac numery? (t/n)(bazowo t): \n");
    scanf(" %s", &temp);
    if (temp == 'n') {
        numbers = false;
    }
    temp = ' ';
    //Wywołanie funkcji generującej hasło
    passwordGenerator(N, special, big, small,numbers,seed);

    return 0;
}
