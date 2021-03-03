#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 **/

void menger(int level)
{
	if (level == -1)
		return;
	else if (level == 0)
		printf("#\n");
	else if (level == 1)
		printf("###\n# #\n###\n");
}
