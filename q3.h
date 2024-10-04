//
// Created by cassandre on 01/10/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

typedef struct LinkedList LinkedList;
struct LinkedList {
    int number;
    LinkedList *next;
    LinkedList *previous;
};

LinkedList *initialization(int firstnumber);

void insertion(LinkedList **list, int newnumber);

int displayList(const LinkedList *list);

void sizeList(LinkedList *list);

void address_value(LinkedList *list);

void deleteFirstNumber(LinkedList** list);

void deleteLastNumber(LinkedList** list);

void addLastNumber(LinkedList** list, int newnumber);

void addFirstNumber(LinkedList** list, int newnumber);

void concatenation(LinkedList** list1, LinkedList** list2);

LinkedList *squaredList(LinkedList *list);

#endif //LINKEDLIST_H
