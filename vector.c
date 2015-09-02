#include <assert.h>
#include <memory.h>
#include "vector.h"

const size_t VECTOR_INITIAL_CAPACITY = 8;

void* address_of_index(struct vector *vector, size_t index)
{
	char *bytes = (char *) vector->elements;	
	size_t byte_index = index * vector->element_size;

	return (void *) (bytes + byte_index);
}


int vector_init(struct vector *vector, size_t element_size) 
{
	vector->size = 0;
	vector->element_size = element_size;

	vector->elements = malloc(VECTOR_INITIAL_CAPACITY * element_size);

	return 1;
}

int vector_push(struct vector *vector, void **value) 
{
	size_t pushed_index = vector->size;
	vector->size += 1;

	*value = address_of_index(vector, pushed_index);

	return 1;
}

int vector_read(struct vector *vector, size_t index, void **value)
{
	assert(index >= 0);
	assert(index < vector->size);

	*value = address_of_index(vector, index);

	return 1;	
}