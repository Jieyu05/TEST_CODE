#include<iostream>
#include<cstdlib> 
#define w 73.66
#define e 135.05
#define N 53.55
#define S 3.86
using namespace std;
int main()

{
	for(int i=0;i<10;i++)
	{
		double val = w + (double)(rand()) /RAND_MAX * (e- w);
		cout<<val<<"\n";
	}
	return 0;
}
