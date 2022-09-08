#pragma once
#include "error_ana.h"
void error_ana::set_k(int k) 
{
	KNN* knn = new KNN(k);
	vector<vector<double>> the_a = knn->getou();//获取欧拉测试集的<标号，预测值，准确值>
	vector<vector<double>> the_b = knn->getman();//获取曼哈顿测试集的<标号，预测值，准确值>
	a = the_a;
	b = the_b;
}
void error_ana::ans() {
	int sum = 0;
	for (int i = 0; i < 30; i++)
	{
		if (a[i][1] == a[i][2])
			sum++;
	}
	cout << "标号" << '\t' << "预测值" << '\t' << "准确值" << endl;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j]<<'\t';
		}
		cout << endl;
	}

	cout << "此时 欧式距离的准确率为：" << endl;
	cout << sqrt(sum * 1.0 / 30)<<endl;
	sum = 0;
	for (int i = 0; i < 30; i++)
	{
		if (b[i][1] == b[i][2])
			sum++;
	}
	cout << "标号" << '\t' << "预测值" << '\t' << "准确值" << endl;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << b[i][j] <<'\t';
		}
		cout << endl;
	}
	cout << "此时 曼哈顿距离的准确率为：" << endl;
	cout << sqrt(sum * 1.0 / 30)<<endl;
}
