#include "list.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <fmt/format.h>

ListNode_t* NewListNode(void)
{
    fmt::println("in \"{}\"",__func__);
    ListNode_t* n = (ListNode_t*) malloc(sizeof(ListNode_t));
    n->data = 0;
    n->pNext = NULL;

    return NULL;
}

void FreeListNode(ListNode_t* elem)
{
    fmt::println("in \"{}\"",__func__);
    free(elem);
}

List_t* NewList(void)
{
    fmt::println("in \"{}\"",__func__);
    List_t* n = (List_t*) malloc(sizeof(List_t));
    n->pHead = NULL;
    n->pTail = NULL;
    n->size = 0;
    return NULL;
}

void FreeList(List_t* list)
{
    fmt::println("in \"{}\"",__func__);
    for (ListNode_t* cur = list->pHead; cur != NULL; cur = cur->pNext)
    {
        FreeListNode(cur);
    }
}

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);

    if(list->pTail == NULL)
    {
        /* empty list */
        list->pHead = elem;
        list->pTail = elem;
        elem->pNext = NULL;
    }
    else
    {
        /* append at the end */
        list->pTail->pNext = elem;
        list->pTail = elem;
        elem->pNext = NULL;
    }

    list->size = list->size + 1;

    return EXIT_SUCCESS;
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node, ListNode_t* elem)
{
    fmt::println("in \"{}\"", __func__);

    if (list == NULL || node == NULL || elem == NULL)
        return EXIT_FAILURE;

    elem->pNext = node->pNext;
    node->pNext = elem;

    if (node == list->pTail)
        list->pTail = elem;

    list->size++;

    return EXIT_SUCCESS;
}

int RemoveFromList(List_t* list, ListNode_t* elem)
{
    fmt::println("in \"{}\"", __func__);

    if (list == NULL || elem == NULL)
        return EXIT_FAILURE;

    ListNode_t* prev = NULL;
    ListNode_t* cur  = list->pHead;

    while (cur != NULL && cur != elem) {
        prev = cur;
        cur = cur->pNext;
    }

    if (cur == NULL)
        return EXIT_FAILURE;

    if (cur == list->pHead) {
        list->pHead = cur->pNext;

        if (cur == list->pTail)
            list->pTail = NULL;
    }

    else if (cur == list->pTail) {
        prev->pNext = NULL;
        list->pTail = prev;
    }
    
    else {
        prev->pNext = cur->pNext;
    }

    FreeListNode(cur);
    list->size--;

    return EXIT_SUCCESS;
}


ListNode_t* GetNext(const List_t* list, ListNode_t* elem)
{
    fmt::println("in \"{}\"",__func__);
    return NULL;
}