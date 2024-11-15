#include <stdio.h>
#include <stdlib.h>

#include "headers\\three_funck.h"
#include "headers\\akinator.h"

int main()
{
    node_t *first  = make_element ();
    sprintf(first->data, "Football");

    for(int i = 0; i < 3; i ++)
    {
        find_word(first);
    }

    printing_dump(first);
}
