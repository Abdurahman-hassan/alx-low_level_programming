#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

/**
  * is_valid_ascii - this will check if it valid or not
  * @value: the ascci value
  * Return: 0 if success
 */
int is_valid_ascii(int value) {
    // Check if value corresponds to valid character ranges
    return (value >= 48 && value <= 57)   ||  // digits
           (value >= 65 && value <= 90)   ||  // uppercase letters
           (value >= 97 && value <= 122)  ||  // lowercase letters
           (value >= 33 && value <= 47)   ||  // symbols
           (value >= 58 && value <= 64)   ||  // symbols
           (value >= 91 && value <= 96)   ||  // symbols
           (value >= 123 && value <= 126);   // symbols
}

/**
  * main - the main point
  * Return: 0 if success
 */
int main(void)
{
    char password[PASSWORD_LENGTH + 1]; // +1 for null terminator
    int i, ascii_value;

    srand(time(NULL)); // seed random number generator

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        do {
            ascii_value = rand() % 127; // Generate random ASCII value between 0 and 126
        } while (!is_valid_ascii(ascii_value)); // Ensure it's a valid character

        password[i] = (char)ascii_value;
    }

    password[PASSWORD_LENGTH] = '\0';

    printf("%s\n", password);

    return 0;
}

