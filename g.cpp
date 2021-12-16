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

        // 点与多边形顶点重合
        if ((sx ==  px && sy ==  py) || (tx ==  px && ty ==  py)) 
		{
            flag=!flag;
        }
        // 判断线段两端点是否在射线两侧
        if ((sy < py && ty >= py) || (sy >= py && ty < py)) 
		{
            // 线段上与射线 Y 坐标相同的点的 X 坐标
            double x = sx + (py - sy) * (tx - sx) / (ty - sy);
            // 点在多边形的边上
            if (x ==  px) 
			{
               flag=!flag;
            }
            // 射线穿过多边形的边界
            if (x > px) 
			{
                flag = !flag;
            }
        }
    }

    // 射线穿过多边形边界的次数为奇数时点在多边形内
    return flag ;//? 'in' : 'out';
}
int main()
{
	double a,b;
	cout<<"输入测试点经纬度：\n";
	cin>>a>>b;
		ifstream input("chinagps.txt");
	
	static double num[N];
	int len,j=0,k=0;
	//cout<<"多边形集合坐标集合"<<endl;
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

