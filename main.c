#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SZ 50

// Function to process the input string
int setup_buff(char *buff, const char *user_str, int buff_size) {
    char *buff_ptr = buff;
    const char *user_ptr = user_str;
    int count = 0;

    while (*user_ptr != '\0') {
        if (count >= buff_size) {
            return -1; // Error: Input string too large
        }
        if (!isspace(*user_ptr)) {
            *buff_ptr++ = *user_ptr; // Copy non-whitespace character
            count++;
        } else if (buff_ptr != buff && *(buff_ptr - 1) != ' ') {
            *buff_ptr++ = ' '; // Replace multiple spaces/tabs with a single space
            count++;
        }
        user_ptr++;
    }

    // Remove trailing spaces
    if (buff_ptr != buff && *(buff_ptr - 1) == ' ') {
        buff_ptr--;
        count--;
    }

    // Fill remaining buffer with '.'
    while (count < buff_size) {
        *buff_ptr++ = '.';
        count++;
    }

    return buff_ptr - buff; // Return the length of the processed string
}

// Function to count words
int count_words(char *buff, int user_len) {
    int word_count = 0;
    int in_word = 0;

    for (int i = 0; i < user_len; i++) {
        if (buff[i] != ' ' && buff[i] != '.') {
            if (!in_word) {
                word_count++; // New word detected
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    return word_count;
}

// Function to reverse the string
void reverse_string(char *buff, int user_len) {
    char *start = buff;
    char *end = buff + user_len - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to print words and their lengths
void print_words(char *buff, int user_len) {
    char *ptr = buff;
    int word_index = 1;

    printf("Word Print\n----------\n");

    while (ptr < buff + user_len) {
        int len = 0;
        char *word_start = ptr;

        while (ptr < buff + user_len && *ptr != ' ' && *ptr != '.') {
            len++;
            ptr++;
        }

        if (len > 0) {
            printf("%d. %.*s (%d)\n", word_index++, len, word_start, len);
        }

        while (ptr < buff + user_len && (*ptr == ' ' || *ptr == '.')) {
            ptr++;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: stringfun -[h|c|r|w] \"sample string\"\n");
        return 1;
    }

    char *option = argv[1];
    char *user_str = argv[2];
    char buff[BUFFER_SZ];

    int user_len = setup_buff(buff, user_str, BUFFER_SZ);
    if (user_len < 0) {
        printf("Error: Input string is too large.\n");
        return 1;
    }

    if (strcmp(option, "-h") == 0) {
        printf("Usage: stringfun -[h|c|r|w] \"sample string\"\n");
    } else if (strcmp(option, "-c") == 0) {
        int word_count = count_words(buff, user_len);
        printf("Word Count: %d\n", word_count);
    } else if (strcmp(option, "-r") == 0) {
        reverse_string(buff, user_len);
        printf("Reversed String: %.*s\n", user_len, buff);
    } else if (strcmp(option, "-w") == 0) {
        print_words(buff, user_len);
    } else {
        printf("Invalid option. Use -h for help.\n");
        return 1;
    }

    return 0;
}

