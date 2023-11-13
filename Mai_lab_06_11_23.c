#define _CRT_SECURE_NO_WARNINGS
/*

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


typedef enum {
    WaitingNumber,
    ReadingNumber,
    BadNumber
} State;


bool isDelimiter(char symbol) {
    // return isdigit(symbol) && (symbol - '0') < 8;
    return symbol == ' ' || symbol == '\n' || symbol == '\t';
}


int main() {
    State state = WaitingNumber;

    char current;
    long long number = 0;
    long long count = 0;

    while (scanf("%c", &current) != EOF) {
        switch (state) {
        case ReadingNumber: {
            if (isdigit(current)) {
                int currentNumber = current - '0';
                if (currentNumber >= 8) {
                    state = BadNumber;
                    number = 0;
                    break;
                }

                number *= 8;
                number += currentNumber;
                state = ReadingNumber;

                if (number > 1000) {
                    state = BadNumber;
                    number = 0;
                    break;
                }
                break;
            }

            if (isDelimiter(current)) {
                if (10 <= number && number < 1000) {
                    count += 1;
                    number = 0;
                }
                state = WaitingNumber;
                break;
            }

            state = BadNumber;
            number = 0;

            break;
        }
        case BadNumber: {
            if (isDelimiter(current)) {
                state = WaitingNumber;
            }
            break;
        }
        case WaitingNumber: {
            if (isdigit(current)) {
                int currentNumber = current - '0';
                if (currentNumber >= 8) {
                    state = BadNumber;
                    number = 0;
                    break;
                }

                number = currentNumber;
                state = ReadingNumber;

                break;
            }
            state = BadNumber;
            break;
        }
        }
    }

    if (state == ReadingNumber) {
        if (10 <= number && number < 1000) {
            count += 1;
        }
    }

    printf("Количество восьмиричных чисел, находящихся в диапазоне от 10 до 1000: %lli\n", count);
}

*/