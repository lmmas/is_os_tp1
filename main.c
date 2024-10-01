#include "main.h"

int main(void) {
    mainMemoryTest();
    memoryTest();
    return 0;
}

void mainMemoryTest() {
    printf("address of the main function: %p \n", main);
}