//
// Created by cassandre on 01/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "q3.h"

// INITIALIZATION OF THE LINKED LIST (FIRST TERM)

LinkedList *initialization(int firstnumber) {
    LinkedList *list = malloc(sizeof(*list));
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }
    list->number = firstnumber;
    list->next = NULL;
    return list;
}


// INSERTION OF TERMS IN THE LINKED LIST

void insertion(LinkedList** list, int newnumber) {

    LinkedList *newnode = malloc(sizeof(*newnode));
    newnode->number = newnumber;
    newnode->next = NULL;
    newnode->previous = NULL;

    if (*list == NULL) {
        *list = newnode;
        return;
    }
    LinkedList* current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newnode;
    newnode->previous = current;
}

// DISPLAY THE LINKED LIST

int displayList(const LinkedList* list) {

    while (list != NULL) {
        printf("%d  ", list->number);
        list = list->next;
    }
    printf("\n");
    return 0;
}

// THE SIZE OF LINKED LIST



void sizeList(LinkedList *list) {
    int size = 0;
    while (list != NULL) {
        size++;
        list = list->next;
    }
    printf("The size of our linkedList is: %d\n", size);
}

// PRINT EACH TERMS OF THE LIST AND THEIR ADDRESSES

void address_value(LinkedList *list) {

    while (list != NULL) {
        printf("<address of the number: %p  > Number: %d \n", (void*) list ,  list->number);
        list = list->next;
    }
    printf("\n");
}

// DELETE THE FIRST TERM OF THE LIST


void deleteFirstNumber(LinkedList** list) {
    if (*list == NULL) {
        printf("No terms in your list");
        return;
    }

    LinkedList *current = *list;
    *list = (*list)->next;
    free(current);
}

void deleteLastNumber(LinkedList** list) {
    // list empty
    if (*list == NULL) {
        printf("No terms in your list");
        return;
    }

    //list with one term
    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return;
    }

    LinkedList* current = *list;
    while(current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void addLastNumber(LinkedList** list, int newnumber) {
    insertion(list, newnumber);
    displayList(*list);
}

void addFirstNumber(LinkedList** list, int newnumber) {
    if (*list == NULL) {
        printf("No terms in your list");
        return;
    }
    LinkedList *newnode = malloc(sizeof(*newnode));
    newnode->number = newnumber;
    newnode->next = *list;
    *list = newnode;
    displayList(*list);
}

// CONCATENATION OF LISTS

void concatenation(LinkedList** list1, LinkedList** list2) {
    if (*list1 == NULL) {
        printf("No terms in your list1");
    }

    else if (*list2 == NULL) {
        printf("No terms in your list2");
    }

    else {
        LinkedList* current = *list1;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = *list2;

        while(current->next->next != NULL) {
            current = current->next;
        }
    }
}

LinkedList *squaredList(LinkedList* list) {

        LinkedList* newList = NULL;

        LinkedList *current = list;
        while (current != NULL) {
            insertion(&newList, current->number * current->number);
            current = current->next;
        }
        return newList;
    }

void display_question3(void) {

    LinkedList *list1 = initialization(0);
    insertion(&list1,1);
    insertion(&list1,2);
    insertion(&list1,3);
    insertion(&list1,4);
    insertion(&list1,5);

    printf("List1 : ");
    displayList(list1);

    sizeList(list1);
    address_value(list1);

    deleteFirstNumber(&list1);
    printf("Delete the first number of the list : ");
    displayList(list1);

    deleteLastNumber(&list1);
    printf("Delete the last number of the list : ");
    displayList(list1);

    printf("Add a number at the end of the list : ");
    addLastNumber(&list1,1);

    printf("Add a number at the beginning of the list : ");
    addFirstNumber(&list1,10);


    LinkedList *list2 = initialization(11);
    insertion(&list2,12);
    insertion(&list2,13);
    insertion(&list2,14);
    insertion(&list2,15);
    insertion(&list2,16);

    printf("List1 : ");
    displayList(list1);

    printf("List2 : ");
    displayList(list2);

    printf("List1 and List2 concatenated : ");
    concatenation(&list1,&list2);
    displayList(list1);

    printf("List1 : ");
    displayList(list1);
    LinkedList* list3 = squaredList(list1);
    printf("List3 : ");
    displayList(list3);

}