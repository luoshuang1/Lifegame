#include<iostream>
#include<string.h>
#include <iomanip>
#include<graphics.h>//easyx的库
#include"funtion_declaration.h"
#include"Tape.h"
#include<string>
#include<fstream>
#include<conio.h>
//#include <cctype>
using namespace std;

//mciSendString需要的头文件

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define SQUARE 10//一个格子的宽高
#define COLS 80
//纵向格子数
#define ROWS 80
//横向格子数
#define ADD 40
//额外设置供操作的用户界面窗口






enum COLORS{green=1,red,blue,yellow,cyan,magenta,customization};//青色：Cyan;洋红色：Magenta


COLORREF _cellcolor = WHITE;

extern int velocity;
int Continue = 1;//设置全局变量
bool Click = true;
bool Action = true;
int scount = 0;//记录已经注册的用户数
void draw(int x, int y, int state, COLORREF cellcolor)
{
	//边框的颜色
	setcolor(RGB(167, 167, 167));
	/*RGB(167, 167, 167)代表的是灰色。在RGB颜色模型中，每个颜色通道的取值范围是0到255，其中红色（R）、绿色（G）和蓝色（B）分别对应三个通道。当这三个通道的取值相等时，就会得到一种灰色*/
	if (state == 1)
	{
		setfillcolor(cellcolor);
	}//填充颜色
	else
	{
		setfillcolor(BLACK);
	}

	//填充矩形，四个参数为左上角坐标和右下角坐标
	fillrectangle(x, y, x + SQUARE, y + SQUARE);
}

//画整个界面
void drawmap(int map[ROWS][COLS], COLORREF cellcolor1)


{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			draw(j * SQUARE, i * SQUARE, map[i][j], cellcolor1);
		}
	}

}
//根据鼠标输入来设置格子存活状态
void getAndSet(int map[ROWS][COLS])
{
	cout << "绘画结束后点击最右下角方块即可进入演变" << endl;
	MOUSEMSG msg;
	int x, y;
	/*MOUSEMSG是EasyX图形库中的一个结构体类型，用于描述鼠标消息。该结构体包含了鼠标事件的类型、坐标等信息，以便程序可以对鼠标事件进行响应和处理。*/
	while (Continue)
	{
		msg = GetMouseMsg();
		//这个函数用于获取一个鼠标消息。如果当前鼠标消息队列中没有，就一直等待。
		x = msg.x / SQUARE;
		y = msg.y / SQUARE;
		if (msg.mkLButton)//鼠标左键点击
		{
			map[y][x] = 1;//注意到x是横坐标row
			//设置结束操作
			if (y == (ROWS - 1) && x == (COLS - 1))
			{
				Continue = 0;

			}
		}
		else
		{
			map[y][x] = 0;
		}
	}
}

int getPoint(int map[ROWS][COLS], int x, int y)
{
	int _x, _y;
	int num = 0;
	for (int i = 0; i < 8; i++)
	{
		switch (i)
		{
		case 0:
			_x = x;
			_y = y - 1;
			break;
		case 1:
			_x = x;
			_y = y + 1;
			break;
		case 2:
			_x = x - 1;
			_y = y;
			break;
		case 3:
			_x = x + 1;
			_y = y;
			break;
		case 4:
			_x = x + 1;
			_y = y + 1;
			break;
		case 5:
			_x = x + 1;
			_y = y - 1;
			break;
		case 6:
			_x = x - 1;
			_y = y + 1;
			break;
		case 7:
			_x = x - 1;
			_y = y - 1;
			break;
		}
		if (_x >= 0 && _y >= 0 && _x < COLS && _y < ROWS && map[_y][_x] == 1)
		{
			num++;
		}


	}
	return num;
}

void lifeWeek(int map[ROWS][COLS])
{
	int num;
	int  tem[ROWS][COLS] = { 0 };
	

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			num = getPoint(map, j, i);
			if (num == 3)
			{
				tem[i][j] = 1;
			}
			else if (num == 2)
			{
				tem[i][j] = map[i][j];
			}
			else
			{
				tem[i][j] = 0;
			}
		}
	}
	memcpy(map, tem, sizeof(int) * ROWS * COLS);
	
	
}



void setButton(Button& button, int _x1, int _y1, int _x2, int _y2,const char a[])
{
	button.x1 = _x1;
	button.x2 = _x2;
	button.y1 = _y1;
	button.y2 = _y2;
	setfillcolor(WHITE);
	fillrectangle(button.x1, button.y1,button.x2,button.y2);
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("华文新魏"));
	outtextxy(_x1+5, _y1+10, a);
	
	//设置按钮与鼠标交互
	
	/*while (1)
	{
		if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
		{
			MOUSEMSG msg = GetMouseMsg();
			//判断是否是左键按下
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				if (msg.x<_x2 && msg.x>_x1 && msg.y > _y1 && msg.y < _y2)
					//确保是在按钮里点击的
				{
					//Click = 0;
					if (Click == 1)
					{
						Click = 0;
					}
					else
					{
						Click = 1;
					}
				}
			}
		}
		
		

		
	}*/
	
	
		



	

	


}


void pauseButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[])
{
	button.x1 = _x1;
	button.x2 = _x2;
	button.y1 = _y1;
	button.y2 = _y2;
	setfillcolor(WHITE);
	fillrectangle(button.x1, button.y1, button.x2, button.y2);
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("华文新魏"));
	outtextxy(_x1 + 5, _y1 + 10, a);



	/*while (1)
	{
		if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
		{
			MOUSEMSG msg1 = GetMouseMsg();
			//判断是否是左键按下
			if (msg1.uMsg == WM_LBUTTONDOWN)
			{
				if (msg1.x<_x2 && msg1.x>_x1 && msg1.y > _y1 && msg1.y < _y2)
					//确保是在按钮里点击的
				{
					if (Action == 1)
					{
						Action = 0;
					}
					else
					{
						Action = 1;
					}
				}
			}
		}




	}*/

}

void pulsarButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color)
{
	button.x1 = _x1;
	button.x2 = _x2;
	button.y1 = _y1;
	button.y2 = _y2;
	setfillcolor(color);
	fillrectangle(button.x1, button.y1, button.x2, button.y2);
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("华文新魏"));
	outtextxy(_x1 + 5, _y1 + 5, a);
}

void gliderButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color)
{
	button.x1 = _x1;
	button.x2 = _x2;
	button.y1 = _y1;
	button.y2 = _y2;
	setfillcolor(color);
	fillrectangle(button.x1, button.y1, button.x2, button.y2);
	settextcolor(RED);
	//setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("华文新魏"));
	outtextxy(_x1 + 5, _y1 + 5, a);

}

void lightshipButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color)
{
	button.x1 = _x1;
	button.x2 = _x2;
	button.y1 = _y1;
	button.y2 = _y2;
	setfillcolor(color);
	fillrectangle(button.x1, button.y1, button.x2, button.y2);
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("华文新魏"));
	outtextxy(_x1 + 5, _y1 + 5, a);
}

void tumblerButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color)
{
	button.x1 = _x1;
	button.x2 = _x2;
	button.y1 = _y1;
	button.y2 = _y2;
	setfillcolor(color);
	fillrectangle(button.x1, button.y1, button.x2, button.y2);
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("华文新魏"));
	outtextxy(_x1 + 5, _y1 + 5, a);
}

void balanceButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color)
{
	button.x1 = _x1;
	button.x2 = _x2;
	button.y1 = _y1;
	button.y2 = _y2;
	setfillcolor(color);
	fillrectangle(button.x1, button.y1, button.x2, button.y2);
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("华文新魏"));
	outtextxy(_x1 + 5, _y1 + 5, a);
}


void setButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color)
{
	button.x1 = _x1;
	button.x2 = _x2;
	button.y1 = _y1;
	button.y2 = _y2;
	setfillcolor(color);
	fillrectangle(button.x1, button.y1, button.x2, button.y2);
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("华文新魏"));
	outtextxy(_x1 + 5, _y1 + 5, a);
}



Button button;
Button button1;
Button buttonp;
Button buttong;
Button buttonl;
Button buttont;
void function(int map[ROWS][COLS])
{
	while (1)
	{
		if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
		{

			MOUSEMSG msg1 = GetMouseMsg();
			//判断是否是左键按下



			if (msg1.uMsg == WM_LBUTTONDOWN)
			{
				if (msg1.x < 1080 && msg1.x>900 && msg1.y > 370 && msg1.y < 440)
					//确保是在按钮里点击的
				{
					if (Action == 1)
					{
						Action = 0;
						cout << "已暂停" << endl;
						cout << "暂停时进入自定义细胞生存状态模式，点击最右下角方块即可结束" << endl;


						while (1)
						{
							if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
							{

								MOUSEMSG msg = GetMouseMsg();
								//判断是否是左键按下



								if (msg.uMsg == WM_LBUTTONDOWN)
								{

									if (msg.x < 800)
									{
										int x, y;
										x = msg.x / SQUARE;
										y = msg.y / SQUARE;
										if (map[y][x] == 0)
										{
											map[y][x] = 1;
										}
										if (map[y][x] == 1)
										{
											map[y][x] = 0;
										}
										if (y == (ROWS - 1) && x == (COLS - 1))
										{
											break;
										}
										
									}
								}
							}
						}
					}

					else
					{
						Action = 1;
						cout << "已重新启动" << endl;
					}
				}
				if (msg1.x < 1080 && msg1.x>900 && msg1.y > 200 && msg1.y < 270)
					//确保是在按钮里点击的
				{
					if (Click == 1)
					{
						Click = 0;
					}
					else
					{
						Click = 1;
					}
				}
				if (msg1.x < 950 && msg1.x>850 && msg1.y > 530 && msg1.y < 570)
				{
					setlinecolor(YELLOW);
					rectangle(850, 530, 950, 570);
					//pulsarButton(buttonp, 850, 530, 950, 570, "脉冲星", LIGHTGRAY);

					while (1)
					{
						if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
						{

							MOUSEMSG msg = GetMouseMsg();
							//判断是否是左键按下
							if (msg.uMsg == WM_LBUTTONDOWN)
							{
								if (msg.x < 800)
								{
									int x, y;
									x = msg.x / SQUARE;
									y = msg.y / SQUARE;
									map[y][x] = 0;
									map[y][x - 1] = 0;
									map[y][x + 1] = 0;
									map[y - 1][x] = 0;
									map[y + 1][x] = 0;
									map[y - 1][x - 1] = 0;
									map[y - 1][x + 1] = 0;
									map[y + 1][x + 1] = 0;
									map[y + 1][x - 1] = 0;
									map[y - 1][x - 2] = 1;
									map[y - 1][x - 3] = 1;
									map[y - 1][x - 4] = 1;
									map[y - 1][x + 2] = 1;
									map[y - 1][x + 3] = 1;
									map[y - 1][x + 4] = 1;
									map[y + 1][x - 2] = 1;
									map[y + 1][x - 3] = 1;
									map[y + 1][x - 4] = 1;
									map[y + 1][x + 2] = 1;
									map[y + 1][x + 3] = 1;
									map[y + 1][x + 4] = 1;
									map[y - 2][x - 1] = 1;
									map[y - 2][x - 3] = 1;
									map[y - 2][x - 5] = 1;
									map[y - 2][x + 1] = 1;
									map[y - 2][x + 3] = 1;
									map[y - 2][x + 5] = 1;
									map[y + 2][x - 1] = 1;
									map[y + 2][x - 3] = 1;
									map[y + 2][x - 5] = 1;
									map[y + 2][x + 1] = 1;
									map[y + 2][x + 3] = 1;
									map[y + 2][x + 5] = 1;
									map[y - 3][x - 1] = 1;
									map[y - 3][x - 2] = 1;
									map[y - 3][x - 4] = 1;
									map[y - 3][x - 5] = 1;
									map[y - 3][x - 6] = 1;
									map[y - 3][x + 1] = 1;
									map[y - 3][x + 2] = 1;
									map[y - 3][x + 4] = 1;
									map[y - 3][x + 5] = 1;
									map[y - 3][x + 6] = 1;
									map[y + 3][x - 1] = 1;
									map[y + 3][x - 2] = 1;
									map[y + 3][x - 4] = 1;
									map[y + 3][x - 5] = 1;
									map[y + 3][x - 6] = 1;
									map[y + 3][x + 1] = 1;
									map[y + 3][x + 2] = 1;
									map[y + 3][x + 4] = 1;
									map[y + 3][x + 5] = 1;
									map[y + 3][x + 6] = 1;
									map[y - 4][x - 1] = 1;
									map[y - 4][x - 3] = 1;
									map[y - 4][x - 6] = 1;
									map[y - 4][x + 1] = 1;
									map[y - 4][x + 3] = 1;
									map[y - 4][x + 6] = 1;
									map[y + 4][x - 1] = 1;
									map[y + 4][x - 3] = 1;
									map[y + 4][x - 6] = 1;
									map[y + 4][x + 1] = 1;
									map[y + 4][x + 3] = 1;
									map[y + 4][x + 6] = 1;
									map[y - 5][x - 2] = 1;
									map[y - 5][x - 3] = 1;
									map[y - 5][x + 2] = 1;
									map[y - 5][x + 3] = 1;
									map[y + 5][x - 2] = 1;
									map[y + 5][x - 3] = 1;
									map[y + 5][x + 2] = 1;
									map[y + 5][x + 3] = 1;
									map[y - 6][x - 3] = 1;
									map[y - 6][x - 4] = 1;
									map[y - 6][x + 3] = 1;
									map[y - 6][x + 4] = 1;
									map[y + 6][x - 3] = 1;
									map[y + 6][x - 4] = 1;
									map[y + 6][x + 3] = 1;
									map[y + 6][x + 4] = 1;
									//pulsarButton(buttonp, 850, 530, 950, 570, "脉冲星", WHITE);
									setlinecolor(WHITE);
									rectangle(850, 530, 950, 570);
									break;
								}

							}
						}

					}




				}
				if (msg1.x < 1150 && msg1.x>1050 && msg1.y > 530 && msg1.y < 570)
				{
					setlinecolor(YELLOW);
					rectangle(1050, 530, 1150, 570);
					while (1)
					{
						if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
						{

							MOUSEMSG msg = GetMouseMsg();
							//判断是否是左键按下
							if (msg.uMsg == WM_LBUTTONDOWN)
							{
								if (msg.x < 800)
								{
									int x, y;
									x = msg.x / SQUARE;
									y = msg.y / SQUARE;
									map[y][x - 1] = 1;
									map[y][x + 1] = 1;
									map[y - 1][x + 1] = 1;
									map[y + 1][x] = 1;
									map[y + 1][x + 1] = 1;
									setlinecolor(WHITE);
									rectangle(1050, 530, 1150, 570);

									break;
								}

							}
						}

					}





				}
				if (msg1.x < 950 && msg1.x>850 && msg1.y > 660 && msg1.y < 700)
				{


					setlinecolor(YELLOW);
					rectangle(850, 660, 950, 700);
					//lightshipButton(buttonl, 850, 660, 950, 700, "轻飞船",LIGHTGRAY);

					while (1)
					{
						if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
						{

							MOUSEMSG msg = GetMouseMsg();
							//判断是否是左键按下
							if (msg.uMsg == WM_LBUTTONDOWN)
							{
								if (msg.x < 800)
								{
									int x, y;
									x = msg.x / SQUARE;
									y = msg.y / SQUARE;
									map[y][x - 1] = 1;
									map[y][x + 1] = 1;
									map[y][x - 2] = 1;
									map[y][x + 2] = 1;
									map[y - 1][x] = 1;
									map[y - 1][x - 1] = 1;
									map[y - 1][x - 2] = 1;
									map[y - 1][x + 1] = 1;
									map[y + 1][x] = 1;
									map[y + 1][x + 1] = 1;
									map[y - 2][x - 1] = 1;
									map[y - 2][x] = 1;
									setlinecolor(WHITE);
									rectangle(850, 660, 950, 700);
									//lightshipButton(buttonl, 850, 660, 950, 700, "轻飞船", WHITE);
									break;
								}

							}
						}

					}







				}
				if ((msg1.x < 1150 && msg1.x>1050 && msg1.y > 660 && msg1.y < 700))
				{





					setlinecolor(YELLOW);
					rectangle(1050, 660, 1150, 700);
					//tumblerButton(buttont, 1050, 660, 1150, 700, "不倒翁", LIGHTGRAY);
					while (1)
					{
						if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
						{

							MOUSEMSG msg = GetMouseMsg();
							//判断是否是左键按下
							if (msg.uMsg == WM_LBUTTONDOWN)
							{
								if (msg.x < 800)
								{
									int x, y;
									x = msg.x / SQUARE;
									y = msg.y / SQUARE;
									map[y][x - 2] = 1;
									map[y][x + 2] = 1;
									map[y][x - 2] = 1;
									map[y][x + 2] = 1;
									map[y + 1][x - 1] = 1;
									map[y + 1][x - 2] = 1;
									map[y + 1][x + 1] = 1;
									map[y + 1][x + 2] = 1;
									map[y - 1][x - 1] = 1;
									map[y - 1][x + 1] = 1;
									map[y - 1][x - 4] = 1;
									map[y - 1][x + 4] = 1;
									map[y - 2][x - 2] = 1;
									map[y - 2][x + 2] = 1;
									map[y - 2][x - 4] = 1;
									map[y - 2][x + 4] = 1;
									map[y - 3][x + 3] = 1;
									map[y - 3][x - 3] = 1;


									setlinecolor(WHITE);
									rectangle(1050, 660, 1150, 700);
									//tumblerButton(buttont, 1050, 660, 1150, 700, "不倒翁", WHITE);
									break;
								}

							}
						}

					}








				}
				if ((msg1.x < 1050 && msg1.x>950 && msg1.y > 595 && msg1.y < 635))
				{
					setlinecolor(YELLOW);
					rectangle(950, 595, 1050, 635);
					while (1)
					{
						if (MouseHit())//如果存在鼠标消息，返回 true；否则返回 false
						{

							MOUSEMSG msg = GetMouseMsg();
							//判断是否是左键按下
							if (msg.uMsg == WM_LBUTTONDOWN)
							{
								if (msg.x < 800)
								{
									int x, y;
									x = msg.x / SQUARE;
									y = msg.y / SQUARE;
									map[y + 1][x] = 1;
									map[y + 2][x] = 1;
									map[y + 2][x - 1] = 1;
									map[y + 3][x - 1] = 1;
									map[y + 3][x + 1] = 1;
									map[y - 1][x] = 1;
									map[y - 2][x] = 1;
									map[y - 1][x - 1] = 1;
									map[y - 2][x - 1] = 1;
									setlinecolor(WHITE);
									rectangle(950, 595, 1050, 635);
									break;
								}
							}
						}
					}
				}
				if ((msg1.x < 930 && msg1.x>850 && msg1.y > 50 && msg1.y < 90))
				{
					// 保存数组到文件
					saveArrayToFile(map, 80, 80, "array_data.txt");
				}
				if ((msg1.x < 1150 && msg1.x>1070 && msg1.y > 50 && msg1.y < 90))
				{
					// 从文件中加载数组
					loadArrayFromFile(map, 80, 80, "array_data.txt");

					// 打印数组
					printArray(map, 80, 80);
				}
				if ((msg1.x < 930 && msg1.x>850 && msg1.y > 100 && msg1.y < 140))
				{
					cout << "请输入要改变成的速度（毫秒），细胞将以这个速度刷新" << endl;
					int a;

					if (cin >> a)
					{
						velocity = a;
					}
					else {
						std::cout << "输入不是整型数字" << std::endl;
						std::cin.clear();
						std::string invalidInput;
						std::cin >> invalidInput; // 忽略无效输入
					}

				}
				if ((msg1.x < 1150 && msg1.x>1070 && msg1.y > 100 && msg1.y < 140))
				{
					cout << "请输入要将细胞改变成什么颜色：1.绿色；2.红色；3.蓝色；4.黄色；5.青色；6.洋红色;7.自定义" << endl;
					enum COLORS color;
					cin >> (int&)color;
					switch (color)
					{

					case red:
						_cellcolor = RED;
						break;
					case green:
						_cellcolor = GREEN;
						break;
					case blue:
						_cellcolor = BLUE;
						break;
					case yellow:
						_cellcolor = YELLOW;
						break;
					case cyan:
						_cellcolor = CYAN;
						break;
					case magenta:
						_cellcolor = MAGENTA;
						break;
					case customization:
						cout << "请输入自定义RGB的三值（数字范围为0~255）" << endl;
						int c1, c2, c3;
						if (cin >> c1 >> c2 >> c3 && 0 <= c1 <= 255 && 0 <= c2 <= 255 && 0 <= c3 <= 255)
						{
							_cellcolor = RGB(c1, c2, c3);
						}
						else
						{
							cout << "输入无效" << endl;
						}
						break;

					default:



						std::cout << "输入的是未记录的颜色" << std::endl;
						std::cin.clear();
						std::string invalidInput;
						std::cin >> invalidInput; // 忽略无效输入
					}

				}


			}
			
		}


	}
}


void saveArrayToFile(const int array[][80], int rows, int columns, const string& filename) {
	ofstream file(filename);
	if (file.is_open()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				file << array[i][j] << " ";
			}
			file << "\n";
		}
		file.close();
		cout << "已经成功保存" << endl;
	}
	else {
		cout << "保存失败" << endl;
	}
}



void loadArrayFromFile(int array[][80], int rows, int columns, const string& filename) {
	ifstream file(filename);
	if (file.is_open()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				file >> array[i][j];
			}
		}
		file.close();
		cout << "读取成功" << endl;
	}
	else {
		cout << "读取失败" << endl;
	}
}



void printArray(const int array[][80], int rows, int columns) {
	// 计算每个数据的宽度
	int dataWidth = 1.6; // 包括空格在内的每个数据宽度

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (array[i][j] == 0) {
				cout << setw(dataWidth) << " ";
			}
			 if (array[i][j] == 1) {
				cout << setw(dataWidth) << "*";
			}
		
		if ((j + 1) % 80 == 0) 
			cout << endl;
		}
		
	}
}