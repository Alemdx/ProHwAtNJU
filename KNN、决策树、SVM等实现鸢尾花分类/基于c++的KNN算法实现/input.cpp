#pragma once
#include "input.h"
input::input(string name)//�����ݴ���һ��Irises������
{
    vector<vector<double> > Irises;
    ifstream fp(name); //��������һ��ifstream����ָ���ļ�·��
    string line;
    getline(fp, line); //������������һ�в�������
    while (getline(fp, line))
    { //ѭ����ȡÿ������
        vector<double> Iris;
        string number;
        istringstream readstr(line); //string��������
        //��һ�����ݰ�'��'�ָ�
        for (int j = 0; j < 6; j++) {
            getline(readstr, number, ','); //ѭ����ȡ����
            Iris.push_back(stod(number));
        }
        Irises.push_back(Iris); //���뵽vector��
    }
    Irises_ = Irises;
}
vector<vector<double> > input::get()
{
    return Irises_;
}