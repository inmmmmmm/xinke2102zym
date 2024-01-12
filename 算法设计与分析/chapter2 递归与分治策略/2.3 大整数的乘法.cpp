#include <iostream>
#include <cmath>
using namespace std;

#define SIGN(A)((A>0)?1:-1) 

//用分治法计算两个大整数的乘积
int divideConquer(int X, int Y, int n)
{
    int sign=SIGN(X)*SIGN(Y);//记录乘积的符号
    int x=abs(X);//取X的绝对值
    int y=abs(Y);//取Y
    if(x==0 || y==0)//如果有一个数为0
        return 0;
    else if(n==1) // 如果只有一位数，直接相乘
        return sign*x*y;
    else
	{
        int A=(int)x/pow(10,(int)(n/2));
        int B=x-A*pow(10,n/2);
        int C=(int)y/pow(10,(int)(n/2));
        int D=y-C*pow(10,n/2);
        // 递归计算AC, BD，(A-B)(D-C) + AC + BD
        int AC=divideConquer(A,C,n/2);
        int BD=divideConquer(B,D,n/2);
        int ABDC=divideConquer((A-B),(D-C),n/2)+AC+BD;
        // 返回乘积的结果
        return sign*(AC*pow(10,n)+ABDC*pow(10,(int)(n/2))+BD); 
    }
}

int main()
{
    int x,y,n;//输入的两个数和位数
    cout<<"请输入两个数和位数，用空格隔开："<<endl;
    cin>>x>>y>>n;
    cout<<"x 和 y的乘积为："<<divideConquer(x,y,n)<<endl;
    return 0;
}
//测试案例 1234 5678 4 
