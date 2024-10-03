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
};

LinkedList *initialization() ;
void insertion(LinkedList *list, int newnumber);

int display(LinkedList *list);

int sizeList(LinkedList *list);

void address_value(LinkedList *list);

LinkedList* deleteFirstNumber(LinkedList *list);

#endif //LINKEDLIST_H
