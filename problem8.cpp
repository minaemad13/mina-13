#include "pch.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

int main()
{
	vector<int> grades; 
	int val;
	cout << "Enter grades  (-1 to QUIT)"<<endl;
	
	while (cin>> val &&  val >= 0)
	{	
		grades.push_back(val);
	}
	int max = 0;
	for (int i : grades)
	{
		if (max < i) max = i;
	}
	int *p = new int[max];
	for (int j = 0; j <= max; j++)
	{
		p[j] = 0;
	}
	for (int i : grades)
	{
		if (i >= 0)
		{
			++p[i]; 
		}
	}
	for (int x = 0; x <= max; x++)
	{
		if (p[x] != 0)
		{
			cout << "Number of " << x << "'s => " << p[x] << endl;
		}
	}
	delete []p;
	return 0;
}
