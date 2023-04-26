#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>

bool readNumbers( int * a, int * b){

    printf("Please select the number A:\n");
    if (IO_getInt(a) != IO_OK){
        printf("Incorect input!\n");
        return  false;
    }
    printf("Please select the number B:\n");
    if (IO_getInt(b) != IO_OK){
        printf("Incorect input!\n");
        return false;
    }
    return true;
}


bool Calculator_addFunction(){
    int numberA;
    int numberB;
    if (readNumbers(&numberA, &numberB) == false)
        return false;
    printf("%i + %i = %i\n", numberA, numberB, numberA+numberB);
    return true;
}

bool Calculator_subFunction(){
    int numberA;
    int numberB;
    if (readNumbers(&numberA, &numberB) == false)
        return false;
    printf("%i - %i = %i\n", numberA, numberB, numberA-numberB);
    return true;
}

bool Calculator_mulFunction(){
    int numberA;
    int numberB;
    if (readNumbers(&numberA, &numberB) == false)
        return false;
    printf("%i - %i = %i\n", numberA, numberB, numberA*numberB);
    return true;
}
bool Calculator_divFunction(){
    int numberA;
    int numberB;
    if (readNumbers(&numberA, &numberB) == false)
        return false;
    if (numberB == 0){
        printf("Error: divided by zero!\n");
        return false;
    }
    printf("%i / %i = %i\n", numberA, numberB, numberA/numberB);
    return true;
}