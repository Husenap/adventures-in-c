#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H

typedef struct doubly_node {
    int                 value;
    struct doubly_node* next;
    struct doubly_node* prev;
} doubly_node_t;

typedef struct {
    doubly_node_t* head;
} doubly_linked_list_t;

doubly_linked_list_t* doubly_linked_list_create();
void                  doubly_linked_list_destroy(doubly_linked_list_t** list);
doubly_node_t*        doubly_linked_list_add_first(doubly_linked_list_t* list, int value);
void                  doubly_linked_list_add_after(doubly_node_t* node, int value);
void                  doubly_linked_list_print(doubly_linked_list_t* list);
doubly_node_t*        doubly_linked_list_find(doubly_linked_list_t* list, int value);
int                   doubly_linked_list_peek(doubly_linked_list_t* list);
int                   doubly_linked_list_pop(doubly_linked_list_t* list);

#endif  // _DOUBLY_LINKED_LIST_H