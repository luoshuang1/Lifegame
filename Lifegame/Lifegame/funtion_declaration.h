#pragma once
#ifndef _FUNTION_DECLARATION_H_
#define _FUNTION_DECLARATION_H_
#include"Tape.h"
#include<string>
using namespace std;//string����δ��ʶ����

/*#pragma once��һ��Ԥ����ָ�����ȷ��ͷ�ļ���header file��ֻ������һ�Ρ�����һ�ַǱ�׼�ı�����ָ����ڴ���������������ж��õ���֧�֡�

��һ��ͷ�ļ����������ʱ����ͳ�Ĵ���ʽ��ʹ����������ָ�����#ifndef��#define��#endif�������ظ�����������������ȷ��ͷ�ļ�ֻ������һ�Σ��Ա����ظ���������������������

��#pragma onceָ���ṩ��һ�ָ����ķ�ʽ��ʵ����ͬ��Ч���������߱�����ֻ����һ�θ�ͷ�ļ�������������ΰ�����ʹ��#pragma once���Լ��ٱ�д��������ָ��Ĺ����������Ҹ���������ࡣ*/


#define SQUARE 10//һ�����ӵĿ��
#define COLS 80
//���������
#define ROWS 80
//���������
#define ADD 40
//�������ù��������û����洰��


//�����ӣ�x��yΪ�������Ͻ����꣬state���״̬
//1Ϊ��0Ϊ����
void draw(int x, int y, int state, COLORREF cellcolor = WHITE);

//����������
void drawmap(int map[ROWS][COLS], COLORREF cellcolor1 = WHITE);
//����������������ø��Ӵ��״̬
void getAndSet(int map[ROWS][COLS]);

//�����ݻ�
void lifeWeek(int map[ROWS][COLS]);

//��ȡ��ͼ��ĳ������Χ���������������
int getPoint(int map[ROWS][COLS], int x, int y);

//����һ����ť���ڽ���
void setButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[]);
/*��Windows�ϣ�TCHAR��һ���궨�壬�����ݱ���ѡ������ã��ڲ�ͬ�ı��뻷���»ᱻ�滻Ϊchar��wchar_t������������ʹ�����ڲ�ͬ�ı��뻷���о��и��õĿ���ֲ�ԡ�*/


//����һ����ͣ��ť
void pauseButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[]);

//�����ǰ�ť
void pulsarButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[],COLORREF color);

//�����߰�ť
void gliderButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);

//�������ɴ���ť
void lightshipButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);


//�����̰�ť
void tumblerButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);

//�����߰�ť
void balanceButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);



//����Ͳ鿴��ť
void setButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);


//ʵ�ֱ����ݻ�����
void function(int map[ROWS][COLS]);


//�����ά���鵽�ļ���
void saveArrayToFile(const int array[][80], int rows, int columns, const string& filename);


//���ļ��м�������
void loadArrayFromFile(int array[][80], int rows, int columns, const string& filename);


//��ӡ���飬������Ľ������
void printArray(const int array[][80], int rows, int columns);





#endif