#include "main.h"

#include "q2.h"
#include "q3.h"

int main(void) {
    //mainMemoryTest();
    //memoryTest();

    //display_question3();
    q2("../test.txt");
    return 0;
}


void mainMemoryTest() {
    printf("address of the main function: %p \n", main);

}