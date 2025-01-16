#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct vector vector;

struct vector {
    int size;
    int current_element;
    int *values;
};

struct vector init(int size);

struct vector* reverse(struct vector* self);

void push_back(struct vector* self, int value);

void delete_vector(struct vector* self);

void print_vector(struct vector self);

void erase(struct vector* self, int pos);

int pop_back(struct vector* self);

#endif