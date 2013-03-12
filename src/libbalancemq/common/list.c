#include "list.h"

#include <stdlib.h>

BALANCEMQ_list_t* BALANCEMQ_list_create()
{
    BALANCEMQ_list_t* list = \
        (BALANCEMQ_list_t*) malloc(sizeof(BALANCEMQ_list_t));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void BALANCEMQ_list_destroy(BALANCEMQ_list_t* list)
{
    BALANCEMQ_list_node_t* curr = list->head;
    BALANCEMQ_list_node_t* tmp = NULL;

    while(curr != NULL) {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
}

void BALANCEMQ_list_push(BALANCEMQ_list_t* list, void* data)
{
    BALANCEMQ_list_node_t* node = \
        (BALANCEMQ_list_node_t*) malloc(sizeof(BALANCEMQ_list_node_t));

    node->data = data;

    if(list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }

    list->size++;
}

/* EOF */
