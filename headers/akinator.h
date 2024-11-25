#ifndef AKINATOR
#define AKINATOR



enum mode{
    LOAD_TREE = 1,
    SAVE_TREE,
    FIND_WORD,
    EXIT
};

node_t     *add_question      (node_t *currNode, tree_t *currTree, int addingType);
void        find_word         (tree_t *node);
node_way_t  finde_by_name     (char * const searchingWord, tree_t *searchingTree);
int         give_definition   (char * const name, tree_t *searchingTree);
int         yes_no_scan       ();
int         addStart          (tree_t *currTree);
int         add_before        (tree_t *currTree);

int         right_left_scanStart(tree_t *currTree, node_t *newStart, char *rAns);


#endif /*AKINATOR*/
