#pragma once
#include "Data_set.h"
Data_set::Data_set(vector<vector<double> >Irises)
{
    int i = 0;
    while (i < 150 * 0.8)
    {
        int r = rand() % 150;
        //cout << r<<" ";
        vector<double> iris_line;//�����ȡĳһ������
        for (int j = 0; j < 6; j++)
        {
            //cout << Irises[r][j] << endl;
            iris_line.push_back(Irises[r][j]);
        }
        iris_set.push_back(iris_line);//���������Լ���
        iris_line.clear();
        i++;
    }
    i = 0;
    while (i < 150 * 0.2)
    {
        int r = rand() % 150;
        vector<double> iris_line;
        for (int j = 0; j < 6; j++)
        {
           //cout << Irises[r][j] << endl;
            iris_line.push_back(Irises[r][j]);
        }
        iris_test.push_back(iris_line);//ȡ��ĳһ�����ݣ����������Լ���
        iris_line.clear();
        i++;
    }
}
vector<vector<double> > Data_set::get_set() {
    return iris_set;
}
vector<vector<double> > Data_set::get_test() {
    return iris_test;
}