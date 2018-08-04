#define EFFECTS_COUNT 1

#define EFFECT_NONE 0

enum effect { E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16 };

typedef struct Effect {
	unsigned short int id;
	char* name;
	double value;
	unsigned short int duration;
} Effect;


const Effect EFFECTS[ EFFECTS_COUNT ] = {
	{ 0, "NONE",		 		0.0,  0 },
	//{ 1, "Energy Boost", 		2.0, 10 },
	//{ 2, "Damage Boost", 		2.0,  5 },
};