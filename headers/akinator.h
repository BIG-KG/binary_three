#ifndef AKINATOR
#define AKINATOR


enum {
    LOAD_TREE = 1,
    SAVE_TREE,
    FIND_WORD,
    EXIT
};

node_t *add_question (node_t *curr_node, tree_t *currTree);
void    find_word(tree_t *node);

#endif /*AKINATOR*/
