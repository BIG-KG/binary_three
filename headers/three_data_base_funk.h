#ifndef  THREE_DATA_BASE_F
#define  THREE_DATA_BASE_F

// #define skip(stringArr, currentWord, errorString)                                   \
//     while ( isspace(stringArr[*currentWord])  &&                                    \
//             stringArr[*currentWord] != '\0'       )           *currentWord += 1;    \
//     if (stringArr[*currentWord] == '\0')                                            \
//     {                                                                               \
//         *errorString = STRING_END;                                                  \
//         return STRING_END;                                                          \
//     }                                                                               \
//                                                                                     \
//     return 0;                                                                       \


#ifdef CONSOL_DEBAG
    #define errorCheck(loading_file, errorString, ERROR_NUM, symb)                      \
    if (fgetc(loading_file) != symb)                                                    \
    {                                                                                   \
        printf("ERROR: syntax error no node start: symb  curr word %c", symb);          \
        *errorString = ERROR_NUM;                                                       \
        return NULL;                                                                    \
    }
#else
    #define errorCheck(loading_file, errorString, ERROR_NUM, symb);                     \
    if (fgetc(loading_file) != symb )                                                   \
    {                                                                                   \
        *errorString = ERROR_NUM;                                                       \
        return NULL;                                                                    \
    }
#endif

#endif /*THREE_DATA_BASE_F*/
