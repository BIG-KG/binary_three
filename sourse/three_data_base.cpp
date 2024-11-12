#include <stdio.h>
#include <stdio.h>
#include <string.h>


#include "..\\headers\\three_funck.h"
#include "..\\headers\\three_data_base_funk.h"

#include "..\\stack\stack_funk.h"
#include "..\\stack\errors.h"
#include "..\\stack\const.h"

#include "..\\onegin\onegin.h"


enum {
    SYNTAX_ERROR = 1
};


node_t *make_three (string_start_end ** stringArr, int *currentWord)
{

    if (*StringArr[*currentWord++].startl != '{')
    {
        #ifdef   CONSOL_DEBAG
            printf("ERROR: syntax error no node start : \"{\"\n");
        #endif /*CONSOL_DEBAG*/

        return NULL;
    }

    node_t newNode = make_element();

    strcpy(newNode.data, StringArr[*currentWord++].startl + 1);
    newNode.data[  strlen(newNode.data) - 1  ] = '\0'         ;

    *currentWord ++;
    if (StringArr[*currentWord] == '*') newNode.left  = NULL                              ;
    else                                newNode.left  = make_three(stringArr, currentWord);

    *currentWord ++;
    if (StringArr[*currentWord] == '*') newNode.right = NULL                              ;
    else                                newNode.right = make_three(stringArr, currentWord);

    *currentWord ++;
    if (*StringArr[*currentWord].startl != '}')
    {
        #ifdef   CONSOL_DEBAG
            printf("ERROR: syntax error no node end : \"}\"\n");
        #endif /*CONSOL_DEBAG*/

        return NULL;
    }


    return newNode;
}

node_t *load_three (char *fileName)
{
    int commandsFile = open(argv[1], _O_BINARY | O_RDONLY );



}
