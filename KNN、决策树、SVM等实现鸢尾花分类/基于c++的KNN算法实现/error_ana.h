#include"KNN.h"
#include<iostream>
using namespace std;
class error_ana {
public :
	void set_k(int k);
	void ans() ;
private:
	int k;
	vector<vector<double>> a;
	vector<vector<double>> b;
};
