#include <stdio.h>
#include "rogue.h"
#include "action.h"

typedef struct State {
	unsigned short int effects_mask;
	unsigned short int action_id;
	unsigned short int combos;
	unsigned short int energy;
} State;

const State START = { EFFECT_NONE, ACTION_PASS, COMBOS_MIN, ENERGY_MAX/ENERGY_STEP };

typedef unsigned short int Tree[ 1 << EFFECTS_COUNT ][ ACTIONS_COUNT ][ COMBOS_MAX + 1 ][ ENERGY_MAX/ENERGY_STEP + 1 ];


unsigned short int EvalScore();
unsigned short int GenerateStates();
unsigned short int isAvaliable( State* from, State* to );
unsigned short int PrintState( State* s, State* s2 );

//-------------------------------------------------------

unsigned short int GenerateStates( Tree* t )
{
	State start = { EFFECT_NONE, ACTION_PASS, COMBOS_MIN, ENERGY_MAX/ENERGY_STEP };
	
	for (int e = 0; e < ( 1 << EFFECTS_COUNT ); e++ )
		for (int a = 0 ; a < ACTIONS_COUNT; a++ )
			for (int c = 0 ; c <= COMBOS_MAX; c++ )
				for (int n = 0 ; n <= ENERGY_MAX/ENERGY_STEP; n++ )
				{
					*t[ e ][ a ][ c ][ n ] = EvalScore( e, a, c, n );

					State this = { e, a, c, n };
					if ( isAvaliable( &start, &this ) )						
						PrintState( &start, &this);
				}
}

unsigned short int EvalScore( int e, int a, int c, int n)
{
	return ( 2 * ACTIONS[ a ].dmg );
}

unsigned short int isAvaliable( State* from, State* to )
{
	int new_energy = from->energy + ACTIONS[to->action_id].energy_gain - ACTIONS[to->action_id].energy_cost;// + ENERGY_REGEN;
	new_energy = new_energy >= ENERGY_MAX/ENERGY_STEP ? ENERGY_MAX/ENERGY_STEP : new_energy >= ENERGY_MIN ? new_energy : ( ENERGY_MAX/ENERGY_STEP + ENERGY_MAX ); // invalid, never equeals 

	int new_combo = from->combos + ACTIONS[to->action_id].combo_gain - ACTIONS[to->action_id].combo_cost;
	new_combo = new_combo >= COMBOS_MAX ? COMBOS_MAX : ( new_combo >= COMBOS_MIN ? new_combo : ( COMBOS_MAX + 100 ) ); // invalid, never equeals 

	unsigned short int new_effect = from->effects_mask | ACTIONS[to->action_id].effects;
	
	//printf("[%3d %3d, %3d %3d, %d %d]", to->combos, new_combo, to->energy, new_energy, to->effects_mask, new_effect );
	return to->combos == new_combo && to->energy == new_energy && to->effects_mask == new_effect;

}

unsigned short int PrintState( State* s, State* s2 )
{
	printf("(\"%15s\" %4d* %3dc %3de)", ACTIONS[ s->action_id ].name, s->effects_mask, s->combos, s->energy*ENERGY_STEP );

	if ( s2 != NULL )
		printf(" -> (\"%15s\" %4d* %3dc %3de) (%d)", ACTIONS[ s2->action_id ].name, s2->effects_mask, s2->combos, s2->energy*ENERGY_STEP, isAvaliable( s, s2 ));

	printf("\n");
}