#ifndef THREE_TYPES
#define THREE_TYPES

#include <stdint.h>
typedef char elem_t;

struct node_t
{
    elem_t  data[64] = "";//hardcode
    node_t *right    = NULL; // alternate this on realloc
    node_t *left     = NULL;

};

struct three_t
{
    void   *occupiedMemStart = NULL; // remove
    node_t *threeStart       = NULL;
    int     capacity         = 0;
    int     currentElement   = 0;

};


#endif /*THREE_TYPES*/
