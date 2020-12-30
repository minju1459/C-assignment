#ifndef __PUSH_H
#define __PUSH_H

#define _MY_DEBUG

#define SIZE			    10
//icon
#define ICON_EMPTY		    0
#define ICON_WALL		    1
#define ICON_OBSTACLE		2
#define ICON_OBSTACLE_ADD	3
#define ICON_TARGET		    4
#define ICON_BLOCK		    7
#define ICON_USER		    8
#define ICON_KILLER		    9

//key
#define KEY_EXT			224
#define KEY_UP          72
#define KEY_DOWN		80
#define KEY_RIGHT		77
#define KEY_LEFT		75
#define KEY_STOP		'q'
#define KEY_RESET		'r'

//return value
#define RET_SUCCESS		1
#define RET_FAIL		0

//struct define
typedef struct _Point{
	int row;
	int column;
}Point;

//function define
void  init();
void  display();
int  getKey();
void  check();
void move();
int finish();

#endif