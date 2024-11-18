#ifndef TREE_TYPES
#define TREE_TYPES

#include <stdint.h>
#include "tree_const.h"
typedef char elem_t;

struct node_t
{
    elem_t  data[STRING_DATA_SIZE] = "";//hardcode
    node_t *right                  = NULL; // alternate this on realloc
    node_t *left                   = NULL;

};

struct tree_t
{
    void   *occupiedMemStart = NULL; // remove
    node_t *treeStart       = NULL;
    int     capacity         = 0;
    int     currentElement   = 0;

};

struct node_way_t
{
    int  depth = 0;
    int *way   = NULL;

}

#endif /*TREE_TYPES*/
