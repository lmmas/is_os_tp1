#include "main.h"
#include "q3.h"

int main(void) {
    //mainMemoryTest();
    //memoryTest();
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
    


    return 0;
}
/*
void mainMemoryTest() {
    printf("address of the main function: %p \n", main);

}*/