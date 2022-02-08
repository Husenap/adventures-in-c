#include "linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

node_t* node_create(int value) {
    node_t* node = malloc(sizeof(node_t));
    if (node) {
        node->value = value;
        node->next  = NULL;
    }
    return node;
}
void node_destroy(node_t* node) {
    printf("Freeing node [addr=%p] with [value=%d]\n", node, node->value);
    free(node);
}

linked_list_t* linked_list_create() {
    linked_list_t* list = malloc(sizeof(linked_list_t));
    if (list) {
        list->head = NULL;
    }
    return list;
}

void linked_list_destroy(linked_list_t** list) {
    node_t* current = (*list)->head;
    while (current) {
        node_t* temp = current->next;
        node_destroy(current);
        current = temp;
    }
    free(*list);
    *list = NULL;
}

void linked_list_add_first(linked_list_t* list, int value) {
    node_t* node = node_create(value);
    node->next   = list->head;
    list->head   = node;
}

void linked_list_add_after(node_t* node, int value) {
    node_t* new_node = node_create(value);
    new_node->next   = node->next;
    node->next       = new_node;
}

void linked_list_print(linked_list_t* list) {
    node_t* current = list->head;
    printf("[");
    while (current) {
        printf("%d - ", current->value);
        current = current->next;
    }
    printf("]\n");
}

node_t* linked_list_find(linked_list_t* list, int value) {
    node_t* current = list->head;
    while (current) {
        if (current->value == value) return current;
        current = current->next;
    }
    return NULL;
}

int linked_list_peek(linked_list_t* list) {
    assert(list->head);
    return list->head->value;
}
int linked_list_pop(linked_list_t* list) {
    assert(list->head);

    node_t* node = list->head;
    list->head   = node->next;

    int value = node->value;
    node_destroy(node);

    return value;
}