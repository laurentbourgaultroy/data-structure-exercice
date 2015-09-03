#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>

struct vector {
    size_t size;
    size_t capacity;
    size_t element_size;
    void *elements;
};

extern const size_t VECTOR_INITIAL_CAPACITY;

int vector_init(struct vector *vector, size_t element_size);
void vector_free(struct vector *vector);

int vector_push(struct vector *vector, void **value);
int vector_read(struct vector *vector, size_t index, void **value);

#endif