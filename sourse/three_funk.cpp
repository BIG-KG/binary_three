#include <stdio.h>
#include <stdlib.h>

#include "..\\headers\tree_types.h"
#include "..\\headers\tree_const.h"
#include "..\\headers\tree_funck.h"


node_t *make_element(tree_t *currTree)
{
    printf("make node\n");
    node_t *tmpPntr_ = (node_t *)calloc(1, sizeof(node_t));

    if (tmpPntr_ == NULL)
    {
        #ifdef CONSOLE_DEBUG
            printf("No RAM space to add new tree element\n");
        #endif

        return NULL;
    }

    return tmpPntr_;
}


int printing_dump(node_t *node)
{
    printf("{");

    if (node->left  != NULL) printing_dump(node->left );
    else                     printf("*");

    printf("%s", node->data);

    if (node->right != NULL) printing_dump(node->right);
    else                     printf("*");

    printf("}");

    return 0;
}

int delete_tree(node_t *deleatingNode)
{
    if (!deleatingNode) return 0;

    if(deleatingNode->left != NULL)
    {
        delete_tree(deleatingNode->left);
    }

    if(deleatingNode->right != NULL)
    {
        delete_tree(deleatingNode->right);
    }

    free(deleatingNode);

    return 0;
}
