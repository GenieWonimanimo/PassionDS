#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define CUS_COME_TERM	15 // customer come term : second unit

typedef enum {CHE_BUR, BUL_BUR, DUB_BUR} BUR; // kind of burger : 0, 1, 2

typedef enum {CHE_TERM = 12, BUL_TERM = 15, DUB_TERM = 24} TERM; // time to make burger

int main(void)
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	// 1 sec for 1 1oop
	for (int sec = 0; sec < 3600; sec++)
	{
		if (sec % CUS_COME_TERM == 0) // customer is come!
		{
			switch (rand() % 3) // kind of burger
			{
			// EnQueue mean customer go into the waiting room
			case CHE_BUR:
				EnQueue(&que, CHE_TERM);
				cheOrder++;
				break;
			case BUL_BUR:
				EnQueue(&que, BUL_TERM);
				bulOrder++;
				break;
			case DUB_BUR:
				EnQueue(&que, DUB_TERM);
				dubOrder++;
				break;
			}
		}
		
		// burger maker is free && there is burger has to make
		if (makeProc <= 0 && !QIsEmpty(&que))
			makeProc = DeQueue(&que); // customer wait at outside of the waiting room

		makeProc--;
	}

	printf("Simulation Report! \n");
	printf(" - Cheese burger: %d \n", cheOrder);
	printf(" - Bulgogi burger: %d \n", bulOrder);
	printf(" - Double burger: %d \n", dubOrder);
	printf(" - Waiting room size: %d \n", QUE_LEN);
	return 0;
}