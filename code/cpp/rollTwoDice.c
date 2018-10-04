#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int die1, die2, sum;
    time_t t;
    srand((unsigned)time(&t));

    die1 = rand() % (6 - 1 + 1) + 1;
    die2 = rand() % (6 - 1 + 1) + 1;
    sum = die1 + die2;

    printf("You roll 2 six-sided dice.\n");
    printf("Die 1 result: [%d]\n", die1);
    printf("Die 2 result: [%d]\n", die2);
    printf("Total is [%d].\n", sum);

    return 0;
}