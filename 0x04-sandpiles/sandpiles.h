#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

void add_sandpiles(int grid1[3][3], int grid2[3][3]);

int is_stable_sandpile(int grid1[3][3]);

void topple(int grid1[3][3], int topple_count);

static void print_grid(int grid[3][3]);

#endif /* SANDPILES_H */
