#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "..\\headers\\three_types.h"
#include "..\\headers\\three_funck.h"
#include "..\\headers\\three_data_base_funk.h"


#include "..\\onegin\onegin.h"
//#define  CONSOL_DEBAG


#define errorCheck(loading_file, errorStream, ERROR_NUM, symb);                     \
if (fgetc (loading_file) != symb )                                                   \
{                                                                                   \
    *errorStream = ERROR_NUM;                                                       \
    return NULL;                                                                    \
}

enum {
    NO_NODE_START = 1,
    NO_NODE_END,
    NO_NODE_DATA,
    STRING_END,
    UND_BEH
};



node_t *make_node (FILE *loading_file, int *errorStream, three_t *currThree)
{
    node_t *newNode         = make_element (currThree);
    char    startElementget = 0;

    fscanf (loading_file, "%*[ ]");
    errorCheck (loading_file, errorStream, NO_NODE_START, '{' );


    fscanf (loading_file, "%*[^']");
    errorCheck (loading_file, errorStream, NO_NODE_DATA,  '\'');
    fscanf (loading_file, "%[^']", newNode->data);
    //printf("%s\n", newNode->data);
    errorCheck (loading_file, errorStream, NO_NODE_DATA,  '\'');
    

    newNode->left  = scan_node(loading_file, errorStream, currThree);
    if (*errorStream) return NULL;

    newNode->right = scan_node(loading_file, errorStream, currThree);
    if (*errorStream) return NULL;


    fscanf(loading_file, "%*[ ]");
    errorCheck (loading_file, errorStream, NO_NODE_START, '}');


    return newNode;
}


three_t *load_three (char *loadingFileName, int *errorStream)
{

    FILE *loadingFile = fopen(loadingFileName, "r");
    int innrErrStrng  = 0;
    three_t *currThree = (three_t *)calloc(1, sizeof(three_t));                                          

    #ifdef   CONSOLE_DEBUG_MY
        printf("Start_making_three\n");
    #endif /*CONSOLE_DEBUG_MY*/


    node_t *threeStartNode = make_node (loadingFile, &innrErrStrng, currThree); // scan
    currThree->threeStart = threeStartNode;
    if (errorStream)   *errorStream = innrErrStrng;

    if (innrErrStrng)  return NULL                ;

    #ifdef   CONSOLE_DEBUG_MY
        printf("End_making_three\n");
    #endif /*CONSOLE_DEBUG_MY*/

    return  currThree;
}


int save_three (three_t *savigThee, char * const fileName)
{
    FILE *savingFile = fopen(fileName, "w");
    
    save_node(savigThee->threeStart, savingFile);

    fclose(savingFile);

    return 0;
}

int save_node (node_t *startingNode, FILE *savingFile)
{
    fprintf(savingFile, "{ ");
    fprintf(savingFile, " \'%s\' ", startingNode->data);

    if (startingNode->left ) save_node (startingNode->left,  savingFile);
    else                     fprintf (savingFile, " * ");

    if (startingNode->right) save_node (startingNode->right, savingFile);
    else                     fprintf (savingFile, " * ");

    fprintf(savingFile, "}");

    return 0;
}


node_t *scan_node (FILE* loading_file, int *errorStream, three_t *currThree)
{          
    fscanf (loading_file, "%*[ ]");                             
                                                                
    char startElementget = fgetc(loading_file);                 
    if      (startElementget == '*')                            
    {                                                           
        return NULL;                                          
    }                                                           
    else if (startElementget == '{')                            
    {                                                           
        ungetc (startElementget, loading_file);                 
        return make_node (loading_file, errorStream, currThree);}       
    else                                                        
    {                                                           
        ungetc (startElementget, loading_file)                    ; 
        errorCheck (loading_file, errorStream, NO_NODE_START, '{'); 
        return NULL;
    }                                                           

    *errorStream = UND_BEH;                                                           
    return NULL;                         
}