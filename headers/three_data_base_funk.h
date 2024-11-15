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

#define make_node(loading_file, saveTo, errorStream)            \
    fscanf (loading_file, "%*[ ]");                             \
                                                                \
         startElementget = fgetc(loading_file);                 \
    if      (startElementget == '*')                            \
    {                                                           \
        saveTo = NULL;                                          \
    }                                                           \
    else if (startElementget == '{')                            \
    {                                                           \
        ungetc (startElementget, loading_file);                 \
        saveTo = make_three (loading_file, errorStream);}       \
    else                                                        \
    {                                                           \
        ungetc (startElementget, loading_file)                    ; \
        errorCheck (loading_file, errorStream, NO_NODE_START, '{'); \
    }                                                           \
                                                                \
    if (*errorStream != 0) return NULL;                         \

int            save_three (node_t *startingNode, FILE *savingFile);
static node_t *make_three (FILE *loading_file, int *errorStream);
node_t        *load_three (char *loadingFileName, int *errorStream);



#endif /*THREE_DATA_BASE_F*/
