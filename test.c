#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "test.h"

void vector_start_empty() {
    struct vector vector;

    vector_init(&vector, sizeof(int));

    assert_equals(0, vector.size, "Vector must start empty");
}

void adding_item_increase_size() 
{
    struct vector vector;
    vector_init(&vector, sizeof(int));

    for (size_t i = 0; i < VECTOR_INITIAL_CAPACITY; ++i) {;
        int *current;
        vector_push(&vector, (void**)&current);

        assert_equals(
            i + 1, 
            vector.size, 
            "Vector must increase size when adding items");
    }
}

void assert_can_insert_up_to_size(struct vector *vector, size_t insert_size)
{
    for (size_t i = 0; i < insert_size; i++) 
    {
        int *expected_value = NULL;
        int *actual_value = NULL;

        vector_push(vector, (void**)&expected_value);
        *expected_value = i * 10;

        vector_read(vector, i, (void**)&actual_value);

        assert_equals(
            *expected_value, 
            *actual_value, 
            "Reading a value must yield the value affected to it");
    }
}

void added_item_are_accessible() 
{
    struct vector vector;
    vector_init(&vector, sizeof(int));

    assert_can_insert_up_to_size(&vector, VECTOR_INITIAL_CAPACITY);
}

void vector_expand_beyond_initial_capacity()
{
    struct vector vector;
    size_t beyond_initial_capacity = VECTOR_INITIAL_CAPACITY * 10000;
    vector_init(&vector, sizeof(int));

    assert_can_insert_up_to_size(&vector, beyond_initial_capacity);
}

int main(int argc, char *argv[])
{
    init_errors();

    vector_start_empty();
    adding_item_increase_size();
    added_item_are_accessible();
    vector_expand_beyond_initial_capacity();

    if (errors.count > 0) {
        printf("Unit Tests FAILED!\n\n");
        display_errors();

        return EXIT_FAILURE;
    }

    printf("Unit Tests SUCCESS!\n");
    return EXIT_SUCCESS;
}

void init_errors() {
    errors.count = 0;

    for (int i = 0; i < MAX_ERROR_COUNT; i++)
    {
        errors.messages[i] = NULL;
    }
}

void display_errors() {
    for (int i = 0; i < errors.count; i++) 
    {
        printf("%s\n", errors.messages[i]);
    }

    printf("\n");
}

void assert_equals(int expected, int actual, char *message)
{
    char *error_message = NULL;
    int error_index = 0;

    if (expected == actual) 
    {
        return;
    }

    asprintf(
        &error_message, 
        "Failed assertion: %s: expected %i but got %i", 
        message, 
        expected, 
        actual);

    error_index = errors.count;
    errors.messages[error_index] = error_message;
    errors.count += 1;
}