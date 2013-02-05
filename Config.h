// Config.h
//
//////////////////////////////////////////////////////////////////////
#ifndef	_CONFIG_H_
#define _CONFIG_H_

// Map config info
#define MAP_W	10	// map width
#define MAP_L	10	// map length

// Mouse config info
#define MOUSE_NAME	"mouse"
#define MOUSE_ENERGY	1	
#define MOUSE_VIEW	2	

// Cat config info
#define CAT_NAME	"cat"
#define CAT_ENERGY	1	
#define CAT_VIEW	2	

// Cheese config info
#define CHEESE_NAME	"cheese"

// Obstacle config info
#define OBSTACLE_NAME	"obstacle"

// Probability that animal will go a position.
// From positive position to negative position
#define S1_POS_PROB_A	0.45
#define S1_POS_PROB_B	0.45
#define S1_POS_PROB_C	0.05
#define S1_POS_PROB_D	0.025
#define S1_POS_PROB_E	0.025
#define S2_POS_PROB_A	0.8
#define S2_POS_PROB_B	0.1
#define S2_POS_PROB_C	0.04
#define S2_POS_PROB_D	0.04
#define S2_POS_PROB_E	0.02

//! A position and its robability that animal will go to
typedef struct
{
	int		x;
	int		y;
	float	prob;
}PosProb;

#endif
