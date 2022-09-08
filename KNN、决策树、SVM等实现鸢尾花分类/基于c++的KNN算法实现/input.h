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
    vector<vector<double>> get();//返回一个参数 读取的数据
private:
    vector<vector<double> > Irises_;
};