#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "io.h"
#include "calculator.h"


void printHelp(){
    printf("**************************************\n");
    printf("| Possible options:                  |\n"
           "|   a - addition                     |\n"
           "|   s - subtraction                  |\n"
           "|   m - multiplication               |\n"
           "|   d - division                     |\n"
           "|   h - print this help              |\n"
           "|   q - quit application             |\n"
           "**************************************\n");
}

int main() {
    char readedChar;

    printHelp();
    printf("Select the opration: ");
    while(IO_getChar(&readedChar) == IO_OK){
        switch (readedChar) {
            case 'a': case 'A':
                Calculator_addFunction(); break;
            case 's': case 'S':
                Calculator_subFunction(); break;
            case 'm': case 'M':
                Calculator_mulFunction(); break;
            case 'd': case 'D':
                Calculator_divFunction();
                break;
            case 'h': case 'H': printHelp(); break;
            case 'q': case 'Q': return 0;
            default:
                if (isprint(readedChar)){
                    printf("Unknown choice: %c\n", readedChar);
                }else{
                    printf("Unknown choice: %d\n", readedChar);
                }
        }
        printf("Select the opration: ");
    }

    return 0;
}
