#include<iostream>
#include<cmath>
#include<iomanip>
using std::setw;
using namespace std;

//四则运算 
class operation
{
	public:
	//加法 
	int add(int x,int y)
	{
		int z=x+y;
		return z;
	}
	//减法 
	int sub(int x,int y)
	{
		int z=x-y;
		return z;
	}
	//乘法 
	int mutl(int x,int y)
	{
		int z=x*y;
		return z;
	}
	//除法 
	int div(int x,int y)
	{
		int z=x/y;
		return z;
	}
};
//判断 
class judge
{
	public:
	//判断奇偶 
	void judgeParity(int n)
	{
		if(n%2==0)
		{
			cout<<n<<"是偶数\n";
		}
		else{
			cout<<n<<"是奇数\n";
		}
	}
	//判断元音辅音 
	void judgeword(char s)
	{
		bool ischar;
		int isLowercaseVowel,isUppercaseVowel;
		ischar=(s>='a'&&s<='z'||s>='A'&&s<='Z');
		if(ischar)
		{
			isLowercaseVowel=(s=='a'||s=='e'||s=='i'||s=='o'||s=='u');
			isUppercaseVowel=(s=='A'||s=='E'||s=='I'||s=='O'||s=='U');
			if(isLowercaseVowel||isUppercaseVowel){
				cout<<s<<"是元音字母\n";
			}
			else{
				cout<<s<<"不是元音字母\n";
			}
		}
		else
		{
			cout<<s<<"不是字母\n";
		} 
	}
	//判断两个数大小 
	int judgemaxnumber(int a,int b)
	{
		if(a>b) return a;
		else return b;
	}
};
//求方程实数根 
class equation
{
	public:
		void Rootseeking(float a,float b,float c)
		{
			float s;
			s=b*b-4*a*c;
			float x1,x2;
			if(s>0)
			{
				x1=(-b+sqrt(s))/(2*a);
				x2=(-b-sqrt(s))/(2*a);
				cout<<"方程的两个根："<<x1<<setw(5)<<x2<<endl;
			}
			else if(s==0){
				x1=x2=(-b)/(2*a);
				cout<<"方程的两个根："<<x1<<setw(5)<<x2<<endl;
			}
			else
			{
				cout<<"方程无实数根\n";
			}
		}
};
//求和 
class Sumofnumber
{
	public:
	//奇数求和 
		void sumofOdd(int n)
		{
			 
			for(int i=1;i<=n;i++)
			{
				if(i%2!=0)
				{
					sum=sum+i;
				}
			}
			cout<<n<<"以内的奇数和："<<sum<<endl;
		}
		//偶数求和 
		void sumofeven(int n)
		{
			for(int i=1;i<=n;i++)
			{
				if(i%2==0)
				{
					sum=sum+i;
				}
			}
			cout<<n<<"以内的偶数和："<<sum<<endl;
		}
		//自然数求和 
		void sumofNatural(int n)
		{
			for(i=0;i<=n;i++)
			{
				sum=sum+i;
			}
			cout<<n<<"数以内的自然数和："<<sum<<endl;
		}
		protected:
			int sum,i;
};
int main()
{
	cout<<"操作:\n";
	cout<<"1、加法\n";
	cout<<"2、减法\n";
	cout<<"3、乘法\n";
	cout<<"4、除法\n";
	cout<<"5、判断奇偶\n";
	cout<<"6、判断元音辅音（元音： a、e、i、o、u ）：\n";
	cout<<"7、判断大小\n";
	cout<<"8、求一元二次方程的根\n";
	cout<<"9、求和\n"; 
	char g='y';
	while(g=='y'||g=='Y')
	{
	cout<<"输入你选择的操作：\n";
	int s,num;
	operation p;
	judge jg;
	equation e;
	Sumofnumber k; 
	cin>>s;
	//cout<<s<<endl; 
	if(s==5)
	{
		int n;
		
		cout<<"输入你想判断的数：\n";
		cin>>n;
		jg.judgeParity(n);
		cout<<"\n";
		cout<<"继续？（Y/N）\n";
		cin>>g;
	}
	else if(s==6){
		char s;
		cout<<"输入你想判断的字母：\n";
		cin>>s;
		jg.judgeword(s);
		cout<<"\n";
		cout<<"继续？（Y/N）\n";
		cin>>g;
	}
	else if(s==7)
	{
		int a,b;
		cout<<"输入你想判断的两个数：\n";
		cin>>a>>b;
		int max=jg.judgemaxnumber(a,b);
		cout<<"两个数中最大数："<<max<<"\n";
		cout<<"\n";
		cout<<"继续？（Y/N）\n";
		cin>>g;
	}
	else if(s==8)
	{
		float a,b,c;
		cout<<"输入方程的各项系数：\n";
		cin>>a>>b>>c;
		e.Rootseeking(a,b,c);
		cout<<"\n";
		cout<<"继续？（Y/N）\n";
		cin>>g;
	 }
	 else if(s==9)
	 {
	 	int a;
	 	cout<<"输入自然数：\n";
	 	cin>>a;
	 	k.sumofOdd(a);
	 	k.sumofeven(a);
	 	k.sumofNatural(a);
	 	cout<<"\n";
		cout<<"继续？（Y/N）\n";
		cin>>g;
	 }
	else if(s<5)
	{
	int a,b;
	cout<<"输入两个数：\n";
	cin>>a>>b;
	switch(s)
	{
		case 1:
			num=p.add(a,b);
			cout<<a<<"+"<<b<<"="<<num;break;
		case 2:
			num=p.sub(a,b);
			cout<<a<<"-"<<b<<"="<<num;break;
		case 3:
			num=p.mutl(a,b);
			cout<<a<<"*"<<b<<"="<<num;break;
		case 4:
			num=p.div(a,b);
			cout<<a<<"÷"<<b<<"="<<num;break;
		default:break;
	}
	cout<<"\n";
	cout<<"继续？（Y/N）\n";
	cin>>g;
	}
	}
	return 0;
}
