#include "doubly_linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

doubly_node_t* doubly_node_create(int value) {
    doubly_node_t* node = malloc(sizeof(doubly_node_t));
    if (node) {
        node->value = value;
        node->next  = NULL;
        node->prev  = NULL;
    }
    return node;
}
void doubly_node_destroy(doubly_node_t* node) {
    printf("Freeing node [addr=%p] with [value=%d]\n", node, node->value);
    free(node);
}

doubly_linked_list_t* doubly_linked_list_create() {
    doubly_linked_list_t* list = malloc(sizeof(doubly_linked_list_t));
    if (list) {
        list->head = NULL;
    }
    return list;
}

void doubly_linked_list_destroy(doubly_linked_list_t** list) {
    doubly_node_t* current = (*list)->head;
    while (current) {
        doubly_node_t* temp = current->next;
        doubly_node_destroy(current);
        current = temp;
    }
    free(*list);
    *list = NULL;
}

doubly_node_t* doubly_linked_list_add_first(doubly_linked_list_t* list, int value) {
    doubly_node_t* node = doubly_node_create(value);
    list->head->prev    = node;
    node->next          = list->head;
    list->head          = node;
    return node;
}

void doubly_linked_list_add_after(doubly_node_t* node, int value) {
    doubly_node_t* new_node = doubly_node_create(value);
    new_node->next          = node->next;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
    new_node->prev = node;
    node->next     = new_node;
}

void doubly_linked_list_print(doubly_linked_list_t* list) {
    doubly_node_t* current = list->head;
    printf("[");
    while (current) {
        printf("%d - ", current->value);
        current = current->next;
    }
    printf("]\n");
}

doubly_node_t* doubly_linked_list_find(doubly_linked_list_t* list, int value) {
    doubly_node_t* current = list->head;
    while (current) {
        if (current->value == value) return current;
        current = current->next;
    }
    return NULL;
}

int doubly_linked_list_peek_front(doubly_linked_list_t* list) {
    assert(list->head);
    return list->head->value;
}
int doubly_linked_list_pop_front(doubly_linked_list_t* list) {
    assert(list->head);

    doubly_node_t* node = list->head;
    list->head          = node->next;

    int value = node->value;
    doubly_node_destroy(node);

    return value;
}