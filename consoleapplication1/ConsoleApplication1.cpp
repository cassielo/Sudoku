// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "kernel.h"
#include <iostream>
#include <fstream>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	kernel x;
	x.read("Question1.txt");
	x.printQ();
	x.solve();
	x.printA();
	system("pause");
	return 0;
}


