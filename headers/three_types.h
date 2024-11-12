#ifndef THREE_TYPES
#define THREE_TYPES

#include <stdint.h>
typedef char elem_t;

struct node_t
{
    elem_t data[64] = "";
    node_t *right = NULL;
    node_t *left  = NULL;

};

#endif /*THREE_TYPES*/
