#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random passwords for the program 101-crackme, ensuring
 * the sum of ASCII values equals 2772.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    const int MAX_SIZE = 100;
    const char ASCII_OFFSET = '0';
    const int TARGET_SUM = 2772;

    int current_sum = 0;
    int required_val, random_val;
    int i;

    srand(time(NULL));  /* Seed the random number generator */

    for (i = 0; i < MAX_SIZE; i++)
    {
        random_val = rand() % 78;  /* Generate a random value between 0 and 77 */
        current_sum += (random_val + ASCII_OFFSET);

        /* If adding another random character can exceed TARGET_SUM, adjust the value */
        required_val = TARGET_SUM - current_sum;
        if (required_val < 78)
        {
            printf("%c", required_val + ASCII_OFFSET);
            break;
        }

        printf("%c", random_val + ASCII_OFFSET);
    }

    return 0;
}
