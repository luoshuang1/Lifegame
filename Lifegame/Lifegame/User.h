#pragma once
#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
public:
    string username;
    string password;

    void save();//保存
    static bool exists(const string& username);//检查用户名是否存在
    static bool login(const string& username, const string& password);//登录
    static bool remove(const string& username);  // 删除
    static void viewAll();  // 查看已储存的用户名和密码
};

#endif  
