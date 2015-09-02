#ifndef TEST_H
#define TEST_H

const int MAX_ERROR_COUNT = 1000;
struct {
	int count;
	char *messages[MAX_ERROR_COUNT];
} errors;

void init_errors();
void display_errors();
void assert_equals(int expected, int actual, char *message);

#endif