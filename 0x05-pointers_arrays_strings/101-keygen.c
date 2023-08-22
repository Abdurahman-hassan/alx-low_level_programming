#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Program that generates random valid
 * passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int rand_pass[100]; /* Array to store random password components */
    int index, total_sum, num; /* Renamed variables */

    total_sum = 0;	

    srand(time(NULL)); /* Initialize random seed */

    /* Loop to generate random password components */
    for (index = 0; index < 100; index++)
    {
        rand_pass[index] = rand() % 78; /* Generate random number between 0 and 77 */
        total_sum += (rand_pass[index] + '0'); /* Update the ASCII sum */
        putchar(rand_pass[index] + '0'); /* Print the current password component */

        /* Check if the remaining sum to reach 2772 is less than 78 */
        if ((2772 - total_sum) - '0' < 78)
        {
            num = 2772 - total_sum - '0'; /* Calculate the required number to reach the sum of 2772 */
            total_sum += num; /* Update the total sum */
            putchar(num + '0'); /* Print the final password component */
            break;
        }
    }

    return (0);
}

