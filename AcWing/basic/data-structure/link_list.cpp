#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <iostream>
#include <cstring>

typedef struct Node
{
    int val;
    Node * next;
} Node;


typedef struct LinkList
{
    Node * head;
} LinkList;

LinkList * list_init(){
    LinkList* list = new LinkList;
    list->head = new Node;
    return list;
}

void insert_head(int val, LinkList * list){
    Node * node = new Node;
    node->val = val;
    node->next = list->head->next;
    list->head->next = node;
    return;
}

void innsert_tail(int val, LinkList * list){
    
}






#endif
