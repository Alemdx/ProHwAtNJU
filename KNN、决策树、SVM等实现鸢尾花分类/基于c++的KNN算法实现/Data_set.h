#pragma once
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
class Data_set{
private:
    vector<vector<double> > iris_set;//存放80%数据作为训练集
    vector<vector<double> > iris_test;//存放20%数据作为测试集
public:
    Data_set(vector<vector<double> >Irises);
    vector<vector<double> >get_set();
    vector<vector<double> >get_test();

};