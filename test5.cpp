#include<iostream>
#include<fstream>
#include<vector>
#define N 10000
using namespace std;


int main()
{
	//������ ���ļ������ 
	ifstream input("chinagps.txt");
	
	//���ļ���ѭ���������� 
	static double num[N];
	cout<<"����μ������꼯��"<<endl;
	for(int i=0;i<N;i++)
	{
		if(!input.eof())
		{
			input>>num[i];
		}
	}
	for(int i=0;i<N;i++)
	{
		if(num[i]!=0) cout<<num[i]<<endl;
		cout<<s[i]<<endl;
	}
	input.close();
	return 0;
}
