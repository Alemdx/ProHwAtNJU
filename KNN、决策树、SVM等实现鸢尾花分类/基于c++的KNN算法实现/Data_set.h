#pragma once
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
class Data_set{
private:
    vector<vector<double> > iris_set;//���80%������Ϊѵ����
    vector<vector<double> > iris_test;//���20%������Ϊ���Լ�
public:
    Data_set(vector<vector<double> >Irises);
    vector<vector<double> >get_set();
    vector<vector<double> >get_test();

};