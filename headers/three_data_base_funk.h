#ifndef  THREE_DATA_BASE_F
#define  THREE_DATA_BASE_F

 #include "three_types.h"


// #define skip(stringArr, currentWord, errorStream)                                   \
//     while ( isspace(stringArr[*currentWord])  &&                                    \
//             stringArr[*currentWord] != '\0'       )           *currentWord += 1;    \
//     if (stringArr[*currentWord] == '\0')                                            \
//     {                                                                               \
//         *errorStream = STRING_END;                                                  \
//         return STRING_END;                                                          \
//     }                                                                               \
//                                                                                     \
//     return 0;                                                                       \


#ifdef CONSOL_DEBAG
    #define errorCheck (loading_file, errorStream, ERROR_NUM, symb)                      \
    if (fgetc (loading_file) != symb)                                                    \
    {                                                                                   \
        printf("ERROR: syntax error no node start: symb  curr word %c", symb);          \
        *errorStream = ERROR_NUM;                                                       \
        return NULL;                                                                    \
    }
#else
    #define errorCheck(loading_file, errorStream, ERROR_NUM, symb)                     \
    if (fgetc (loading_file) != symb )                                                   \
    {                                                                                   \
        *errorStream = ERROR_NUM;                                                       \
        return NULL;                                                                    \
    }
#endif

three_t       *make_three (FILE *loading_file, int *errorStream);
three_t        *load_three (char *loadingFileName, int *errorStream);
int            save_three (three_t *savigThee, char * const fileName);
int            save_node  (node_t *startingNode, FILE *savingFile);
node_t        *make_node  (FILE *loading_file, int *errorStream, three_t *currThree);
node_t        *scan_node  (FILE* loading_file, int *errorStream, three_t *currThree);



#endif /*THREE_DATA_BASE_F*/
