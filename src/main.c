#include <stdlib.h>
#include <stdio.h>

#include "state.h"

int main()
{
	Tree TREE;

	/*
	printf("tree: %d %d %d %d | %d - %dMB\n",
		1 << EFFECTS_COUNT,
		ACTIONS_COUNT,
		COMBOS_MAX + 1,
		ENERGY_MAX/ENERGY_STEP + 1,
		(
			(1 << EFFECTS_COUNT)
			*ACTIONS_COUNT
			*( COMBOS_MAX + 1)
			*(ENERGY_MAX/ENERGY_STEP+1)
		),
		sizeof(TREE) >> 20
	);
	*/

	GenerateStates( &TREE );


	
	printf("------\n");


}