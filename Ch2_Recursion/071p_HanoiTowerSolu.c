#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
    if (num == 1) // number of disk to move is 1
        printf("Move disk 1 from %c to %c\n", from, to);
    else
    {
        HanoiTowerMove(num - 1, from, to, by); // move num - 1 disks from to by
        printf("Move disk %d from %c to %c\n", num, from, to); // move num-th disk from to to
        HanoiTowerMove(num - 1, by, from, to); // move num - 1 disks by from to
    }
}

int main(void)
{
    // move 3 disk from A to C through B
    HanoiTowerMove(3, 'A', 'B', 'C');
    return 0;
}