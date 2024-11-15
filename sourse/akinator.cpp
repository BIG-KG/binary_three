#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


#include "..\\headers\\three_funck.h"
#include "..\\headers\\akinator.h"



void find_word (node_t *node)

{
    char answer[32] = "";
    node_t *currNode = node;

    while(  (currNode->left != NULL) && (currNode->right != NULL)  )
    {
        printf("%s\n", currNode->data);

        scanf("%s", answer);

        if(strcmp(answer, "yes") == 0) currNode = currNode->right;

        else                           currNode = currNode->left ;
    }

    printf("%s\n", currNode->data);
    printf("Is this your word?\n");
    scanf("%s", answer)         ;

    if(strcmp(answer, "yes") == 0) return                 ;

    else                           add_question (currNode);

    return;

}

node_t *add_question (node_t *curr_node)
{
    char    rAns[64] = ""            ;
    char    qush[64] = ""            ;
    char    tmpr[64] = ""            ;
    node_t *r_node   = make_element();
    node_t *l_node   = make_element();

    if ( !r_node || !l_node )
    {
        return NULL;
    }

    printf ("What word did you guess?\n");
    scanf  ("%s", rAns);

    printf ("How is the hidden word different from ABA?\n");
    getchar();
    scanf("%[^\n]", qush);

    printf ("If I ask this question to the word you asked, will the answer be YES?\n");

    #ifdef   CONSOL_DEBAG_MY
        printf("111\n");
    #endif /*CONSOL_DEBAG_MY*/

    scanf  ("%s", tmpr);

    #ifdef   CONSOL_DEBAG_MY
        printf("222\n");
    #endif /*CONSOL_DEBAG_MY*/

    if ( strcmp(tmpr, "yes") == 0)
    {
        sprintf (r_node->data, "%s", rAns)           ;
        sprintf (l_node->data, "%s", curr_node->data);
    }

    else
    {
        sprintf (l_node->data, "%s", rAns)           ;
        sprintf (r_node->data, "%s", curr_node->data);
    }

    sprintf (curr_node->data, "%s", qush);
    curr_node->right = r_node            ;
    curr_node->left  = l_node            ;

    return curr_node;
}
