#include <stdio.h>
#include <stdlib.h>

#include <C:\MIPT\bit_three\headers\three_types.h>
#include <C:\MIPT\bit_three\headers\three_const.h>


node_t *make_element(void)
{
    static node_t *dataArray      = (node_t *)calloc (  DATA_ARRAY_BASE_SIZE, sizeof(node_t)  );
    static int     capacity       = DATA_ARRAY_BASE_SIZE;
    static int     currentElement = 0;

    if ( capacity == currentElement )
    {
        int newCapacity  = capacity * STEP_ADDING_SIZE;

        node_t *tmpPntr_ = (node_t *) realloc(dataArray, newCapacity * sizeof(node_t));

        if (!tmpPntr_)
        {
            #ifdef CONSOLE_DEBAG
                printf("ERROR: not enough memory to expand array.\n");
            #endif

            return NULL;
        }

        capacity  = newCapacity;
        dataArray = tmpPntr_;
    }

    return dataArray + (currentElement++);
}

int printing_dump(node_t *node)
{
    printf("{");

    if (node->left  != NULL) printing_dump(node->left );
    else                     printf("{}");

    printf("%d", node->data);

    if (node->right != NULL) printing_dump(node->right);
    else                     printf("{}");

    printf("}");

    return 0;
}