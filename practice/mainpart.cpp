#include<graphics.h>
#include<iostream>
#include <Windows.h>


IMAGE heart, heartmask;

void begin1()
{
	loadimage(&heart, L"image/heart.jpg");
	loadimage(&heartmask, L"image/heartmask.jpg");
	for (int i = 10; i < 750;)
	{
		bool color = 0;
		cleardevice();
		setfillcolor(WHITE);
		solidcircle(640, 360, i);		 putimage(220, 90, &heartmask, NOTSRCERASE); putimage(220, 90, &heart, SRCINVERT);
		for (int j = i; j >= 10; j -= 15)
		{
			if (color == 0)
			{
				setfillcolor(MAGENTA);
				solidcircle(640, 360, j);		 putimage(220, 90, &heartmask, NOTSRCERASE); putimage(220, 90, &heart, SRCINVERT);
				color = 1;
			}
			else
			{
				setfillcolor(WHITE);
				solidcircle(640, 360, j);		 putimage(220, 90, &heartmask, NOTSRCERASE); putimage(220, 90, &heart, SRCINVERT);
				color = 0;
			}
		}
		FlushBatchDraw();
		if (i < 150)
		{
			i++;
		}
		else if (i < 300)
		{
			i += 2;
		}
		else if (i < 400)
		{
			i += 3;
		}
		else if (i < 500)
		{
			i += 4;
		}
		else
		{
			i += 5;
		}
		Sleep(7);
	}
}
int main()
{
	int x = 640, y = 360, size = 10;
	initgraph(1280, 720);
	BeginBatchDraw();
	while (true)
	{
		begin1();
	}
	EndBatchDraw();
	return 0;
}