#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Private macro ----------------------------- */
#define BUFFER_SIZE 100
#define STRING_SIZE ( BUFFER_SIZE - 1 )

/* Exported functions declaration ------------ */

/**
 * @brief The function for reading string from standard input.
 *
 * If the string is correctly read, the real length of the string is written back to the "len" parameter.
 * All remaining strings (another lines) to be flushed.
 * @param inOutString Pointer to a variable where the string should be stored.
 * @param len IN: The max length of the input array OUT: the real length of already read text.
 * @return Status of the reading process
 */
IO_RES IO_getLine(char * const inOutString, int * const len){
    if ((inOutString == NULL) || (len == NULL) || ( *len == 0)){
        return  IO_ARGS_ERROR;
    }
    if (fgets(inOutString, *len, stdin) == NULL){
        return IO_STREAM_ERROR;
    }else{
        *len = strlen(inOutString);
    }
    fflush(stdin);
    return IO_OK;
}

/**
 * @brief The function returns one character read from the input.
 * @param value The the character read from the input.
 * @return Status of the reading process
 */
IO_RES IO_getChar(char * const value){
    if (value == NULL){
        return IO_ARGS_ERROR;
    }
    char string[BUFFER_SIZE];
    int len = BUFFER_SIZE;

    if (IO_getLine(string, &len) == IO_OK){
        *value = * string;
        return IO_OK;
    }
    return IO_STREAM_ERROR;
}


/**
 * @brief Function read one line from the standard input and trasfer it into the integer value.
 * @param value The read value
 * @return Status of the reading process
 */
IO_RES IO_getInt(int * const value){
    char string[BUFFER_SIZE];
    int len = BUFFER_SIZE;

    if (value == NULL){
        return IO_ARGS_ERROR;
    }
    if (IO_getLine(string, &len) == IO_OK){
        long converted = strtol(string, NULL, 10);
        if ((converted == 0)&&(*string!='0')){
            // TODO: Implement better error corrections
            return IO_STREAM_ERROR;
        }
        *value = converted;
        return IO_OK;
    }
    return IO_STREAM_ERROR;
}
