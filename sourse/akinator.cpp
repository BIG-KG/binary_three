#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


#include "..\\headers\\tree_funck.h"
#include "..\\headers\\akinator.h"
#include "..\\headers\\colors.h"



void find_word (tree_t *currtree)
{
    char answer[32] = "";
    node_t *currNode = currtree->treeStart;

    while(  (currNode->left != NULL) && (currNode->right != NULL)  )
    {
        printf("\n%s%s%s\n", YELLOW, currNode->data, RESET);

        scanf("%s", answer);

        if(strcmp(answer, "yes") == 0) currNode = currNode->right;

        else                           currNode = currNode->left ;
    }

    printf("%s%s%s\n", YELLOW, currNode->data, RESET );
    printf("%sIs this your word?%s\n", YELLOW, RESET);
    scanf("%s", answer)         ;

    if(strcmp(answer, "yes") == 0) return;

    else                           add_question (currNode, currtree);

    return;

}

node_t *add_question (node_t *curr_node, tree_t *currtree)
{
    char    rAns[64] = ""; // hardcoded size EVIL
    char    qush[64] = "";
    char    tmpr[64] = "";
    node_t *r_node   = make_element (currtree);
    node_t *l_node   = make_element (currtree);

    if ( !r_node || !l_node )
    {
        return NULL;
    }

    printf ("What word did you guess?\n");
    scanf  ("%s", rAns);

    printf ("How is the hidden word different from %s?\n", curr_node->data);
    getchar();
    scanf("%[^\n]", qush);

    printf ("If I ask this question to the word you asked, will the answer be YES?\n");
    scanf  ("%s", tmpr); // function to scan yes or no

    if ( strcmp(tmpr, "yes") == 0)
    {
        strcpy (r_node->data, rAns)           ;
        strcpy (l_node->data, curr_node->data);
    }

    else
    {
        strcpy (l_node->data, rAns)           ;
        strcpy (r_node->data, curr_node->data);
    }  

    strcpy (curr_node->data, qush);
    curr_node->right = r_node            ;
    curr_node->left  = l_node            ;

    return curr_node;
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
