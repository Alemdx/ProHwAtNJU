#pragma once
#include<ctime>
#include<iostream>
#include<vector>
#include <iomanip>
#include<algorithm>
#include <cstdlib>
#include "Data_set.h"
#include "input.h"
using namespace std;
class KNN {
public:
	KNN(int k);
	vector<vector<double>> getou();//��ȡŷ���ļ�����
	vector<vector<double>> getman();//��ȡ�����ٵļ�����
private:
	vector<vector<double>> test_ou;//����ŷ�����Լ���<��ţ�Ԥ��ֵ��׼ȷֵ>
	vector<vector<double>> test_man;//���������ٲ��Լ���<��ţ�Ԥ��ֵ��׼ȷֵ>
};


