#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "test.h"

void vector_start_empty() {
    struct vector vector;

    vector_init(&vector, sizeof(int));

    assert_equals(0, vector.size, "Vector must start empty");
}

void adding_item_increase_size() {
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

void added_item_are_accessible() {
    struct vector vector;
    vector_init(&vector, sizeof(int));

    for (size_t i = 0; i < VECTOR_INITIAL_CAPACITY; i++) {
        int *expected_value;
        vector_push(&vector, (void**)&expected_value);
        *expected_value = 10;

        int *actual_value;
        vector_read(&vector, i, (void**)&actual_value);

        assert_equals(
            *expected_value, 
            *actual_value, 
            "Reading a value must yield the value affected to it");
    }
}

int main(int argc, char *argv[])
{
    init_errors();

    vector_start_empty();
    adding_item_increase_size();
    added_item_are_accessible();

    if (errors.count > 0) {
        printf("Unit Tests FAILED!\n\n");

        for (int i = 0; i < errors.count; i++) 
        {
            printf("%s\n", errors.messages[i]);
        }

        printf("\n");

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