#pragma once
#include "Data_set.h"
Data_set::Data_set(vector<vector<double> >Irises)
{
    int i = 0;
    while (i < 150 * 0.8)
    {
        int r = rand() % 150;
        //cout << r<<" ";
        vector<double> iris_line;//随机读取某一行数据
        for (int j = 0; j < 6; j++)
        {
            //cout << Irises[r][j] << endl;
            iris_line.push_back(Irises[r][j]);
        }
        iris_set.push_back(iris_line);//将其放入测试集中
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
        iris_test.push_back(iris_line);//取出某一行数据，将其放入测试集中
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