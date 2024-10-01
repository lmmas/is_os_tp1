//
// Created by louismmassin on 10/1/24.
//
#include "memory.h"
int globalVar1 = 3;
int globalVar2 = 0;
char* testString = "test";


void memoryTest() {
    int localVar = 3;
    printf("address of a local variable: %p \n", &localVar);
    printf("address of a global variable initialized: %p \n", &globalVar1);
    printf("address of a global variable initialized to 0: %p \n", &globalVar2);
    printf("address of a local string: %p \n", &testString);
    int* testArray = malloc(sizeof(int)* 3);
    printf("address of a dynamically allocated array: %p \n", &testArray);
    printf("address of the malloc function: %p \n", malloc);
    int * memoryMmap = mmap(NULL,1024,PROT_WRITE,MAP_PRIVATE,-1, 0);
    printf("address of the memory mmap data: %p \n", memoryMmap);
    pmap();
}

void pmap() {
    pid_t parentPID = getpid();
    pid_t childPID = fork();
    if(childPID == 0) {
        char pidString[100];
        sprintf(pidString, "%d", parentPID);
        execlp("pmap", "pmap", "-X", pidString, NULL);
        perror("exec failed");
    }
    else {
        wait(NULL);
    }

}