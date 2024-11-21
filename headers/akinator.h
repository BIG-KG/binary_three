#ifndef AKINATOR
#define AKINATOR


enum mode{
    LOAD_TREE = 1,
    SAVE_TREE,
    FIND_WORD,
    EXIT
};

node_t     *add_question      (node_t *curr_node, tree_t *currTree);
void        find_word         (tree_t *node);
node_way_t  finde_by_name     (char * const searchingWord, tree_t *searchingTree);
int         give_definition   (char * const name, tree_t *searchingTree);
int         yes_no_scan       ();


#endif /*AKINATOR*/
