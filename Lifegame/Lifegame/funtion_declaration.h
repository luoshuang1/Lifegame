#pragma once
#ifndef _FUNTION_DECLARATION_H_
#define _FUNTION_DECLARATION_H_
#include"Tape.h"
#include<string>
using namespace std;//string引发未标识问题

/*#pragma once是一种预处理指令，用于确保头文件（header file）只被编译一次。它是一种非标准的编译器指令，但在大多数主流编译器中都得到了支持。

当一个头文件被包含多次时，传统的处理方式是使用条件编译指令，例如#ifndef、#define和#endif来避免重复包含。这样做可以确保头文件只被编译一次，以避免重复定义或引起其他编译错误。

而#pragma once指令提供了一种更简洁的方式来实现相同的效果，它告诉编译器只包含一次该头文件，无论它被多次包含。使用#pragma once可以减少编写条件编译指令的工作量，并且更加清晰简洁。*/


#define SQUARE 10//一个格子的宽高
#define COLS 80
//纵向格子数
#define ROWS 80
//横向格子数
#define ADD 40
//额外设置供操作的用户界面窗口


//画格子，x，y为格子左上角坐标，state标记状态
//1为存活，0为死亡
void draw(int x, int y, int state, COLORREF cellcolor = WHITE);

//画整个界面
void drawmap(int map[ROWS][COLS], COLORREF cellcolor1 = WHITE);
//根据鼠标输入来设置格子存活状态
void getAndSet(int map[ROWS][COLS]);

//进行演化
void lifeWeek(int map[ROWS][COLS]);

//获取地图中某个点周围存活点的数量并返回
int getPoint(int map[ROWS][COLS], int x, int y);

//创建一个按钮用于交互
void setButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[]);
/*在Windows上，TCHAR是一个宏定义，它根据编译选项的设置，在不同的编译环境下会被替换为char或wchar_t。这样做可以使代码在不同的编译环境中具有更好的可移植性。*/


//创建一个暂停按钮
void pauseButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[]);

//脉冲星按钮
void pulsarButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[],COLORREF color);

//滑翔者按钮
void gliderButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);

//轻量级飞船按钮
void lightshipButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);


//不倒翁按钮
void tumblerButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);

//均衡者按钮
void balanceButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);



//保存和查看按钮
void setButton(Button& button, int _x1, int _y1, int _x2, int _y2, const char a[], COLORREF color);


//实现倍速演化功能
void function(int map[ROWS][COLS]);


//保存二维数组到文件中
void saveArrayToFile(const int array[][80], int rows, int columns, const string& filename);


//从文件中加载数组
void loadArrayFromFile(int array[][80], int rows, int columns, const string& filename);


//打印数组，将保存的结果呈现
void printArray(const int array[][80], int rows, int columns);





#endif