#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers\\tree_funck.h"
#include "headers\\akinator.h"
#include "headers\tree_data_base_funk.h"


int main()
{   
    // tree_t test_tree = {};

    // //printf("start\n");
    // node_t *start_node = make_element( &test_tree );
    // strcpy(start_node->data, "GOOOL");

    // for(int i = 0; i < 3; i ++)
    // {
    //     //printf("cicke = %d\n", i);
    //     find_word(&test_tree);
    //     //printf("errr = %d\n\n", i);
    // }

    // //printf("endcickle");
    // printing_dump(test_tree.treeStart);

    // save_tree(&test_tree, "test_save.txt");

    //__________________________________________________________
    //LOAD
    int errors = 0;
    tree_t test_load_three = {};
    printf("start load\n");
    load_tree("test_save.txt", &test_load_three, &errors);
    printf("endload errors = %d\n", errors);

    for (int i = 0; i < 1; i ++)
    {
        find_word(&test_load_three);
        generate_png (&test_load_three, 0);

    }

    save_tree (&test_load_three, "test_save.txt");

    generate_png (&test_load_three, 0);

    delete_tree (&test_load_three);
    
    return 0;
}
