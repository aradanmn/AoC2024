//
//  Common.h
//  AoC2024
//
//  Created by Scott Dean on 12/15/24.
//

#ifndef Common_h
#define Common_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

FILE* FileOpen(const char* filename, const char* mode);

void initArray(DynamicArray *arr, int initialCapacity);
void addElement(DynamicArray *arr, int value);
void freeArray(DynamicArray *arr);

#endif /* Common_h */
