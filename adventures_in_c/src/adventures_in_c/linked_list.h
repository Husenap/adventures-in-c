#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct node {
    int          value;
    struct node* next;
} node_t;

typedef struct linked_list {
    node_t* head;
} linked_list_t;

linked_list_t* linked_list_create();
void           linked_list_destroy(linked_list_t** list);
void           linked_list_add_first(linked_list_t* list, int value);
void           linked_list_add_after(node_t* node, int value);
void           linked_list_print(linked_list_t* list);
node_t*        linked_list_find(linked_list_t* list, int value);
int            linked_list_peek(linked_list_t* list);
int            linked_list_pop(linked_list_t* list);

#endif