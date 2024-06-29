#include"Tape.h"

Buttons::Buttons(int _x1, int _y1, int _x2, int _y2, COLORREF colorback, COLORREF colorword
, COLORREF colorline, string a) :x1(_x1), y1(_y1), x2(_x2), y2(_y2), colorback(colorback), colorword(colorword), colorline(colorline), a(a)
{}

Buttons::~Buttons()
{

}

void Buttons::setrectangle(int hight)
{
	
	setlinecolor(colorline); // 设置边框颜色
	
	
	rectangle(x1, y1, x2, y2);
	
	setfillcolor(colorback);
	fillrectangle(x1, y1, x2, y2);
	settextcolor(colorword);
	setbkmode(TRANSPARENT);
	settextstyle(hight, 0, _T("华文新魏"));
	char* pt = &a[0];
	outtextxy(x1 +10, y1 + 10, pt);

}

void Buttons::changecolorback(COLORREF new_colorback)
{
	colorback = new_colorback;
	clearrectangle(x1, y1, x2, y2);
	setrectangle(90);

}

void Buttons::changecolorword(COLORREF new_colorword)
{
	colorword = new_colorword;
	clearrectangle(x1, y1, x2, y2);
	setrectangle(90);
}

void Buttons::changecolorline(COLORREF new_colorline)
{
	colorline = new_colorline;
	clearrectangle(x1, y1, x2, y2);
	setrectangle(90);
}

void Buttons::click()
{
	changecolorline(colorback);
}

void Buttons::offclick()
{
	changecolorline(record);
}

void Buttons::sureclick()
{
	while (1)
	{
		MOUSEMSG msga;
		msga = GetMouseMsg();
		//这个函数用于获取一个鼠标消息。如果当前鼠标消息队列中没有，就一直等待。
		int x1, y1;
		//_x = msg_.x / SQUARE;
		//_y = msg_.y / SQUARE;
		x1 = msga.x;
		y1 = msga.y;
		if (msga.mkLButton)//左键点击
		{
			if (x1 < 1100 && x1>1000 && y1 > 650 && y1 < 700)//在随机区域内
			{
				break;
			}
		}
	}
}