#ifndef AKINATOR
#define AKINATOR


enum {
    LOAD_TREE = 1,
    SAVE_TREE,
    FIND_WORD,
    EXIT
};

node_t *add_question      (node_t *curr_node, tree_t *currTree);
void    find_word         (tree_t *node);
node_t *finde_by_name_rec (node_t* startNode, char * const searchingWord, int64_t way_stack, int *deep)


#endif /*AKINATOR*/
