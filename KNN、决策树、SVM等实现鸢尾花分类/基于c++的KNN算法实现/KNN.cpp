#pragma once
#include<iostream>
using namespace std;
#include "KNN.h"
bool cmp(vector<double>& a, vector<double>& b) {
	if (a[1] != b[1])
		return a[1] < b[1];
	else
		return a[0] > b[0];
}//�Զ�άvector�����������,����ÿ�еڶ���Ԫ�ؽ��д�С����������ͬ����Ƚϵ�����Ԫ��
double get_oudis(vector<double> a, vector<double> b)
{
	double i = sqrt(pow((a[1] - b[1]), 2) + pow((a[2] - b[2]), 2) + pow((a[3] - b[3]), 2) + pow((a[4] - b[4]), 2));
	return i;
};//ŷʽ����
double get_madis(vector<double> a, vector<double> b) {
	double i = sqrt(abs(a[1] - b[1]) + abs(a[2] - b[2]) + abs(a[3] - b[3]) + abs(a[4] - b[4]));
	return i;
}//�����پ���
KNN::KNN(int k)
{
	input tmp("Iris.csv");
	Data_set tmp2(tmp.get());//���ݸ�temp2
	//cout << "hhhhhhh" << endl;
	vector<vector<double>> a = tmp2.get_test();//ȡ�����Լ�
	vector<vector<double>> b = tmp2.get_set();//ȡ��ѵ����
	vector<double> single;
	vector<double>ret;
	vector<vector<double>> test1;
	//����ŷʽ�������Ԥ��
	//cout << "���Լ����" << "\t" << "��������Ԥ��ֵ" << "\t" << "���Լ���ʵֵ" << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 120; j++) {
			single.push_back(b[j][0]);//ѵ�����ı��
			single.push_back(get_oudis(a[i], b[j]));//ѵ������ò��Լ�֮��ľ���ŷʽ����
			single.push_back(b[j][5]);//����ѵ����������
			test1.push_back(single);//��¼index�;��룬����(�����Ǽ�¼�������Լ�������ѵ����������)
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
		sort(test1.begin(), test1.end(), cmp);//��С��������
		//cout << "--------------------------------------" << endl;
		//for (int i = 0; i < 120; i++)
		//{
		//	for (int j = 0; j < 3; j++)
		//	{
		//		cout << test1[i][j] << " " << endl;
		//	}
		//	cout << endl;
		//}
		int arr[5] = { 0 };//��¼�±꼰�����
		for (int i = 0; i < k; i++)
		{
			arr[int(test1[i][2])]++;//ͳ��ǰk�����ֵ�����ĸ���
		}
		//���巵�س��ִ�����������,��¼��max֮��
		int max = 1;
		for (int i = 1; i <= 3; i++)
		{

			if (arr[i + 1] > arr[i])
			{
				max = i + 1;
			}
		}//maxΪԤ��ֵ
		ret.push_back(a[i][0]);
		ret.push_back(max);
		ret.push_back(a[i][5]);//ret<���Լ���ţ����Լ�Ԥ��ֵ�����Լ���ʵֵ>
		//cout << a[i][0] << "\t" << max << "\t" << a[i][5] << endl;
		test_ou.push_back(ret);
		ret.clear();

	}
	//���������پ������Ԥ��
	test1.clear();
	//cout << "���Լ����" << "\t" << "��������Ԥ��ֵ" << "\t" << "���Լ���ʵֵ" << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 120; j++) {
			single.push_back(b[j][0]);//ѵ�������
			single.push_back(get_madis(a[i], b[j]));//���Լ���ѵ���������پ���
			single.push_back(b[j][5]);//������Լ�������
			test1.push_back(single);//ѵ������� ���� ѵ��������
			single.clear();
		}
		sort(test1.begin(), test1.end(), cmp);
		int arr[5] = { 0 };//��¼�±꼰�����
		for (int i = 0; i < k; i++)
		{
			arr[int(test1[i][2])]++;//ͳ��ǰk�����ֵ�����ĸ���
		}
		//���巵�س��ִ�����������,��¼��max֮��
		int max = 1;
		for (int i = 1; i <= 3; i++)
		{

			if (arr[i + 1] > arr[i])
			{
				max = i + 1;
			}
		}//maxΪԤ��ֵ
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