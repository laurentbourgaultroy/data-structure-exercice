#include <assert.h>
#include <memory.h>
#include "vector.h"

const size_t VECTOR_INITIAL_CAPACITY = 8;

static void* address_of_index(struct vector *vector, size_t index)
{
    char *bytes = (char *) vector->elements;    
    size_t byte_index = index * vector->element_size;

    return (void *) (bytes + byte_index);
}

static int is_allocated(struct vector *vector)
{
    // Will catch vector explicitely deallocated
    if (vector->elements == NULL)
    {
        return 0;
    }

    // Unnallocated vector may contains junks that contains this error
    if (vector->capacity < vector->size)
    {
        return 0;
    }

    return 1;
}

int vector_init(struct vector *vector, size_t element_size) 
{
    vector->size = 0;
    vector->element_size = element_size;

    vector->elements = malloc(VECTOR_INITIAL_CAPACITY * element_size);
    vector->capacity = VECTOR_INITIAL_CAPACITY;

    return 1;
}

void vector_free(struct vector *vector)
{
    assert(is_allocated(vector));

    free(vector->elements);
    vector->elements = NULL;
}

int vector_push(struct vector *vector, void **value) 
{
    assert(is_allocated(vector));

    size_t pushed_index = vector->size;
    vector->size += 1;

    if (vector->size > vector->capacity) {
        size_t new_capacity = vector->capacity * 2;
        size_t new_memory_size = new_capacity * vector->element_size;

        vector->elements = realloc(vector->elements, new_memory_size);
        vector->capacity = new_capacity;
    }

    *value = address_of_index(vector, pushed_index);

    return 1;
}

int vector_read(struct vector *vector, size_t index, void **value)
{
    assert(is_allocated(vector));
    assert(index >= 0);
    assert(index < vector->size);

    *value = address_of_index(vector, index);

    return 1;   
}