//
// Created by cassandre on 04/10/24.
//

#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "q2.h"

#include <unistd.h>


void q2(char * filePath) {

    printf("DEBUG \n");

    int fileDescriptor = open(filePath,O_CREAT|O_RDWR);

    if (fileDescriptor == -1) {
        perror("Error opening file");
    }

    struct stat statbuf;
    if (fstat(fileDescriptor, &statbuf) == -1) {
        perror("Error opening file");
        close(fileDescriptor);
    }

    printf("File size: %ld\n", statbuf.st_size);


    char *file_map = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fileDescriptor, 0);
    if (file_map == MAP_FAILED) {
        perror("Error memory mapping");
        close(fileDescriptor);
    }
    else {
        printf("What's in the file :\n%.*s\n", (int)statbuf.st_size, file_map);
        int textSize = statbuf.st_size - 1;
        for(int i = 0; i < textSize / 2; i++) {
            char tempChar = *(file_map + i);
            *(file_map + i) = *(file_map + textSize - i - 1);
            *(file_map + textSize - i - 1) = tempChar;
        }
        printf("Edited file :\n%.*s\n", (int)statbuf.st_size, file_map);
        munmap(file_map, statbuf.st_size);

        close(fileDescriptor);
    }
}




