#include <stdio.h>

int main(void)
{
    int number, remaining, digit;
    long long reversed = 0;

    printf("Enter an integer: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Enter an integer.\n");
        return 1;
    }

    /* This program treats negative numbers as not palindromes. */
    if (number < 0) {
        printf("%d is not a palindrome.\n", number);
        return 0;
    }

    remaining = number;

    while (remaining > 0) {
        digit = remaining % 10;
        reversed = reversed * 10 + digit;
        remaining = remaining / 10;
    }

    if (reversed == number) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}