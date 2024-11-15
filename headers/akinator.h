#ifndef AKINATOR
#define AKINATOR

enum {
    LOAD_THREE = 1,
    SAVE_THREE,
    FIND_WORD,
    EXIT
};

node_t *add_question (node_t *curr_node);
void    find_word(node_t *node);

#endif /*AKINATOR*/
