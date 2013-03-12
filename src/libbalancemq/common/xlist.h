#ifndef _BALANCEMQ_XLIST_H
#define _BALANCEMQ_XLIST_H

typedef struct BALANCEMQ_list_node_t {
    void* data;
    struct BALANCEMQ_list_node_t* next;
    struct BALANCEMQ_list_node_t* prev;
} BALANCEMQ_list_node_t;

typedef struct {
    int size;
    BALANCEMQ_list_node_t* head;
    BALANCEMQ_list_node_t* tail;
} BALANCEMQ_list_t;

BALANCEMQ_list_t* BALANCEMQ_list_create();

void BALANCEMQ_list_destroy(BALANCEMQ_list_t* list);
void BALANCEMQ_list_push(BALANCEMQ_list_t* list, void* data);

#endif /* _BALANCEMQ_XLIST_H */
