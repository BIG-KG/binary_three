#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "..\\headers\\three_funck.h"
#include "..\\headers\\three_data_base_funk.h"

#include "..\\stack\stack_funk.h"
#include "..\\stack\errors.h"
#include "..\\stack\const.h"

#include "..\\onegin\onegin.h"
#define  CONSOL_DEBAG


enum {
    NO_NODE_START = 1,
    NO_NODE_END,
    NO_NODE_DATA,
    STRING_END
};

static node_t *make_three (FILE *loading_file, int *errorStream)
{
    node_t *newNode         = make_element ();
    char    startElementget = 0;

    fscanf (loading_file, "%*[ ]");
    errorCheck (loading_file, errorStream, NO_NODE_START, '{' );

    fscanf (loading_file, "%*[^\']");
    errorCheck (loading_file, errorStream, NO_NODE_DATA,  '\'');
    fscanf (loading_file, "%[^\']", newNode->data);
    printf("%s\n", newNode->data);
    errorCheck (loading_file, errorStream, NO_NODE_DATA,  '\'');
    


    make_node(loading_file, newNode->left,  errorStream);

    make_node(loading_file, newNode->right, errorStream);



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



int save_three (node_t *startingNode, FILE *savingFile)
{
    fprintf(savingFile, "{ ");
    fprintf(savingFile, " \'%s\' ", startingNode->data);

    if (startingNode->left ) save_three(startingNode->left,  savingFile);
    else                     fprintf(savingFile, " * ");

    if (startingNode->right) save_three(startingNode->right, savingFile);
    else                     fprintf(savingFile, " * ");

    fprintf(savingFile, "}");

    return 0;
}