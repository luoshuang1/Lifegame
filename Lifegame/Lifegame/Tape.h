#pragma once
#ifndef _TAPE_H
#define _TAPE_H
#include<string>
#include <graphics.h>
using namespace std;

struct Button
{
	int x1;
	int y1;
	int x2;
	int y2;
};








class Buttons
{
private:
	int x1;
	int y1;
	int x2;
	int y2;
	COLORREF colorback;//按钮颜色
	COLORREF colorword;//字体颜色
	COLORREF colorline;//边框颜色
	COLORREF record = colorline;
	LPCTSTR lpszFace;//字体名称
	string a;//按钮文字
	

public:
	Buttons(int _x1, int _y1, int _x2, int _y2, COLORREF colorback, COLORREF colorword, COLORREF colorline,string a);
	void setrectangle(int hight);
	void changecolorback(COLORREF new_colorback);
	void changecolorword(COLORREF new_colorline);
	void changecolorline(COLORREF new_colorline);
	void click();//点击之后的变化
	void offclick();//按钮功能完成后的变化
	void sureclick();
	~Buttons();
};

#endif