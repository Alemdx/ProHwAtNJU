#pragma once
#include<iostream>
using namespace std;
#include "KNN.h"
bool cmp(vector<double>& a, vector<double>& b) {
	if (a[1] != b[1])
		return a[1] < b[1];
	else
		return a[0] > b[0];
}//对二维vector数组进行排序,按照每行第二个元素进行从小大排序。若相同，则比较第三个元素
double get_oudis(vector<double> a, vector<double> b)
{
	double i = sqrt(pow((a[1] - b[1]), 2) + pow((a[2] - b[2]), 2) + pow((a[3] - b[3]), 2) + pow((a[4] - b[4]), 2));
	return i;
};//欧式距离
double get_madis(vector<double> a, vector<double> b) {
	double i = sqrt(abs(a[1] - b[1]) + abs(a[2] - b[2]) + abs(a[3] - b[3]) + abs(a[4] - b[4]));
	return i;
}//曼哈顿距离
KNN::KNN(int k)
{
	input tmp("Iris.csv");
	Data_set tmp2(tmp.get());//传递给temp2
	//cout << "hhhhhhh" << endl;
	vector<vector<double>> a = tmp2.get_test();//取出测试集
	vector<vector<double>> b = tmp2.get_set();//取出训练集
	vector<double> single;
	vector<double>ret;
	vector<vector<double>> test1;
	//根据欧式距离进行预测
	//cout << "测试集标号" << "\t" << "用曼哈顿预测值" << "\t" << "测试集真实值" << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 120; j++) {
			single.push_back(b[j][0]);//训练集的标号
			single.push_back(get_oudis(a[i], b[j]));//训练集与该测试集之间的距离欧式距离
			single.push_back(b[j][5]);//加入训练集的种类
			test1.push_back(single);//记录index和距离，种类(这里是记录单个测试集对所有训练集的数据)
			single.clear();
		}	
		//cout << "*************************" << endl;
		//for (int i = 0; i < 120; i++)
		//{
		//	for (int j = 0; j < 3; j++)
		//	{
		//		cout << test1[i][j] << " " << endl;
		//	}
		//	cout << endl;
		//}
		sort(test1.begin(), test1.end(), cmp);//从小到大排序
		//cout << "--------------------------------------" << endl;
		//for (int i = 0; i < 120; i++)
		//{
		//	for (int j = 0; j < 3; j++)
		//	{
		//		cout << test1[i][j] << " " << endl;
		//	}
		//	cout << endl;
		//}
		int arr[5] = { 0 };//记录下标及其个数
		for (int i = 0; i < k; i++)
		{
			arr[int(test1[i][2])]++;//统计前k个出现的种类的个数
		}
		//定义返回出现次数最多的种类,记录在max之中
		int max = 1;
		for (int i = 1; i <= 3; i++)
		{

			if (arr[i + 1] > arr[i])
			{
				max = i + 1;
			}
		}//max为预测值
		ret.push_back(a[i][0]);
		ret.push_back(max);
		ret.push_back(a[i][5]);//ret<测试集标号，测试集预测值，测试集真实值>
		//cout << a[i][0] << "\t" << max << "\t" << a[i][5] << endl;
		test_ou.push_back(ret);
		ret.clear();

	}
	//根据曼哈顿距离进行预测
	test1.clear();
	//cout << "测试集标号" << "\t" << "用曼哈顿预测值" << "\t" << "测试集真实值" << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 120; j++) {
			single.push_back(b[j][0]);//训练集标号
			single.push_back(get_madis(a[i], b[j]));//测试集与训练集曼哈顿距离
			single.push_back(b[j][5]);//加入测试集的种类
			test1.push_back(single);//训练集标号 距离 训练集种类
			single.clear();
		}
		sort(test1.begin(), test1.end(), cmp);
		int arr[5] = { 0 };//记录下标及其个数
		for (int i = 0; i < k; i++)
		{
			arr[int(test1[i][2])]++;//统计前k个出现的种类的个数
		}
		//定义返回出现次数最多的种类,记录在max之中
		int max = 1;
		for (int i = 1; i <= 3; i++)
		{

			if (arr[i + 1] > arr[i])
			{
				max = i + 1;
			}
		}//max为预测值
		ret.push_back(a[i][0]);
		ret.push_back(max);
		ret.push_back(a[i][5]);
		//cout << a[i][0] << "\t" << max << "\t" << a[i][5] << endl;
		test_man.push_back(ret);
		ret.clear();
	}
}
vector<vector<double>> KNN::getman()
{
	return test_ou;
}
vector<vector<double>>KNN::getou()
{
	return test_man;
}