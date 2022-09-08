#pragma once
#include "error_ana.h"
void error_ana::set_k(int k) 
{
	KNN* knn = new KNN(k);
	vector<vector<double>> the_a = knn->getou();//��ȡŷ�����Լ���<��ţ�Ԥ��ֵ��׼ȷֵ>
	vector<vector<double>> the_b = knn->getman();//��ȡ�����ٲ��Լ���<��ţ�Ԥ��ֵ��׼ȷֵ>
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
	cout << "���" << '\t' << "Ԥ��ֵ" << '\t' << "׼ȷֵ" << endl;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j]<<'\t';
		}
		cout << endl;
	}

	cout << "��ʱ ŷʽ�����׼ȷ��Ϊ��" << endl;
	cout << sqrt(sum * 1.0 / 30)<<endl;
	sum = 0;
	for (int i = 0; i < 30; i++)
	{
		if (b[i][1] == b[i][2])
			sum++;
	}
	cout << "���" << '\t' << "Ԥ��ֵ" << '\t' << "׼ȷֵ" << endl;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << b[i][j] <<'\t';
		}
		cout << endl;
	}
	cout << "��ʱ �����پ����׼ȷ��Ϊ��" << endl;
	cout << sqrt(sum * 1.0 / 30)<<endl;
}
