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
	vector<vector<double>> getou();//获取欧拉的计算结果
	vector<vector<double>> getman();//获取曼哈顿的计算结果
private:
	vector<vector<double>> test_ou;//所有欧拉测试集的<标号，预测值，准确值>
	vector<vector<double>> test_man;//所有曼哈顿测试集的<标号，预测值，准确值>
};


