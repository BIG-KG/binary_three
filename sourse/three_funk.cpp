#include <stdio.h>
#include <stdlib.h>

#include "..\\headers\tree_types.h"
#include "..\\headers\tree_const.h"
#include "..\\headers\tree_funck.h"


node_t *make_element(tree_t *currTree)
{
    
    if (!currTree->occupiedMemStart) 
    {
        currTree->occupiedMemStart = calloc (DATA_ARRAY_BASE_SIZE, sizeof(node_t));
        currTree->treeStart        = (node_t *)currTree->occupiedMemStart;
        currTree->capacity         = DATA_ARRAY_BASE_SIZE;
    }

    node_t **dataArray      = (node_t **)&currTree->occupiedMemStart;

    int     *capacity        = &currTree->capacity;
    int     *currentElement  = &currTree->currentElement;
    printf("new_node");

    if (*capacity == *currentElement )
    {
        printf("start realloc");
        int newCapacity  = *capacity * STEP_ADDING_SIZE;

        node_t *tmpPntr_ = (node_t *) realloc(*dataArray, newCapacity * sizeof(node_t));

        if (!tmpPntr_)
        {
            #ifdef CONSOLE_DEBAG
                printf("ERROR: not enough memory to expand array.\n");
            #endif

            return NULL;
        }

        for(int i = 0; i < currTree->capacity; i ++)
        {
            tmpPntr_[i].right += (tmpPntr_ - (node_t *)currTree->occupiedMemStart);
            tmpPntr_[i].left  += (tmpPntr_ - (node_t *)currTree->occupiedMemStart);
        }

        currTree->treeStart = tmpPntr_;
        *capacity  = newCapacity;

        //free(currTree->occupiedMemStart);
        currTree->occupiedMemStart = tmpPntr_;
    }
    *currentElement = *currentElement + 1;
    
    return *dataArray + (*currentElement - 1);
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

int delete_tree(tree_t *deleatingTree)
{
    free(deleatingTree->occupiedMemStart);
    return 0;
}
