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
	COLORREF colorback;//��ť��ɫ
	COLORREF colorword;//������ɫ
	COLORREF colorline;//�߿���ɫ
	COLORREF record = colorline;
	LPCTSTR lpszFace;//��������
	string a;//��ť����
	

public:
	Buttons(int _x1, int _y1, int _x2, int _y2, COLORREF colorback, COLORREF colorword, COLORREF colorline,string a);
	void setrectangle(int hight);
	void changecolorback(COLORREF new_colorback);
	void changecolorword(COLORREF new_colorline);
	void changecolorline(COLORREF new_colorline);
	void click();//���֮��ı仯
	void offclick();//��ť������ɺ�ı仯
	void sureclick();
	~Buttons();
};

#endif