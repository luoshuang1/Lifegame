#include<iostream>
#include<string.h>
#include <iomanip>
#include<graphics.h>//easyx�Ŀ�
#include"funtion_declaration.h"
#include"Tape.h"
#include<string>
#include<fstream>
#include<conio.h>
//#include <cctype>
using namespace std;

//mciSendString��Ҫ��ͷ�ļ�

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define SQUARE 10//һ�����ӵĿ��
#define COLS 80
//���������
#define ROWS 80
//���������
#define ADD 40
//�������ù��������û����洰��






enum COLORS{green=1,red,blue,yellow,cyan,magenta,customization};//��ɫ��Cyan;���ɫ��Magenta


COLORREF _cellcolor = WHITE;

extern int velocity;
int Continue = 1;//����ȫ�ֱ���
bool Click = true;
bool Action = true;
int scount = 0;//��¼�Ѿ�ע����û���
void draw(int x, int y, int state, COLORREF cellcolor)
{
	//�߿����ɫ
	setcolor(RGB(167, 167, 167));
	/*RGB(167, 167, 167)������ǻ�ɫ����RGB��ɫģ���У�ÿ����ɫͨ����ȡֵ��Χ��0��255�����к�ɫ��R������ɫ��G������ɫ��B���ֱ��Ӧ����ͨ������������ͨ����ȡֵ���ʱ���ͻ�õ�һ�ֻ�ɫ*/
	if (state == 1)
	{
		setfillcolor(cellcolor);
	}//�����ɫ
	else
	{
		setfillcolor(BLACK);
	}

	//�����Σ��ĸ�����Ϊ���Ͻ���������½�����
	fillrectangle(x, y, x + SQUARE, y + SQUARE);
}

//����������
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
//����������������ø��Ӵ��״̬
void getAndSet(int map[ROWS][COLS])
{
	cout << "�滭�������������½Ƿ��鼴�ɽ����ݱ�" << endl;
	MOUSEMSG msg;
	int x, y;
	/*MOUSEMSG��EasyXͼ�ο��е�һ���ṹ�����ͣ��������������Ϣ���ýṹ�����������¼������͡��������Ϣ���Ա������Զ�����¼�������Ӧ�ʹ���*/
	while (Continue)
	{
		msg = GetMouseMsg();
		//����������ڻ�ȡһ�������Ϣ�������ǰ�����Ϣ������û�У���һֱ�ȴ���
		x = msg.x / SQUARE;
		y = msg.y / SQUARE;
		if (msg.mkLButton)//���������
		{
			map[y][x] = 1;//ע�⵽x�Ǻ�����row
			//���ý�������
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
	settextstyle(40, 0, _T("������κ"));
	outtextxy(_x1+5, _y1+10, a);
	
	//���ð�ť����꽻��
	
	/*while (1)
	{
		if (MouseHit())//������������Ϣ������ true�����򷵻� false
		{
			MOUSEMSG msg = GetMouseMsg();
			//�ж��Ƿ����������
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				if (msg.x<_x2 && msg.x>_x1 && msg.y > _y1 && msg.y < _y2)
					//ȷ�����ڰ�ť������
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
	settextstyle(40, 0, _T("������κ"));
	outtextxy(_x1 + 5, _y1 + 10, a);



	/*while (1)
	{
		if (MouseHit())//������������Ϣ������ true�����򷵻� false
		{
			MOUSEMSG msg1 = GetMouseMsg();
			//�ж��Ƿ����������
			if (msg1.uMsg == WM_LBUTTONDOWN)
			{
				if (msg1.x<_x2 && msg1.x>_x1 && msg1.y > _y1 && msg1.y < _y2)
					//ȷ�����ڰ�ť������
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
	settextstyle(30, 0, _T("������κ"));
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
	settextstyle(30, 0, _T("������κ"));
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
	settextstyle(30, 0, _T("������κ"));
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
	settextstyle(30, 0, _T("������κ"));
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
	settextstyle(30, 0, _T("������κ"));
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
	settextstyle(30, 0, _T("������κ"));
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
		if (MouseHit())//������������Ϣ������ true�����򷵻� false
		{

			MOUSEMSG msg1 = GetMouseMsg();
			//�ж��Ƿ����������



			if (msg1.uMsg == WM_LBUTTONDOWN)
			{
				if (msg1.x < 1080 && msg1.x>900 && msg1.y > 370 && msg1.y < 440)
					//ȷ�����ڰ�ť������
				{
					if (Action == 1)
					{
						Action = 0;
						cout << "����ͣ" << endl;
						cout << "��ͣʱ�����Զ���ϸ������״̬ģʽ����������½Ƿ��鼴�ɽ���" << endl;


						while (1)
						{
							if (MouseHit())//������������Ϣ������ true�����򷵻� false
							{

								MOUSEMSG msg = GetMouseMsg();
								//�ж��Ƿ����������



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
						cout << "����������" << endl;
					}
				}
				if (msg1.x < 1080 && msg1.x>900 && msg1.y > 200 && msg1.y < 270)
					//ȷ�����ڰ�ť������
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
					//pulsarButton(buttonp, 850, 530, 950, 570, "������", LIGHTGRAY);

					while (1)
					{
						if (MouseHit())//������������Ϣ������ true�����򷵻� false
						{

							MOUSEMSG msg = GetMouseMsg();
							//�ж��Ƿ����������
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
									//pulsarButton(buttonp, 850, 530, 950, 570, "������", WHITE);
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
						if (MouseHit())//������������Ϣ������ true�����򷵻� false
						{

							MOUSEMSG msg = GetMouseMsg();
							//�ж��Ƿ����������
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
					//lightshipButton(buttonl, 850, 660, 950, 700, "��ɴ�",LIGHTGRAY);

					while (1)
					{
						if (MouseHit())//������������Ϣ������ true�����򷵻� false
						{

							MOUSEMSG msg = GetMouseMsg();
							//�ж��Ƿ����������
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
									//lightshipButton(buttonl, 850, 660, 950, 700, "��ɴ�", WHITE);
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
					//tumblerButton(buttont, 1050, 660, 1150, 700, "������", LIGHTGRAY);
					while (1)
					{
						if (MouseHit())//������������Ϣ������ true�����򷵻� false
						{

							MOUSEMSG msg = GetMouseMsg();
							//�ж��Ƿ����������
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
									//tumblerButton(buttont, 1050, 660, 1150, 700, "������", WHITE);
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
						if (MouseHit())//������������Ϣ������ true�����򷵻� false
						{

							MOUSEMSG msg = GetMouseMsg();
							//�ж��Ƿ����������
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
					// �������鵽�ļ�
					saveArrayToFile(map, 80, 80, "array_data.txt");
				}
				if ((msg1.x < 1150 && msg1.x>1070 && msg1.y > 50 && msg1.y < 90))
				{
					// ���ļ��м�������
					loadArrayFromFile(map, 80, 80, "array_data.txt");

					// ��ӡ����
					printArray(map, 80, 80);
				}
				if ((msg1.x < 930 && msg1.x>850 && msg1.y > 100 && msg1.y < 140))
				{
					cout << "������Ҫ�ı�ɵ��ٶȣ����룩��ϸ����������ٶ�ˢ��" << endl;
					int a;

					if (cin >> a)
					{
						velocity = a;
					}
					else {
						std::cout << "���벻����������" << std::endl;
						std::cin.clear();
						std::string invalidInput;
						std::cin >> invalidInput; // ������Ч����
					}

				}
				if ((msg1.x < 1150 && msg1.x>1070 && msg1.y > 100 && msg1.y < 140))
				{
					cout << "������Ҫ��ϸ���ı��ʲô��ɫ��1.��ɫ��2.��ɫ��3.��ɫ��4.��ɫ��5.��ɫ��6.���ɫ;7.�Զ���" << endl;
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
						cout << "�������Զ���RGB����ֵ�����ַ�ΧΪ0~255��" << endl;
						int c1, c2, c3;
						if (cin >> c1 >> c2 >> c3 && 0 <= c1 <= 255 && 0 <= c2 <= 255 && 0 <= c3 <= 255)
						{
							_cellcolor = RGB(c1, c2, c3);
						}
						else
						{
							cout << "������Ч" << endl;
						}
						break;

					default:



						std::cout << "�������δ��¼����ɫ" << std::endl;
						std::cin.clear();
						std::string invalidInput;
						std::cin >> invalidInput; // ������Ч����
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
		cout << "�Ѿ��ɹ�����" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
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
		cout << "��ȡ�ɹ�" << endl;
	}
	else {
		cout << "��ȡʧ��" << endl;
	}
}



void printArray(const int array[][80], int rows, int columns) {
	// ����ÿ�����ݵĿ��
	int dataWidth = 1.6; // �����ո����ڵ�ÿ�����ݿ��

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