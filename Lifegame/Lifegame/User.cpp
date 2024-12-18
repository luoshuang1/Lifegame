#include "User.h"
#include <fstream>
#include <iostream>

using namespace std;

void User::save() {
    ofstream ofile("users.txt", ios::app);
    if (ofile.is_open()) {
        ofile << username << " " << password << "\n";
        ofile.close();
    }
    else {
        cout << "Error: Unable to open file for writing" << endl;
    }
}

bool User::exists(const string& username) {
    ifstream ifile("users.txt");
    if (ifile.is_open()) {
        string line;
        while (getline(ifile, line)) {
            size_t pos = line.find(' ');
            if (pos != string::npos) {
                string storedUsername = line.substr(0, pos);
                if (username == storedUsername) {
                    ifile.close();
                    return true;
                }
            }
        }
        ifile.close();
    }
    return false;
}

bool User::login(const string& username, const string& password) {
    ifstream ifile("users.txt");
    if (ifile.is_open()) {
        string line;
        while (getline(ifile, line)) {
            size_t pos = line.find(' ');
            if (pos != string::npos) {
                string storedUsername = line.substr(0, pos);
                string storedPassword = line.substr(pos + 1);
                if (username == storedUsername && password == storedPassword) {
                    ifile.close();
                    return true;
                }
            }
        }
        ifile.close();
    }
    return false;
}


bool User::remove(const string& username) {
    std::ifstream ifile("users.txt");
    if (ifile.is_open()) {
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool removed = false;
        while (getline(ifile, line)) {
            size_t pos = line.find(' ');
            if (pos != std::string::npos) {
                std::string storedUsername = line.substr(0, pos);
                if (username == storedUsername) {
                    removed = true;
                }
                else {
                    tempFile << line << "\n";
                }
            }
        }
        ifile.close();
        tempFile.close();
       // remove("users.txt");
        //rename("temp.txt", "users.txt");
        if (removed) {
            if (std::remove("users.txt") != 0) {
                std::cout << "Error deleting file: users.txt" << std::endl;
                return false;
            }

            if (std::rename("temp.txt", "users.txt") != 0) {
                std::cout << "Error renaming file: temp.txt to users.txt" << std::endl;
                return false;
            }
        }
        else {
            std::remove("temp.txt");
        }

        return removed;
    }
      
    return false;
}


#include <iomanip>

void User::viewAll() {
    std::ifstream ifile("users.txt");
    if (ifile.is_open()) {
        std::string line;

        // 打印表头
        std::cout << "=================================" << std::endl;
        std::cout << "| Username             | Password |" << std::endl;
        std::cout << "=================================" << std::endl;

        while (getline(ifile, line)) {
            // 解析用户名和密码
            size_t pos = line.find(' ');
            if (pos != std::string::npos) {
                std::string storedUsername = line.substr(0, pos);
                std::string storedPassword = line.substr(pos + 1);

                // 格式化输出用户名和密码
                std::cout << "| " << std::setw(20) << std::left << storedUsername << " | "
                    << std::setw(8) << std::right << storedPassword << " |" << std::endl;
            }
        }

        // 打印表尾
        std::cout << "=================================" << std::endl;

        ifile.close();
    }
    else {
        std::cout << "Error: Unable to open file for reading" << std::endl;
    }
}

