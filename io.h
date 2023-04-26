#ifndef IO_H
#define IO_H

/* Exported types --------------------------------------*/

/**
 * @brief This enum represents the return state of each functions in this library.
 */
typedef enum{
    IO_OK,              /**< Result is OK*/
    IO_ARGS_ERROR,      /**< The input arguments are incorrect */
    IO_STREAM_ERROR     /**< Error during working with internal command stream (general error) */
} IO_RES;

/* Exported functions declaration ----------------------*/

IO_RES IO_getLine(char * const inOutString, int * const len);
IO_RES IO_getChar(char * const value);
IO_RES IO_getInt(int * const value);

#endif // IO_H