#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include<string>
using namespace std;
class input {
public:
    input(string name);
    vector<vector<double>> get();//����һ������ ��ȡ������
private:
    vector<vector<double> > Irises_;
};