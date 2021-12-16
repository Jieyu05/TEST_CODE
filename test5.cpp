#include<iostream>
#include<fstream>
#include<vector>
#define N 10000
using namespace std;


int main()
{
	//创建流 跟文件相关联 
	ifstream input("chinagps.txt");
	
	//从文件中循环读入数据 
	static double num[N];
	cout<<"多边形集合坐标集合"<<endl;
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
