 #include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);
    char temp;
    int i;
    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to concatenate two strings
void concatenate(char str1[], char str2[]) {
    strcat(str1, str2);
}

// Function to check if a string is palindrome
int isPalindrome(char str[]) {
    int length = strlen(str);
    int i;
    for (i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to copy a string
void copyString(char dest[], char src[]) {
    strcpy(dest, src);
}

// Function to find length of a string
int lengthOfString(char str[]) {
    return strlen(str);
}

// Function to find frequency of a character in a string
int frequencyOfChar(char str[], char ch) {
    int count = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

// Function to count vowels and consonants in a string
void countVowelsConsonants(char str[], int* vowels, int* consonants) {
    *vowels = 0;
    *consonants = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            continue;
        }
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
    }
}

// Function to count blank spaces and digits in a string
void countBlankDigits(char str[], int* blankSpaces, int* digits) {
    *blankSpaces = 0;
    *digits = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            (*blankSpaces)++;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            (*digits)++;
        }
    }
}

int main() {
	char dest[100];
    char input[100];
    int choice;
    char ch;
    int vowels, consonants, blankSpaces, digits;
    char continueChoice;
    char str2[100];

    do {
        printf("\nString Operations Menu:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenation\n");
        printf("3. Palindrome check\n");
        printf("4. Copy a string\n");
        printf("5. Length of the string\n");
        printf("6. Frequency of character\n");
        printf("7. Vowels and consonants count\n");
        printf("8. Blank spaces and digits count\n");
        printf("9. Exit\n");

        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
        getchar();

        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        switch (choice) {
            case 1:
                reverseString(input);
                printf("Reversed string: %s\n", input);
                break;
            case 2:
                printf("Enter another string to concatenate: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                concatenate(input, str2);
                printf("Concatenated string: %s\n", input);
                break;
            case 3:
                printf("Is palindrome: %s\n", isPalindrome(input) ? "Yes" : "No");
                break;

            case 4:
                
                copyString(dest, input);
                printf("Copied string: %s\n", dest);
                break;
            case 5:
                printf("Length of the string: %d\n", lengthOfString(input));
                break;
            case 6:
                
                printf("Enter a character to find frequency: ");
                scanf(" %c", &ch);
                printf("Frequency of '%c': %d\n", ch, frequencyOfChar(input, ch));
                break;
            case 7:
                countVowelsConsonants(input, &vowels, &consonants);
                printf("Vowels count: %d\n", vowels);
                printf("Consonants count: %d\n", consonants);
                break;
            case 8:
                countBlankDigits(input, &blankSpaces, &digits);
                printf("Blank spaces count: %d\n", blankSpaces);
                printf("Digits count: %d\n", digits);
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueChoice);
        while (continueChoice != 'y' && continueChoice != 'n') {
            printf("Invalid input. Please enter y or n: ");
            scanf(" %c", &continueChoice);
        }
    } while (continueChoice == 'y');

    return 0;
}
