#pragma once
#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
public:
    string username;
    string password;

    void save();//����
    static bool exists(const string& username);//����û����Ƿ����
    static bool login(const string& username, const string& password);//��¼
    static bool remove(const string& username);  // ɾ��
    static void viewAll();  // �鿴�Ѵ�����û���������
};

#endif  
