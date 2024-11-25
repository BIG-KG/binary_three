#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers\\tree_funck.h"
#include "headers\\akinator.h"
#include "headers\tree_data_base_funk.h"


int main()
{   
    //__________________________________________________________
    //LOAD
    int errors = 0;
    tree_t test_load_three = {};
    printf("start load\n");
    load_tree("test_save.txt", &test_load_three, &errors);
    printf("endload errors = %d\n", errors);

    // for (int i = 0; i < 1; i ++)
    // {
    //     find_word(&test_load_three);

    // }

    // printf("asdasd\n");
    // add_before(&test_load_three);
    // printf("dvcd\n");

    // save_tree (&test_load_three, "test_save.txt");

    generate_png (&test_load_three, 0);

    delete_tree (test_load_three.treeStart);
    
    return 0;
}
