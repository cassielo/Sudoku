#include "stdafx.h"
#include "kernel.h"
#include <iostream>
#include <fstream>
using namespace std;

kernel::kernel()
{
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
	for (int k = 1; k < 10; k++)
		Table[i][j][k] = 1;
}

kernel::~kernel()
{
}

void kernel::read(char filename[])
{
	fstream f;
	f.open(filename, ios::in);
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
	{
		f >> Q[i][j];
	}
	f.close();

	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
		A[i][j] = Q[i][j];
}

void kernel::printQ()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Q[i][j]>0)
				cout << Q[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

bool kernel::checkTable(int r, int c, int num)
{
	if (Table[r][c][num] == 0)
		return false;

	int i, j, a = 0;
	for (i = 1; i <= 9; i++)
		a += Table[r][c][i];
	if (a == 1)
		return true;

	int b = 0, d = 0;
	for (i = 0; i < 9; i++)
	{
		if (Table[i][c][num] != 0)
			b++;
		if (Table[r][i][num] != 0)
			d++;
	}
	int e = 0;
	for (i = r / 3 * 3; i <= r / 3 * 3 + 2; i++)
	{
		for (j = c / 3 * 3; j <= c / 3 * 3 + 2; j++)
		{
			if (Table[i][j][num] != 0)
				e++;
		}
	}

	if (b == 1 || d == 1 || e == 1)
		return true;
	else return false;
}

void kernel::updateTable(int r, int c, int num)
{
	A[r][c] = num;
	int i, j;
	for (i = 0; i < 9; i++)
	{
		Table[i][c][num] = 0;
		Table[r][i][num] = 0;
	}
	for (i = r / 3 * 3; i <= r / 3 * 3 + 2; i++)
	{
		for (j = c / 3 * 3; j <= c / 3 * 3 + 2; j++)
			Table[i][j][num] = 0;
	}

	for (i = 1; i < 10; i++)
		Table[r][c][i] = 0;

	Table[r][c][num] = 1;
}

void kernel::printA()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void kernel::solve()
{
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
	{
		if (A[i][j] != 0)
			updateTable(i, j, A[i][j]);
	}

	while (1)
	{
		for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		for (int k = 1; k < 10; k++)
		{
			if (checkTable(i, j, k))
				updateTable(i, j, k);
		}

		int x = 0;
		for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		if (A[i][j] != 0)
			x++;

		if (x ==81) break;
	}

}
