#include "iostream"
#include "fstream"
#define N 1000
using namespace std;

struct Point {
    double x;//
    double y;

    Point(double dx, double dy) {
        x = dx;
        y = dy;
    }
    Point(){
	}
};
/*
class GPS {
public:
    void setGPS(double dx, double dy) {
        x = dx;
        y = dy;
    }
    double x;
    double y;
};*/

bool rayCasting(Point p, Point poly[],int len) {
    double px = p.x;
    double py = p.y;
    bool flag = false;

    for (int i = 0,j = 0; i <len; i++) {
        double sx = poly[i].x,
               sy = poly[i].y,
               tx = poly[j].x,
               ty = poly[j].y;

        // �������ζ����غ�
        if ((sx ==  px && sy ==  py) || (tx ==  px && ty ==  py)) 
		{
            flag=!flag;
        }
        // �ж��߶����˵��Ƿ�����������
        if ((sy < py && ty >= py) || (sy >= py && ty < py)) 
		{
            // �߶��������� Y ������ͬ�ĵ�� X ����
            double x = sx + (py - sy) * (tx - sx) / (ty - sy);
            // ���ڶ���εı���
            if (x ==  px) 
			{
               flag=!flag;
            }
            // ���ߴ�������εı߽�
            if (x > px) 
			{
                flag = !flag;
            }
        }
    }

    // ���ߴ�������α߽�Ĵ���Ϊ����ʱ���ڶ������
    return flag ;//? 'in' : 'out';
}
int main()
{
	double a,b;
	cout<<"������Ե㾭γ�ȣ�\n";
	cin>>a>>b;
		ifstream input("chinagps.txt");
	
	static double num[N];
	int len,j=0,k=0;
	//cout<<"����μ������꼯��"<<endl;
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
	/*
	for(int i=0;i<len;i++)
	{
		if(num[i]!=0) 
		
		{
			cout<<i <<endl;
			cout<<num[i]<<endl;
		}
	}*/
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
	Point ploy[N],p;
	for(int i=0;i<len-1,j<len;i++)
	{
		ploy[i].x=num1[i];
		ploy[i].y=num2[i];
	}
	bool str=rayCasting(p,ploy,len);
	cout<<str<<endl;
	//Point p=new Point(a,b);
	return 0;
}

