#include<iostream>
#include<cmath>
#include<iomanip>
using std::setw;
using namespace std;

//�������� 
class operation
{
	public:
	//�ӷ� 
	int add(int x,int y)
	{
		int z=x+y;
		return z;
	}
	//���� 
	int sub(int x,int y)
	{
		int z=x-y;
		return z;
	}
	//�˷� 
	int mutl(int x,int y)
	{
		int z=x*y;
		return z;
	}
	//���� 
	int div(int x,int y)
	{
		int z=x/y;
		return z;
	}
};
//�ж� 
class judge
{
	public:
	//�ж���ż 
	void judgeParity(int n)
	{
		if(n%2==0)
		{
			cout<<n<<"��ż��\n";
		}
		else{
			cout<<n<<"������\n";
		}
	}
	//�ж�Ԫ������ 
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
				cout<<s<<"��Ԫ����ĸ\n";
			}
			else{
				cout<<s<<"����Ԫ����ĸ\n";
			}
		}
		else
		{
			cout<<s<<"������ĸ\n";
		} 
	}
	//�ж���������С 
	int judgemaxnumber(int a,int b)
	{
		if(a>b) return a;
		else return b;
	}
};
//�󷽳�ʵ���� 
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
				cout<<"���̵���������"<<x1<<setw(5)<<x2<<endl;
			}
			else if(s==0){
				x1=x2=(-b)/(2*a);
				cout<<"���̵���������"<<x1<<setw(5)<<x2<<endl;
			}
			else
			{
				cout<<"������ʵ����\n";
			}
		}
};
//��� 
class Sumofnumber
{
	public:
	//������� 
		void sumofOdd(int n)
		{
			 
			for(int i=1;i<=n;i++)
			{
				if(i%2!=0)
				{
					sum=sum+i;
				}
			}
			cout<<n<<"���ڵ������ͣ�"<<sum<<endl;
		}
		//ż����� 
		void sumofeven(int n)
		{
			for(int i=1;i<=n;i++)
			{
				if(i%2==0)
				{
					sum=sum+i;
				}
			}
			cout<<n<<"���ڵ�ż���ͣ�"<<sum<<endl;
		}
		//��Ȼ����� 
		void sumofNatural(int n)
		{
			for(i=0;i<=n;i++)
			{
				sum=sum+i;
			}
			cout<<n<<"�����ڵ���Ȼ���ͣ�"<<sum<<endl;
		}
		protected:
			int sum,i;
};
int main()
{
	cout<<"����:\n";
	cout<<"1���ӷ�\n";
	cout<<"2������\n";
	cout<<"3���˷�\n";
	cout<<"4������\n";
	cout<<"5���ж���ż\n";
	cout<<"6���ж�Ԫ��������Ԫ���� a��e��i��o��u ����\n";
	cout<<"7���жϴ�С\n";
	cout<<"8����һԪ���η��̵ĸ�\n";
	cout<<"9�����\n"; 
	char g='y';
	while(g=='y'||g=='Y')
	{
	cout<<"������ѡ��Ĳ�����\n";
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
		
		cout<<"���������жϵ�����\n";
		cin>>n;
		jg.judgeParity(n);
		cout<<"\n";
		cout<<"��������Y/N��\n";
		cin>>g;
	}
	else if(s==6){
		char s;
		cout<<"���������жϵ���ĸ��\n";
		cin>>s;
		jg.judgeword(s);
		cout<<"\n";
		cout<<"��������Y/N��\n";
		cin>>g;
	}
	else if(s==7)
	{
		int a,b;
		cout<<"���������жϵ���������\n";
		cin>>a>>b;
		int max=jg.judgemaxnumber(a,b);
		cout<<"���������������"<<max<<"\n";
		cout<<"\n";
		cout<<"��������Y/N��\n";
		cin>>g;
	}
	else if(s==8)
	{
		float a,b,c;
		cout<<"���뷽�̵ĸ���ϵ����\n";
		cin>>a>>b>>c;
		e.Rootseeking(a,b,c);
		cout<<"\n";
		cout<<"��������Y/N��\n";
		cin>>g;
	 }
	 else if(s==9)
	 {
	 	int a;
	 	cout<<"������Ȼ����\n";
	 	cin>>a;
	 	k.sumofOdd(a);
	 	k.sumofeven(a);
	 	k.sumofNatural(a);
	 	cout<<"\n";
		cout<<"��������Y/N��\n";
		cin>>g;
	 }
	else if(s<5)
	{
	int a,b;
	cout<<"������������\n";
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
			cout<<a<<"��"<<b<<"="<<num;break;
		default:break;
	}
	cout<<"\n";
	cout<<"��������Y/N��\n";
	cin>>g;
	}
	}
	return 0;
}
