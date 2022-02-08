#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

int main() {
    linked_list_t* list = linked_list_create();

    for (int i = 0; i < 10; ++i) {
        linked_list_add_first(list, i);
    }

    linked_list_print(list);

    node_t* five = linked_list_find(list, 5);
    linked_list_add_after(five, 42);

    linked_list_print(list);

    printf("peek = %d\n", linked_list_peek(list));
    printf("pop  = %d\n", linked_list_pop(list));

    linked_list_print(list);

    linked_list_destroy(&list);

    return 0;
}