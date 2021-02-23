#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

#include <stdio.h>

int slide_line(int *line, size_t size, int direction);

size_t find_next_element(int *line, size_t i, size_t size, int direction);

size_t find_next_nz_element(int *line, size_t i, size_t size, int direction);

void merge(int *line, size_t i, size_t next_index, size_t size, int direction);

#endif /* SLIDE_LINE_H */
