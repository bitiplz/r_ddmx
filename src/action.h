#include "effect.h"

#define ACTIONS_COUNT 1

#define ACTION_PASS 0

enum action { A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16 };

enum school { NODMG, PHYSICAL, NATURE };
enum gcdcat { NONE, NORMAL };

typedef struct Action {
	unsigned short int id;
	char* name;
	enum school school;
	unsigned short int dmg;
	unsigned short int energy_cost;
	unsigned short int energy_gain;
	unsigned short int combo_cost;
	unsigned short int combo_gain;
	unsigned short int range;
	unsigned short int cast;
	unsigned short int cd;
	unsigned short int gcd;
	enum gcdcat gcdcat;
	unsigned short int effects;
} Action;


const Action ACTIONS[ ACTIONS_COUNT ] = {
//	 id  name				dmg_type	dmg 	e_cost 	e_gain 	c_cost 	c_gain 	range	cast 	cd 		gdd 	gcdcat 		effects
	{ 0, "Pass", 			NODMG, 		0,		0,		0,		0, 		0,  	0, 		0, 		0, 		1, 		NONE,   	EFFECT_NONE },
	//{ 1, "Fan of Knives", 	PHYSICAL, 	1,		2,		0,		0, 		1,		10,  	0, 		0, 		1, 		NORMAL, 	EFFECT_NONE },
	//{ 2, "Mutilate", 		PHYSICAL, 	2,		4,		0,		0,		2,		10,		0,  	0, 		1, 		NORMAL, 	EFFECT_NONE },
	//{ 3, "Envenom", 		NATURE, 	7,		3,		0,		5,		0,		10,		0,  	0, 		1, 		NORMAL, 	EFFECT_NONE },
};