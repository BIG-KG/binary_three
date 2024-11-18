#include <stdio.h>
#include <stdlib.h>

#include "..\\headers\\three_types.h"
#include "..\\headers\\three_const.h"


node_t *make_element(three_t *currThree)
{
    
    if (!currThree->occupiedMemStart) 
    {
        currThree->occupiedMemStart = calloc (DATA_ARRAY_BASE_SIZE, sizeof(node_t));
    }
    node_t **dataArray      = (node_t **)&currThree->occupiedMemStart;

    int    *capacity       = &currThree->capacity;
    int    *currentElement = &currThree->currentElement;

    if (*capacity == *currentElement )
    {
        int newCapacity  = *capacity * STEP_ADDING_SIZE;

        node_t *tmpPntr_ = (node_t *) realloc(*dataArray, newCapacity * sizeof(node_t));

        if (!tmpPntr_)
        {
            #ifdef CONSOLE_DEBAG
                printf("ERROR: not enough memory to expand array.\n");
            #endif

            return NULL;
        }

        *capacity  = newCapacity;
        *dataArray = tmpPntr_;
    }

    return *dataArray + (*currentElement++);
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

int delete_three(node_t *start_three)
{
    free(start_three);
    return 0;
}
