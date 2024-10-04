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


void getSizeFile() {

    printf("DEBUG \n");

    int fileDescription = open("/home/cassandre/Documents/TP réseau/test.txt",O_RDONLY);

    if (fileDescription == -1) {
        perror("Error opening file");
    }

    struct stat statbuf;
    if (stat("/home/cassandre/Documents/TP réseau/test.txt", &statbuf) == -1) {
        perror("Error opening file");
        close(fileDescription);
    }

    if (statbuf.st_size == 0) {
        printf("Empty File.\n");
        close(fileDescription);
    }

    printf("File size: %ld\n", statbuf.st_size);


    char *file_mappe = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fileDescription, 0);
    if (file_mappe == MAP_FAILED) {
        perror("Error memory mapping");
        close(fileDescription);
    }

    printf("What's in the file :\n%.*s\n", (int)statbuf.st_size, file_mappe);

    munmap(file_mappe, statbuf.st_size);

    close(fileDescription);
}




