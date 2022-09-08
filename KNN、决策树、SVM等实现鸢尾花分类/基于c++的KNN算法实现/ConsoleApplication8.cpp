#include<vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <cstring>
#include<algorithm>
#include "Data_set.h"
#include "input.h"
#include"KNN.h"
#include"error_ana.h"
int main()
{
	srand(time(0));
	//int k;
	//cin >> k;
	/*for (int i = 3; i <= 120; i++) {
		cout << i << endl;
		
		
	}*/
	error_ana a;
	a.set_k(15);
	a.ans();
	return 0;
}