#include "main.h"

unsigned int _strspn(char *s, char *accept) {
    unsigned int i, j, count = 0;

    for (i = 0; s[i] != '\0'; i++) {
        int found = 0;  // Flag to check if s[i] exists in accept

        for (j = 0; accept[j] != '\0'; j++) {
            if (s[i] == accept[j]) {
                found = 1;
                count++;
                break;  // No need to continue the inner loop once a match is found
            }
        }

        if (!found) {
            break;  // Exit the loop if the character is not found in accept
        }
    }

    return count;
}

