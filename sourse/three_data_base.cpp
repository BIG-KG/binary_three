#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "..\\headers\\three_funck.h"
#include "..\\headers\\three_data_base_funk.h"

#include "..\\stack\stack_funk.h"
#include "..\\stack\errors.h"
#include "..\\stack\const.h"

#include "..\\onegin\onegin.h"
//#define  CONSOL_DEBAG


enum {
    NO_NODE_START = 1,
    NO_NODE_END,
    NO_NODE_DATA,
    STRING_END
};

static node_t *make_three (FILE *loading_file, int *errorStream);

static node_t *make_three (FILE *loading_file, int *errorStream)
{
    fscanf (loading_file, "%*[ ]");
    errorCheck (loading_file, errorStream, NO_NODE_START, '{' );

    node_t *newNode = make_element ();
    fscanf (loading_file, "%*[^\']");
    errorCheck (loading_file, errorStream, NO_NODE_DATA,  '\'');
    fscanf (loading_file, "%[^\']", newNode->data);
    errorCheck (loading_file, errorStream, NO_NODE_DATA,  '\'');



    fscanf (loading_file, "%*[ ]");

    char startElementget = fgetc(loading_file);
    if      (startElementget == '*')
    {
        newNode->left = NULL;
    }
    else if (startElementget == '{')
    {
        ungetc (startElementget, loading_file)                ;
        newNode->left = make_three (loading_file, errorStream);
    }
    else
    {
        ungetc (startElementget, loading_file)                    ;
        errorCheck (loading_file, errorStream, NO_NODE_START, '{');
    }

    if (*errorStream != 0) return NULL;



    fscanf(loading_file, "%*[ ]");

         startElementget = fgetc(loading_file);
    if      (startElementget == '*')
    {
        newNode->right = NULL;
    }
    else if (startElementget == '{')
    {
        ungetc (startElementget, loading_file)                 ;
        newNode->right = make_three (loading_file, errorStream);
    }
    else
    {
        ungetc (startElementget, loading_file)                    ;
        errorCheck (loading_file, errorStream, NO_NODE_START, '{');
    }

    if (*errorStream != 0) return NULL;



    fscanf(loading_file, "%*[ ]");
    errorCheck (loading_file, errorStream, NO_NODE_START, '}');


    return newNode;
}


node_t *load_three (char *loadingFileName, int *errorStream)
{

    FILE *loadingFile = fopen(loadingFileName, "r");
    int innrErrStrng = 0                                          ;


    #ifdef   CONSOLE_DEBUG_MY
        printf("Start_making_three\n");
    #endif /*CONSOLE_DEBUG_MY*/


    node_t *threeStartNode = make_three (loadingFile, &innrErrStrng);
    if (errorStream)   *errorStream = innrErrStrng;

    if (innrErrStrng)  return NULL                ;

    #ifdef   CONSOLE_DEBUG_MY
        printf("End_making_three\n");
    #endif /*CONSOLE_DEBUG_MY*/

    return  threeStartNode;
}




