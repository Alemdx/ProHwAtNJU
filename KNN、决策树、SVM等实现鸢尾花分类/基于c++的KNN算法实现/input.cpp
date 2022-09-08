#pragma once
#include "input.h"
input::input(string name)//将数据存入一个Irises数组中
{
    vector<vector<double> > Irises;
    ifstream fp(name); //定义声明一个ifstream对象，指定文件路径
    string line;
    getline(fp, line); //跳过列名，第一行不做处理
    while (getline(fp, line))
    { //循环读取每行数据
        vector<double> Iris;
        string number;
        istringstream readstr(line); //string数据流化
        //将一行数据按'，'分割
        for (int j = 0; j < 6; j++) {
            getline(readstr, number, ','); //循环读取数据
            Iris.push_back(stod(number));
        }
        Irises.push_back(Iris); //插入到vector中
    }
    Irises_ = Irises;
}
vector<vector<double> > input::get()
{
    return Irises_;
}