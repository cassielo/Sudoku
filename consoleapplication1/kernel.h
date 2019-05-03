#pragma once
class kernel
{
public:
	kernel();
	~kernel();
	void read(char filename[]);
	void solve();
	void printQ();
	void printA();
	void updateTable(int, int, int);
	bool checkTable(int, int, int);
private:
	int Q[9][9];
	int A[9][9];
	int Table[9][9][10];

};

