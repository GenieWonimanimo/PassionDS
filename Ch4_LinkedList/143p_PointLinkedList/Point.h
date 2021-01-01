#ifndef __POINT_H__
#define __POINT_H__

typedef struct _Point
{
	int xpos;
	int ypos;
} Point;

// set xpos, ypos of Point
void SetPointPos(Point* ppos, int xpos, int ypos);

// print xpos, ypos of Point
void ShowPointPos(Point* ppos);

// compare two Point
int PointComp(Point* pos1, Point* pos2);

#endif