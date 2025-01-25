# Text Line Processor Utility

## Description
The **Text Line Processor Utility** is a simple command-line program written in C. It allows users to process a string with various operations such as counting words, reversing the string, and printing words with their lengths.

## Features
- **Help (`-h`)**: Displays usage instructions.
- **Count Words (`-c`)**: Counts the number of words in the input string.
- **Reverse String (`-r`)**: Reverses the characters in the input string.
- **Print Words (`-w`)**: Prints individual words and their lengths from the input string.

## Compilation
To compile the program, navigate to the project directory and use the provided `Makefile`:
```bash
cd /Users/faisalfarooq/Desktop/TextLineProcessor
make

faisalfarooq@MacBookPro TextLineProcessor % make

gcc -Wall -Wextra -std=c11 -o stringfun main.c
faisalfarooq@MacBookPro TextLineProcessor % ls

Makefile        README.md       main.c          stringfun
faisalfarooq@MacBookPro TextLineProcessor % ./stringfun -h

Usage: stringfun -[h|c|r|w] "sample string"
faisalfarooq@MacBookPro TextLineProcessor % ./stringfun -c "This is a test string"

Word Count: 5
faisalfarooq@MacBookPro TextLineProcessor % ./stringfun -r "Reverse this string"

Reversed String: ...............................gnirts siht esreveR
faisalfarooq@MacBookPro TextLineProcessor % ./stringfun -w "Print words and lengths"

Word Print
----------
1. Print (5)
2. words (5)
3. and (3)
4. lengths (7)
faisalfarooq@MacBookPro TextLineProcessor %  
