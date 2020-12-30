
#include"tetris.h"


Point	current;
int		curBlock;
int		curDir;
int		basGround[MY_HIGH][MY_WIDTH];	//base
int		disGround[MY_HIGH][MY_WIDTH];	//dispaly
int		preGround[MY_HIGH][MY_WIDTH];	//previous


Point	blockPattern[MY_PATTERN_NUM][4][4] = {
	{ { 0, 0, 1, 0, 2, 0, 3, 0 }, 
	  { 1, 0, 1, 1, 1, 2, 1, 3 }, 
	  { 0, 0, 1, 0, 2, 0, 3, 0 }, 
	  { 1, 0, 1, 1, 1, 2, 1, 3 } },

	{ { 0, 0, 1, 0, 2, 0, 1, 1 }, 
	  { 0, 0, 0, 1, 0, 2, 1, 1 }, 
	  { 1, 0, 0, 1, 1, 1, 2, 1 }, 
	  { 2, 0, 2, 1, 2, 2, 1, 1 } },

	{ { 0, 0, 0, 1, 1, 0, 1, 1 }, 
	  { 0, 0, 0, 1, 1, 0, 1, 1 }, 
      { 0, 0, 0, 1, 1, 0, 1, 1 }, 
      { 0, 0, 0, 1, 1, 0, 1, 1 } }
};
