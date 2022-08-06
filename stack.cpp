#include "stack.h"

Stack* stackCtor ()
{
    Stack* st = (Stack*) calloc (1, sizeof(Stack));

    st->capacity = START_STACK_SIZE; 
    st->Size = 0;

    st->data = (double*) calloc (st->capacity, sizeof(double));
    accert(st->data);

    return st;
}


//-----------------------------------------------------------------------------


int stackPush (Stack* st, double value)
{
    accert(st);

    if (st->Size >= st->capacity)
        reallocate (st, st->capacity * RESIZE_COEFFICIENT);

    *(st->data + st->Size) = value;
    
    st->Size++;

    return 0;
}


//-----------------------------------------------------------------------------


int stackPop (Stack* st)
{
    accert(st);

    if ((st->Size <= st->capacity/RESIZE_COEFFICIENT) && (st->capacity != START_STACK_SIZE))
        reallocate (st, st->capacity/RESIZE_COEFFICIENT);
    
    --st->Size;

    return 0;
}


//-----------------------------------------------------------------------------


int stackDtor (Stack* st)
{
    accert(st);

    free(st->data);
    free(st);

    return 0;
}


//-----------------------------------------------------------------------------


int reallocate (Stack* st, const size_t newSize) 
{
    accert(st);

    st->capacity = newSize;

    double* tmp = (double*) realloc (st->data, st->capacity * sizeof(double));
    accert(tmp);

    st->data = tmp;

    return 0;
}


void prinStack (const Stack* st)
{
    accert(st);

    for (unsigned num = 0; num < st->Size; num++)
    {
        printf ("%f\n", *(st->data + num));
    }

    printf ("%ld --- %ld\n", st->Size, st->capacity);
}