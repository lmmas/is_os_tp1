//
// Created by cassandre on 01/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "q3.h"

// INITIALIZATION OF THE LINKED LIST (FIRST TERM)

LinkedList *initialization() {
    LinkedList *list = malloc(sizeof(*list));
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }
    list->number = 0;
    printf("%d ", list->number);
    list->next = NULL;
    return list;
}

// INSERTION OF TERMS IN THE LINKED LIST

void insertion(LinkedList *list, int newnumber) {
    if (list == NULL ) {
        exit(EXIT_FAILURE);
    }

    list->number = newnumber;
    printf("%d ", newnumber);
    list->next ;




}

/*
int display(LinkedList *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
    return 0;
}
*/
int sizeList(LinkedList *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }
    int size = 0;
    LinkedList *current = list;
    printf("%p", current);
    while (current != NULL) {
        size++;

        current = current->next;

    }
    printf("\nThe size of the list is: %d \n", size);

    // printf("\nThe size of the list is: %d \n", size);
    return 0;
}

/*
void address_value(LinkedList *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;

    while (current != NULL) {
        printf("<address of the number: %p  > Number: %d \n", (void*) current ,  current->number);
        current = current->next;
    }

}

LinkedList* deleteFirstNumber(List *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    LinkedList *deleteList = initialization();
    if (deleteList->first == NULL) {
        exit(EXIT_FAILURE);
    }



    Element *delete = list->first;
    list->first = list->first->next;

    Element *current = list->first;

    while (current != NULL) {
        insertion(deleteList,current->number);
        current = current->next;
        //printf("%d ", current->number);
    }

    free(delete);
    return deleteList;
}*/