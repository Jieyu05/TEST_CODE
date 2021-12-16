#include<iostream>
#include<fstream>
#include<vector>
#define N 10000
using namespace std;


int main()
{
	ifstream input("chinagps.txt");
	
	static double num[N];
	int len,j=0,k=0;
	cout<<"多边形集合坐标集合"<<endl;
	for(int i=0;i<N;i++)
	{
		if(!input.eof())
		{
		
			input>>num[i];
			len++;
		}
	}
	input.close();
	cout<<len<<endl;
	for(int i=0;i<len;i++)
	{
		if(num[i]!=0) 
		
		{
			cout<<i <<endl;
			cout<<num[i]<<endl;
		}
	}
	 double num1[N],num2[N];
	cout<<"\n";
	//cout<<j<<endl;
	for(int i=0;i<len-2;i++)
	{
		if(i%2==0)
		{
			num1[j]=num[i];
			j++;
		}
		else
		{
			num2[k]=num[i];
			k++;
		}
	}
	for(int i=0;i<j;i++)
	{
		cout<<num1[i]<<endl;
	}
	for(int i=0;i<k;i++)
	{
		cout<<num2[i]<<endl;
	}
	
	//cout<<j<<"\n"<<k<<endl;
	
	return 0;
}

