#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* int tab[rzedy(y)][kolumny(x)]

   for(rzedy)
     for(kolumny)
       tab[rzed][kol]
*/

void zadanie_4()
{
    int tabA[3][4];
    int tabB[3][4];
    int tabC[3][4] = {0};

    srand(time(NULL));

    for(unsigned y = 0; y < 3; y++)
    {
        for(unsigned x = 0; x < 4; x++)
        {
            tabA[y][x] = rand() % (99 - (-99) + 1) + (-99);
            tabB[y][x] = rand() % (99 - (-99) + 1) + (-99);
        }
    }

    for(unsigned y = 0; y < 3; y++)
    {
        for(unsigned x = 0; x < 4; x++)
        {
            tabC[y][x] = tabA[y][x] + tabB[y][x];
        }
    }

    // ---- wydruk ----
    puts("Macierz A:");
    for(unsigned y = 0; y < 3; y++)
    {
        for(unsigned x = 0; x < 4; x++)
        {
            printf("%4d", tabA[y][x]);
        }
        putchar('\n');
    }
    putchar('\n');
    puts("Macierz B:");
    for(unsigned y = 0; y < 3; y++)
    {
        for(unsigned x = 0; x < 4; x++)
        {
            printf("%4d", tabB[y][x]);
        }
        putchar('\n');
    }
    putchar('\n');
    puts("Macierz (wynikowa) C:");
    for(unsigned y = 0; y < 3; y++)
    {
        for(unsigned x = 0; x < 4; x++)
        {
            printf("%4d", tabC[y][x]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void zadanie_8()
{
#define ROW_SIZE 8
#define COL_SIZE 12

    int tab[ROW_SIZE][COL_SIZE];
    int kolumna, rzad; // input
    int sum, min, max;
    float srednia;

    srand(time(NULL));
    for(unsigned y = 0; y < ROW_SIZE; y++)
    {
        for(unsigned x = 0; x < COL_SIZE; x++)
        {
            tab[y][x] = rand() % (99 - (-99) + 1) + (-99);
            printf("%4d", tab[y][x]);
        }
        putchar('\n');
    }

    puts("Podaj numer rzedu i kolumny(indeksuj od 1):");
    scanf("%d %d", &rzad, &kolumna);

    rzad--;
    kolumna--;

    sum = 0;
    min = tab[0][0];
    max = tab[0][0];
    for(int i = 0; i < COL_SIZE; i++)
    {
        if(tab[rzad][i] > max)
            max = tab[rzad][i];
        if(tab[rzad][i] < min)
            min = tab[rzad][i];

        sum += tab[rzad][i];
    }
    srednia = (float)sum/COL_SIZE;
    printf("Rzad: min: %d  max: %d  srednia: %.2f\n", min, max, srednia);

    sum = 0;
    min = tab[0][0];
    max = tab[0][0];
    for(int i = 0; i < ROW_SIZE; i++)
    {
        if(tab[i][kolumna] > max)
            max = tab[i][kolumna];
        if(tab[i][kolumna] < min)
            min = tab[i][kolumna];

        sum += tab[i][kolumna];
    }
    srednia = (float)sum/ROW_SIZE;
    printf("Kolumna: min: %d  max: %d  srednia: %.2f\n", min, max, srednia);

}

void redrawBoard(char tab[3][3]);
void zadanie_9()
{
    char pola[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};;

    pola[1][1] = 'X';
    pola[0][2] = 'O';
    redrawBoard(pola);
}

void redrawBoard(char tab[3][3])
{
    puts("-------------");
    printf("| %c | %c | %c |\n", tab[0][0], tab[0][1], tab[0][2]);
    puts("-------------");
    printf("| %c | %c | %c |\n", tab[1][0], tab[1][1], tab[1][2]);
    puts("-------------");
    printf("| %c | %c | %c |\n", tab[2][0], tab[2][1], tab[2][2]);
    puts("-------------");


}

int main()
{
    printf("\n");

    // zadanie_4();
    // zadanie_8();
    zadanie_9();

    return 0;
}
