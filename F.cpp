#include<iostream>
#include<iomanip>
#include<cstdlib> 
#define W 73.66
#define E 135.05
#define N 53.55
#define S 3.86
using namespace std;

class Rectangle
{
	static int int_count;
	public:
		double west,east;
		double north,south;
		 
		Rectangle(double,double,double,double);
};
Rectangle::Rectangle(double a,double b,double c,double d)
{
	north=a;
	west=b;
	south=c;
	east=d;
}
int main()
{
	static int in,out;
	Rectangle FitRetangle[]=
	{
		Rectangle(49.22, 79.44, 42.88, 96.33),
    	Rectangle(54.14, 109.68, 39.37, 135.00),
    	Rectangle(42.88, 73.12, 29.52, 124.14),
    	Rectangle(29.52, 82.96, 26.71, 97.03),
    	Rectangle(29.52, 97.02, 20.41, 124.36),
    	Rectangle(20.41, 107.97, 17.87, 111.74),
		Rectangle(25.39, 119.92, 21.78, 122.49),
	};
	Rectangle outofRetangle[]=
	{
		
    	Rectangle(22.28, 101.86 ,20.09, 106.66),
    	Rectangle(21.54, 106.45, 20.48, 108.05),
    	Rectangle(55.82, 109.03, 50.32, 119.12),
    	Rectangle(55.82, 127.45, 49.55, 137.02),
    	Rectangle(44.89, 131.26, 42.56, 137.02),
	};
	double x,y;
	cout<<"输入该点的经度、纬度：\n";
	cin>>x>>y;
	/*随机数 
	x= W + (double)(rand()) /RAND_MAX * (E- W);
	y= S + (double)(rand()) /RAND_MAX * (N- S);
	
	for(int i=0;i<7;i++)
	{
		cout<<FitRetangle[i].west<<setw(10)<<FitRetangle[i].east<<setw(10)<<FitRetangle[i].south<<setw(10)<<FitRetangle[i].north<<endl;
	}*/ 
	//排除不合适的区域 
	for(int i=0;i<6;i++)
	{
		if(x>=FitRetangle[i].west && x<=FitRetangle[i].east && y>=FitRetangle[i].south && y<=FitRetangle[i].north)
		{
			in++;
			cout<<in<<endl;
		}
		if(x>=outofRetangle[i].west && x<=outofRetangle[i].east && y>=outofRetangle[i].south && y<=outofRetangle[i].north)
		{
			out++;
			cout<<in<<endl;
		}
	}
	if(in!=0&&out==0)
	{
		cout<<"true!\n";
	}
	else
	{
		cout<<"false!\n";
	}
	return 0;
}
