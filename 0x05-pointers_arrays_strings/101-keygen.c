#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

/* 
 * is_valid_ascii - checks if the given ASCII value corresponds to a valid character 
 * @value: the ASCII value to check 
 * Return: 1 if valid, 0 otherwise 
 */
int is_valid_ascii(int value) {
    return (value >= 48 && value <= 57)   || 
           (value >= 65 && value <= 90)   || 
           (value >= 97 && value <= 122)  || 
           (value >= 33 && value <= 47)   || 
           (value >= 58 && value <= 64)   || 
           (value >= 91 && value <= 96)   || 
           (value >= 123 && value <= 126);   
}

/* 
 * main - main function to generate a password 
 * Return: 0 if successful 
 */
int main(void)
{
    char password[PASSWORD_LENGTH + 1]; /* +1 for null terminator */
    int i, ascii_value;

    srand(time(NULL)); /* Seed random number generator */

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        do {
            ascii_value = rand() % 127; /* Generate ASCII value between 0 and 126 */
        } while (!is_valid_ascii(ascii_value));

        password[i] = (char)ascii_value;
    }

    password[PASSWORD_LENGTH] = '\0'; /* Null terminate the password string */

    printf("%s\n", password);

    return 0;
}
