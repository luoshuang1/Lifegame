#include<iostream>
#include<string.h>
#include<conio.h>//ʹ��getch����
#include<string>
#include<vector>
#include <random>
#include<graphics.h>//easyx�Ŀ�
#include"funtion_declaration.h"
#include"Tape.h"
#include"User.h"
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

extern COLORREF _cellcolor;
extern int Continue;
extern bool Click;
extern bool Action;
int velocity = 300;
using namespace std;

int main()
{
	// 1:������һ������
	initgraph(SQUARE*(COLS+ADD), SQUARE * ROWS);//������Ϊ��λ������һ�����ڣ����Ϊ���ұ�Ϊ��,����������Ϊͬʱ��������


//��¼����
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
	
	User::viewAll();  // ���ò鿴����
	}
	else 
	{
		cout << "Invalid choice" << endl;
	}
}



//չʾͼƬ
	IMAGE picture;//չʾͼƬ
	loadimage(&picture, "images.jpg", 1200, 800);
	putimage(0, 0, &picture);
	Sleep(5000);
	cleardevice();


	//2:������Ϸ����
	char rules[12][200] = {"��ӭ����_������Ϸ��",//0
		"1���˿ڹ��٣���Ⱥ��",//1
		"���һ����ϸ��������������ھӣ�",//2
		"���ͻ�������",//3
		
		"2��������",//4
		"һ�����������������ھӵĻ�ϸ��,",//5
		"������������һ����",//6
		
		"3���˿ڹ��࣬���Ⱦ�����",//7
		"һ���г����������ھӵĻ�ϸ��������",//8
		
		"4:���ܣ�",//9
		"���һ����ϸ���������������ŵ��ھӣ�",//10
		"���ͻḴ�"//11
	};
	

	settextcolor(RED);//����������ɫ
	settextstyle(40, 0, _T("������κ"));//��������߶Ⱥ���ʽ
	outtextxy(100, 100, rules[0]);
	//���������������ַ������ʱͷ��ĸ�� x �������ֵ,y���ֵ���ַ���
	string _sureclick = "ȷ��";
	char* sureclicka = &_sureclick[0];
	Buttons sureclick(1000, 650, 1100, 700, WHITE, RED, WHITE, sureclicka);
	sureclick.setrectangle(40);
	sureclick.sureclick();
	//Sleep(2000);
	clearrectangle(0, 0, 1200, 640);// �������������վ�������
	outtextxy(50, 100, rules[1]);
	outtextxy(50, 200, rules[2]);
	outtextxy(50, 300, rules[3]);
	sureclick.sureclick();
	//Sleep(2000);
	clearrectangle(0, 0, 1200, 640);// �������������վ�������
	outtextxy(50, 100, rules[4]);
	outtextxy(50, 200, rules[5]);
	outtextxy(50, 300, rules[6]);
	//Sleep(2000);
	sureclick.sureclick();
	clearrectangle(0, 0, 1200, 640);// �������������վ�������
	outtextxy(50, 200, rules[7]);
	outtextxy(50, 300, rules[8]);
	//Sleep(2000);
	sureclick.sureclick();
	clearrectangle(0, 0, 1200, 640);// �������������վ�������
	outtextxy(50, 100, rules[9]);
	outtextxy(50, 200, rules[10]);
    outtextxy(50, 300, rules[11]);
	//Sleep(2000);
	sureclick.sureclick();
	clearrectangle(0, 0, 1200, 640);// �������������վ�������
	cleardevice();//����

	


	//��������״̬����ȫ��ʼ��Ϊ�����
	int map[ROWS][COLS] = { 0 };
	

	settextcolor(YELLOW);//����������ɫ
	settextstyle(60, 0, _T("������κ"));//��������߶Ⱥ���ʽ
	string modechoice = "��ѡ��ģʽ";
	char* pmodechoice = &modechoice[0];
	outtextxy(450, 100, pmodechoice);
	Buttons select_random(410, 400, 790, 560, WHITE, RED, RED, "���ģʽ");
	select_random.setrectangle(90);
	Buttons select_handon(410, 600, 790, 760, WHITE, RED, RED, "�ֻ�ģʽ");
	select_handon.setrectangle(90);
	while (1)
	{
		MOUSEMSG msg_;
		msg_ = GetMouseMsg();
		//����������ڻ�ȡһ�������Ϣ�������ǰ�����Ϣ������û�У���һֱ�ȴ���
		int _x, _y;
		//_x = msg_.x / SQUARE;
		//_y = msg_.y / SQUARE;
		_x = msg_.x ;
		_y = msg_.y;
		if (msg_.mkLButton)//������
		{
			if (_x < 790 && _x>410 && _y > 400 && _y < 560)//�����������
			{
				// ����һ�����������
				random_device rd;
				mt19937 generator(rd());

				// ����������ֲ�
				uniform_int_distribution<int> distribution(1, 80); // ����1��80֮�������
				uniform_int_distribution<int> shu(1000, 6000);

				// ����һ���������

				for (int i = 0; i < shu(generator); ++i) {
					map[distribution(generator)][distribution(generator)] = 1;

				}
				cleardevice();
				break;
			}
			if (_x < 790 && _x>410 && _y > 600 && _y < 760)
			{
				CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)getAndSet, (LPVOID)map, NULL, NULL);
				//����һ���߳�
				while (Continue)
				{
					drawmap(map);
				}
				cleardevice();
				break;
			}

		}
	}


	//���ֲ���
	
	//��������
	mciSendString("open mp3.mp3", NULL, NULL, NULL);
	mciSendString("play mp3.mp3 repeat", NULL, NULL, NULL);//repeatΪѭ������ָ��

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
	setButton(button, 900, 200, 1080, 270,"�����ݻ�");
	pauseButton(button1, 900, 370, 1080, 440, "��ͣ/�ָ�");
	pulsarButton(buttonp, 850, 530, 950, 570, "������", WHITE);
	gliderButton(buttong, 1050, 530, 1150, 570, "������", WHITE);
	lightshipButton(buttonl, 850, 660, 950, 700, "��ɴ�", WHITE);
	tumblerButton(buttont, 1050, 660, 1150, 700, "������", WHITE);
	balanceButton(buttonb, 950, 595, 1050, 635, "������", WHITE);
	setButton(savebutton, 850, 50, 930, 90, "����", WHITE);
	setButton(readbutton, 1070, 50, 1150, 90, "�鿴", WHITE);
	setButton(veliocitybutton, 850, 100, 930, 140, "����", WHITE);
	setButton(cellcolorbutton, 1070, 100, 1150, 140, "��ɫ", WHITE);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)function, (LPVOID)map, NULL, NULL);


	
	//�ݻ�
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

