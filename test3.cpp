#include<iostream>
#include<cmath>
#include<vector> 
#include<fstream>
#include <cfloat>
#include<limits>
#include <algorithm>
#define EPSILON 0.000001


using namespace std;

//二维矢量
struct Vec2d
{
	double x,y;
	Vec2d()
	{
		x=0.0;
		y=0.0;
	 } 
	 Vec2d(double dx,double dy)
	 {
	 	x=dx;
	 	y=dy;
	 }
	 void Set(double dx,double dy)
	 {
	 	x=dx;
	 	y=dy;
	 }
 };
 //判断点在线段上
 bool IsPointOnline(double px1,double py1,double px2,double py2,double px3,double py3,double px4,double py4)
 {
 	bool flag=false;
 	double d=(px2-px1)*(py4-py3)-(py2-py1)*(px4-px3);
 	if(d!=0)
 	{
 		double r=((py1-py3)*(px4-px3)-(px1-px3)*(py4-py3))/d;
 		double s=((py1-py3)*(px2-px1)-(px1-px3)*(py2-py1))/d;
 		if((r>=0) &&(r<=1) &&(s<=1))
 		{
 			flag=true;
		 }
	 }
 }
 //判断两线段相交
bool IsIntersect(double px1, double py1, double px2, double py2, double px3, double py3, double px4, double py4)
{
	bool flag = false;
	double d = (px2 - px1) * (py4 - py3) - (py2 - py1) * (px4 - px3);
	if (d != 0)
	{
		double r = ((py1 - py3) * (px4 - px3) - (px1 - px3) * (py4 - py3)) / d;
		double s = ((py1 - py3) * (px2 - px1) - (px1 - px3) * (py2 - py1)) / d;
		if ((r >= 0) && (r <= 1) && (s >= 0) && (s <= 1))
		{
			flag = true;
		}
	}
	return flag;
}
 //判断在多边形内
 bool Point_In_Polygn_2D(double x,double y,const vector<Vec2d> &POL)
 {
 	bool isinside=false;
 	int count=0;
 	
 	double minX=DBL_MAX;
 	for(int i=0;i<POL.size();i++)
 	{
 		minX=std::min(minX,POL[i].x);
	}
	 //
 	double px=x;
 	double py=y;
 	double linePoint1x=x;
 	double linePoint1y=y;
 	double linePoint2x=minX-10;
 	double linePoint2y=y;
 	
 	for(int i=0;i<POL.size();i++)
 	{
 		double cx1=POL[i].x;
 		double cy1 = POL[i].y;
		double cx2 = POL[i + 1].x;
		double cy2 = POL[i + 1].y;
		
		if(IsPointOnline(px, py, cx1, cy1, cx2, cy2))
		{
			return true;
		}
		if(fabs(cy2-cy1)<EPSILON)
		{
			continue;
		}
		if(IsPointOnline(cx1, cy1, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
		{
			if(cy1>cy2)
			{
				count++;
			}
		}
		else if(IsPointOnline(cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
		{
			if(cy2>cy1)
			{
				count++;
			}
		}
		else if(IsIntersect(cx1, cy1, cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
		{
			count++;
		}
	}
	if(count%2==1)
	{
		isinside=true;
	}
	return isinside;
 }
 
 int main()
 {
 	vector<Vec2d> POL;
 	
 	POL.push_back(Vec2d(268.28, 784.75));
	POL.push_back(Vec2d(153.98, 600.60));
	POL.push_back(Vec2d(274.63, 336.02));
	POL.push_back(Vec2d(623.88, 401.64));
	POL.push_back(Vec2d(676.80, 634.47));
	POL.push_back(Vec2d(530.75, 822.85));
	POL.push_back(Vec2d(268.28, 784.75));
	
	if (Point_In_Polygon_2D(407.98, 579.43, POL))
	{
		cout << "点（407.98, 579.43）在多边形内" << endl;
	}
	else
	{
		cout << "点（407.98, 579.43）在多边形外" << endl;
	}


	return 0;
 }
