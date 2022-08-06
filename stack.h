#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

const int START_STACK_SIZE   = 4;
const int RESIZE_COEFFICIENT = 2;


struct Stack
{
    double *data;
    size_t capacity;
    size_t Size;
};


Stack* stackCtor  (Stack* st);
int    stackPush  (Stack* st, double value);
int    stackPop   (Stack* st); 
int    stackDtor  (Stack* st);
int    reallocate (Stack* st, size_t newSize);

void prinStack (const Stack* st);