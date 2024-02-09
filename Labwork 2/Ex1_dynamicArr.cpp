#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct unboundedInt{
    int digit;
    unboundedInt *next;
}unboundedInt;

