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


static node_t *finde_by_name_rec (node_t* startNode, char * const searchingWord, int64_t way_stack, int *deep);
static int right_left_scan   (tree_t *currTree, node_t *currNode, char *const RightWord);

void find_word (tree_t *currTree)
{   
    char answer[STRING_DATA_SIZE] = "";
    node_t *currNode              = currTree->treeStart;
    int userAns                   = 0;

    while(  (currNode->left != NULL) && (currNode->right != NULL)  )
    {

        printf("\n%s%s?%s\n", YELLOW, currNode->data, RESET);
        userAns = yes_no_scan();

        if( userAns == 1) currNode = currNode->right;

        else              currNode = currNode->left ;
    }

    printf ("%s%s%s\n", YELLOW, currNode->data, RESET );
    printf ("%sIs this your word?%s\n", YELLOW, RESET );
    userAns = yes_no_scan();

    if( userAns == 1 ) return;

    else               add_question (currNode, currTree, WORD);

    return;
}

node_t *add_question (node_t *currNode, tree_t *currTree, int addingType)
{
    char    rAns[STRING_DATA_SIZE] = ""; // FIXED hardcoded size EVIL
    char    qush[STRING_DATA_SIZE] = "";


    if (addingType == WORD)
    {
        printf ("%sWhat word did you guess?%s\n", YELLOW, RESET);
    }

    if (addingType == QUESH)
    {
        printf ("%sWhat word to add to the created element?%s\n", YELLOW, RESET);
    }


    scanf("%*[\n]%[^\n]", rAns);

    if (addingType == WORD)
    {
        printf ("%sHow is the hidden word different from %s?%s\n", YELLOW, currNode->data, RESET);
    }
    if (addingType == QUESH)
    {
        printf ("What is the dividing question?");
    }

    scanf("%*[\n]%[^\n]", qush);

    if ( right_left_scan (currTree, currNode, rAns) ) return NULL;

    strcpy (currNode->data, qush);
   
    return currNode;
}

static int right_left_scan (tree_t *currTree, node_t *currNode, char *const RightWord)
{
    node_t *r_node = make_element (currTree);
    node_t *l_node = make_element (currTree);
    if ( !r_node || !l_node )
    {
        return NO_RAM_MEM;
    }

    currNode->right = r_node;
    currNode->left  = l_node;

    char    tmpr[STRING_DATA_SIZE] = "";

    printf ("%sIf I ask this question to the word you asked, will the answer be YES?%s\n", YELLOW, RESET);
    int right_qsh = yes_no_scan();

    if ( right_qsh == 1 )
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

int yes_no_scan()
{
    char tmpr[STRING_DATA_SIZE] = {};
    char skip[10] = {};
    scanf ("%s", tmpr);
    int ans = !strcasecmp (tmpr, "yes");
    //printf("_%s_  _%s_  ans = %d", skip, tmpr, ans);
    return ( ans );
}

node_way_t finde_by_name (char * const searchingWord, tree_t *searchingTree)
{
    int64_t way_stack = stack_ctor();
    int     deep = 0;

    finde_by_name_rec (searchingTree->treeStart, searchingWord, way_stack, &deep);
    node_way_t returningWay = {};
    returningWay.depth = deep;
    returningWay.way = (int *) calloc (sizeof(int), deep);

    for (int i = 0; i < deep; i ++)
    {
        returningWay.way[i] = pop (way_stack);
    }

    return returningWay;
}

static node_t *finde_by_name_rec (node_t* startNode, char * const searchingWord, int64_t way_stack, int *deep)
{
    //printf("_%s_   _%s_   %d    L = %p       R = %p  \n", startNode->data, searchingWord, strcasecmp(searchingWord, startNode->data), startNode->left, startNode->right);
    
    if ( !startNode->left || !startNode->right )
    {
        if( strcasecmp (searchingWord, startNode->data) == 0) 
        {   
             return startNode; 
        }
        else return NULL;
    }

    node_t *tmpPtr = finde_by_name_rec (startNode->right, searchingWord, way_stack, deep);
    if (tmpPtr != NULL) 
    {   
        push (way_stack, RIGHT);
        *deep = *deep + 1;
        return tmpPtr;
    }


            tmpPtr = finde_by_name_rec (startNode->left,  searchingWord, way_stack, deep);
    if (tmpPtr != NULL) 
    {   
        push (way_stack, LEFT );
        *deep = *deep + 1;
        return tmpPtr;
    }

    return NULL;

} 


int give_definition(char * const name, tree_t *currTree)
{
    node_way_t searching_way = finde_by_name(name, currTree);
    node_t    *currNode      = currTree->treeStart;

    if(searching_way.depth == 0)
    {
        printf("No such data\n");
        return 1;
    }
    
    printf("%s%s%s\n", YELLOW, name, RESET);

    for(int i = 0; i < searching_way.depth; i ++)
    {
        if(searching_way.way[i] == 1)
        {
            printf("%s: YES\n", currNode->data);
            currNode = currNode->right;
        }
        else
        {
            printf("%s: NO\n",  currNode->data);
            currNode = currNode->left;
        }

    }

    return 0;
}

int add_before(tree_t *currTree)
{
    printf("add_before\n");
    node_t *currNode     = currTree->treeStart;
    node_t *prevNode     = NULL;
    int     deepCounter  = 0;
    bool    userAns      = 0;

    printf("startsrch\n");

    while(currNode->left != NULL && currNode->right != NULL)
    {
        printf("%sadd before this:\n\t%s %s", YELLOW, currNode->data, RESET);

        if (yes_no_scan() == 1)
        {
            if (deepCounter > 0) add_question(prevNode, currTree, QUESH);
        
            else addStart(currTree);

            return 0;
        }
        else
        {
            printf("%sWright \"YES\" to move to right branch, \"NO\" to left\n%s", YELLOW, RESET);
            if ( (userAns = yes_no_scan()) == 1 )
            {
                prevNode = currNode;
                currNode = currNode->right;
                deepCounter++;
                continue;
            }
            else if( (userAns = yes_no_scan()) == 0 )
            {
                prevNode = currNode;
                currNode = currNode->right;
                deepCounter++;
                continue;

            }

            else
            {
                assert(0);
            }
        }
        
    }

    printf("You have reached the last branch: \"%s\", add a question before it?", currNode->data);
    if( yes_no_scan() == 1 )
    {
        add_question(prevNode, currTree, QUESH);
    }

    return 0;
}

int addStart(tree_t *currTree)
{
    char    rAns[STRING_DATA_SIZE] = ""; // FIXED hardcoded size EVIL
    char    qush[STRING_DATA_SIZE] = "";


    printf ("%sWhat word to add to the created element?%s\n", YELLOW, RESET);

    scanf("%*[\n]%[^\n]", rAns);

    printf ("%sWhat word to add to the created element?%s\n", YELLOW, RESET);

    printf ("What is the dividing question?");

    scanf("%*[\n]%[^\n]", qush);

    node_t * newStart = make_element(currTree);
    strcpy(newStart->data, qush);

    if ( right_left_scanStart (currTree, newStart, rAns) ) return -1;
   
    return 0;
}

int right_left_scanStart(tree_t *currTree, node_t *newStart, char *rAns)
{

    //ADD CHECKING
    node_t *q_node = make_element (currTree);
    strcpy (q_node->data, rAns);

    printf ("%sIf I ask this question to the word you asked, will the answer be YES?%s\n", YELLOW, RESET);
    int right_qsh = yes_no_scan();

    if ( right_qsh == 1 )
    {
        newStart->right = q_node;
        newStart->left  = currTree->treeStart; 
    }

    else
    {
        newStart->right = currTree->treeStart;
        newStart->left  = q_node; 
    }

    currTree->treeStart = newStart;

    return 0;
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
