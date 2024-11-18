#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <strings.h>      


#include "..\\headers\\tree_funck.h"
#include "..\\headers\\akinator.h"
#include "..\\headers\\colors.h"
#include "..\\headers\\errors.h"

#include "..\stack\stack_funk.h"
#include "..\stack\errors.h"
#include "..\stack\const.h"



static int yes_no_scan(tree_t *currTree, node_t *currNode, char *const RightWord);


void find_word (tree_t *currTree)
{   
    char answer[STRING_DATA_SIZE] = "";
    node_t *currNode = currTree->treeStart;

    while(  (currNode->left != NULL) && (currNode->right != NULL)  )
    {

        printf("\n%s%s%s\n", YELLOW, currNode->data, RESET);

        scanf("%s", answer);

        if(strcasecmp(answer, "yes") == 0) currNode = currNode->right;

        else                           currNode = currNode->left ;
    }

    printf("%s%s%s\n", YELLOW, currNode->data, RESET );
    printf("%sIs this your word?%s\n", YELLOW, RESET);
    scanf("%s", answer)         ;

    if(strcasecmp(answer, "yes") == 0) return;

    else                           add_question (currNode, currTree);

    return;
}

node_t *add_question (node_t *currNode, tree_t *currTree)
{
    char    rAns[STRING_DATA_SIZE] = ""; // FIXED hardcoded size EVIL
    char    qush[STRING_DATA_SIZE] = "";

    printf ("%sWhat word did you guess?%s\n", YELLOW, RESET);
    scanf("%*[\n]%[^\n]", rAns);

    printf ("%sHow is the hidden word different from %s?%s\n", YELLOW, currNode->data, RESET);
    scanf("%*[\n]%[^\n]", qush);

    if ( yes_no_scan(currTree, currNode, rAns) ) return NULL;

    strcpy (currNode->data, qush);
   
    return currNode;
}

static int yes_no_scan(tree_t *currTree, node_t *currNode, char *const RightWord)
{
    node_t *r_node   = make_element (currTree);
    node_t *l_node   = make_element (currTree);
    if ( !r_node || !l_node )
    {
        return NO_RAM_MEM;
    }

    currNode->right = r_node;
    currNode->left  = l_node;

    char    tmpr[STRING_DATA_SIZE] = "";

    printf ("%sIf I ask this question to the word you asked, will the answer be YES?%s\n", YELLOW, RESET);
    scanf("%*[\n]%[^\n]", tmpr); // FIXED function to scan yes or no

    if ( strcasecmp(tmpr, "yes") == 0)
    {
        strcpy (r_node->data, RightWord);
        strcpy (l_node->data, currNode->data);
    }

    else
    {
        strcpy (l_node->data, RightWord);
        strcpy (r_node->data, currNode->data);
    }

    return 0;    
}


node_t *finde_by_name(tree_t *searchingTree, char * const searchingWord)
{
    int64_t way_stack = stack_ctor();
    int     deep = 0;

    finde_by_name_rec(searchingTree->treeStart, searchingWord, way_stack, &deep);
    node_way_t returningWay = {};
    returningWay.depth = deep;
    returningWay.way = (int *) calloc(sizeof(int), deep);

    for (int i = 0, i < deep, i ++)
    {
        returningWay.way[i] = pop(way_stack);
    }

    return returningWay;
}

node_t *finde_by_name_rec(node_t* startNode, char * const searchingWord, int64_t way_stack, int *deep)
{
    if (!startNode->left || !startNode->right)
    {
        if( !strcasecmp(searchingWord, startNode->data)) return startNode;
        else                                             return NULL;
    }

    node_t *tmpPtr = finde_by_name(startNode->right, searchingWord);
    if (tmpPtr) 
    {   
        push(way_stack, RIGHT);
        *deep ++;
        return tmpPtr;
    }


            tmpPtr = finde_by_name(startNode->left,  searchingWord);
    if (tmpPtr) 
    {   
        push(way_stack, LEFT );
        *deep ++;
        return tmpPtr;
    }

    return NULL;

} 

// int akintor()
// {
//     int mode = 0;

//     while (mode != EXIT)
//     {
//         mode = aki_interface();

//         switch (mode)
//         {
//         case    LOAD_tree:
//             /* code */
//             break;

//         default:
//             break;
//         }

//     }

    

// }
