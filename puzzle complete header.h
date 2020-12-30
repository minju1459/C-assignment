#ifndef _PZ19_H    //ifndef define->묶어서 , endif 꼭 넣기
#define _PZ19_H

//구조체 정의
typedef struct _Point{
	int row;
	int Column;
}Point;

//key
#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_RIGHT   77
#define KEY_LEFT    75
#define KEY_STOP    'q'
#define KEY_RESET   'r'

#define FILE_SCORE  "score110.txt"

void	init(Point *cPoint);
void	display(int key);
void	getIndex(int key, Point cPoint, Point *mPoint);
void	change(Point *cPoint, Point mPoint);
int		check();
void	reset(Point *cPoint);
int		getKey();
int		getLine();
int		play(Point *cPoint);

#endif