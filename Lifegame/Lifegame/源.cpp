#include<iostream>
#include<string.h>
#include<conio.h>//使用getch函数
#include<string>
#include<vector>
#include <random>
#include<graphics.h>//easyx的库
#include"funtion_declaration.h"
#include"Tape.h"
#include"User.h"
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

extern COLORREF _cellcolor;
extern int Continue;
extern bool Click;
extern bool Action;
int velocity = 300;
using namespace std;

int main()
{
	// 1:先制作一个窗口
	initgraph(SQUARE*(COLS+ADD), SQUARE * ROWS);//以像素为单位，创建一个窗口，左边为宽，右边为高,第三个参数为同时两个窗口


//登录功能
vector<User> users;

string choice;
while (true) {
	cout << "Choose an option - Register (R), Login (L),Delete(D), View All (V): ";
	cin >> choice;

	if (choice == "R" || choice == "r") {
		string username, password, confirm_password;
		cout << "Enter username: ";
		cin >> username;
		if (User::exists(username)) {
			cout << "Username already exists" << endl;
		}
		else {
			cout << "Enter password: ";
			password = "";
			char ch;
			while ((ch = _getch()) != '\r') {
				if (ch == '\b') {
					if (!password.empty()) {
						cout << "\b \b";
						password.pop_back();
					}
				}
				else {
					cout << '*';
					password.push_back(ch);
				}
			}
			cout << endl;

			cout << "Confirm password: ";
			confirm_password = "";
			while ((ch = _getch()) != '\r') {
				if (ch == '\b') {
					if (!confirm_password.empty()) {
						cout << "\b \b";
						confirm_password.pop_back();
					}
				}
				else {
					cout << '*';
					confirm_password.push_back(ch);
				}
			}
			cout << endl;

			if (password == confirm_password) {
				User user;
				user.username = username;
				user.password = password;
				user.save();
				users.push_back(user);
				cout << "Registration successful" << endl;
			}
			else {
				cout << "Passwords do not match. Registration failed." << endl;
			}
		}
	}
	else if (choice == "L" || choice == "l") {
		string username, password;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		password = "";
		char ch;
		while ((ch = _getch()) != '\r') {
			if (ch == '\b') {
				if (!password.empty()) {
					cout << "\b \b";
					password.pop_back();
				}
			}
			else {
				cout << '*';
				password.push_back(ch);
			}
		}
		cout << endl;

		if (User::login(username, password)) {
			cout << "Login successful" << endl;
			break;
		}
		else {
			cout << "Invalid username or password" << endl;
		}
	}
	else if (choice == "D" || choice == "d")
	{
		std::string username;
		std::cout << "Enter username to delete: ";
		std::cin >> username;
		if (User::remove(username)) {
			std::cout << "User " << username << " has been deleted" << std::endl;
		}
		else {
			std::cout << "User " << username << " does not exist" << std::endl;
		}
	}
	else if (choice == "V" || choice == "v")
	{
	
	User::viewAll();  // 调用查看方法
	}
	else 
	{
		cout << "Invalid choice" << endl;
	}
}



//展示图片
	IMAGE picture;//展示图片
	loadimage(&picture, "images.jpg", 1200, 800);
	putimage(0, 0, &picture);
	Sleep(5000);
	cleardevice();


	//2:介绍游戏规则
	char rules[12][200] = {"欢迎来到_生命游戏！",//0
		"1：人口过少，离群：",//1
		"如果一个活细胞少于两个活的邻居，",//2
		"它就会死亡。",//3
		
		"2：正常：",//4
		"一个有两个或三个活邻居的活细胞,",//5
		"可以延续到下一代。",//6
		
		"3：人口过多，过度竞争：",//7
		"一个有超过三个活邻居的活细胞死亡。",//8
		
		"4:繁衍：",//9
		"如果一个死细胞正好有三个活着的邻居，",//10
		"它就会复活。"//11
	};
	

	settextcolor(RED);//设置字体颜色
	settextstyle(40, 0, _T("华文新魏"));//设置字体高度和样式
	outtextxy(100, 100, rules[0]);
	//函数三个参数，字符串输出时头字母的 x 轴的坐标值,y轴的值，字符串
	string _sureclick = "确认";
	char* sureclicka = &_sureclick[0];
	Buttons sureclick(1000, 650, 1100, 700, WHITE, RED, WHITE, sureclicka);
	sureclick.setrectangle(40);
	sureclick.sureclick();
	//Sleep(2000);
	clearrectangle(0, 0, 1200, 640);// 这个函数用于清空矩形区域
	outtextxy(50, 100, rules[1]);
	outtextxy(50, 200, rules[2]);
	outtextxy(50, 300, rules[3]);
	sureclick.sureclick();
	//Sleep(2000);
	clearrectangle(0, 0, 1200, 640);// 这个函数用于清空矩形区域
	outtextxy(50, 100, rules[4]);
	outtextxy(50, 200, rules[5]);
	outtextxy(50, 300, rules[6]);
	//Sleep(2000);
	sureclick.sureclick();
	clearrectangle(0, 0, 1200, 640);// 这个函数用于清空矩形区域
	outtextxy(50, 200, rules[7]);
	outtextxy(50, 300, rules[8]);
	//Sleep(2000);
	sureclick.sureclick();
	clearrectangle(0, 0, 1200, 640);// 这个函数用于清空矩形区域
	outtextxy(50, 100, rules[9]);
	outtextxy(50, 200, rules[10]);
    outtextxy(50, 300, rules[11]);
	//Sleep(2000);
	sureclick.sureclick();
	clearrectangle(0, 0, 1200, 640);// 这个函数用于清空矩形区域
	cleardevice();//清屏

	


	//描述格子状态，并全初始化为不存活
	int map[ROWS][COLS] = { 0 };
	

	settextcolor(YELLOW);//设置字体颜色
	settextstyle(60, 0, _T("华文新魏"));//设置字体高度和样式
	string modechoice = "请选择模式";
	char* pmodechoice = &modechoice[0];
	outtextxy(450, 100, pmodechoice);
	Buttons select_random(410, 400, 790, 560, WHITE, RED, RED, "随机模式");
	select_random.setrectangle(90);
	Buttons select_handon(410, 600, 790, 760, WHITE, RED, RED, "手绘模式");
	select_handon.setrectangle(90);
	while (1)
	{
		MOUSEMSG msg_;
		msg_ = GetMouseMsg();
		//这个函数用于获取一个鼠标消息。如果当前鼠标消息队列中没有，就一直等待。
		int _x, _y;
		//_x = msg_.x / SQUARE;
		//_y = msg_.y / SQUARE;
		_x = msg_.x ;
		_y = msg_.y;
		if (msg_.mkLButton)//左键点击
		{
			if (_x < 790 && _x>410 && _y > 400 && _y < 560)//在随机区域内
			{
				// 创建一个随机数引擎
				random_device rd;
				mt19937 generator(rd());

				// 定义随机数分布
				uniform_int_distribution<int> distribution(1, 80); // 生成1到80之间的整数
				uniform_int_distribution<int> shu(1000, 6000);

				// 生成一连串随机数

				for (int i = 0; i < shu(generator); ++i) {
					map[distribution(generator)][distribution(generator)] = 1;

				}
				cleardevice();
				break;
			}
			if (_x < 790 && _x>410 && _y > 600 && _y < 760)
			{
				CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)getAndSet, (LPVOID)map, NULL, NULL);
				//创建一个线程
				while (Continue)
				{
					drawmap(map);
				}
				cleardevice();
				break;
			}

		}
	}


	//音乐播放
	
	//播放音乐
	mciSendString("open mp3.mp3", NULL, NULL, NULL);
	mciSendString("play mp3.mp3 repeat", NULL, NULL, NULL);//repeat为循环播放指令

	Button button;
	Button button1;
	Button buttonp;
	Button buttong;
	Button buttonl;
	Button buttont;
	Button buttonb;
	Button savebutton;
	Button readbutton;
	Button veliocitybutton;
	Button cellcolorbutton;
	setButton(button, 900, 200, 1080, 270,"倍速演化");
	pauseButton(button1, 900, 370, 1080, 440, "暂停/恢复");
	pulsarButton(buttonp, 850, 530, 950, 570, "脉冲星", WHITE);
	gliderButton(buttong, 1050, 530, 1150, 570, "滑翔者", WHITE);
	lightshipButton(buttonl, 850, 660, 950, 700, "轻飞船", WHITE);
	tumblerButton(buttont, 1050, 660, 1150, 700, "不倒翁", WHITE);
	balanceButton(buttonb, 950, 595, 1050, 635, "均衡者", WHITE);
	setButton(savebutton, 850, 50, 930, 90, "保存", WHITE);
	setButton(readbutton, 1070, 50, 1150, 90, "查看", WHITE);
	setButton(veliocitybutton, 850, 100, 930, 140, "控速", WHITE);
	setButton(cellcolorbutton, 1070, 100, 1150, 140, "控色", WHITE);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)function, (LPVOID)map, NULL, NULL);


	
	//演化
	while (1)
	{
		
		switch (Action)
		{
		case 1:
		
			while (Action)
			{
				switch (Click)
				{
				case 1:
					while (Click&&Action)
					{
						lifeWeek(map);
						drawmap(map, _cellcolor);
						
						Sleep(velocity);
						
					}
					break;

				case 0:
					while (!Click&&Action)
					{
						lifeWeek(map);
						drawmap(map, _cellcolor);
						Sleep(10);
						
					}
					break;

				}
			}
			break;

		

		case 0:
		
			while (!Action);
			
				
			
			
			break;
		
		}
	}
		

	
	
	
		
	


		

		
	while (1);
	return 0;
}

