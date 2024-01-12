#include <iostream>
#include <cmath>
using namespace std;

#define SIGN(A)((A>0)?1:-1) 

//�÷��η����������������ĳ˻�
int divideConquer(int X, int Y, int n)
{
    int sign=SIGN(X)*SIGN(Y);//��¼�˻��ķ���
    int x=abs(X);//ȡX�ľ���ֵ
    int y=abs(Y);//ȡY
    if(x==0 || y==0)//�����һ����Ϊ0
        return 0;
    else if(n==1) // ���ֻ��һλ����ֱ�����
        return sign*x*y;
    else
	{
        int A=(int)x/pow(10,(int)(n/2));
        int B=x-A*pow(10,n/2);
        int C=(int)y/pow(10,(int)(n/2));
        int D=y-C*pow(10,n/2);
        // �ݹ����AC, BD��(A-B)(D-C) + AC + BD
        int AC=divideConquer(A,C,n/2);
        int BD=divideConquer(B,D,n/2);
        int ABDC=divideConquer((A-B),(D-C),n/2)+AC+BD;
        // ���س˻��Ľ��
        return sign*(AC*pow(10,n)+ABDC*pow(10,(int)(n/2))+BD); 
    }
}

int main()
{
    int x,y,n;//�������������λ��
    cout<<"��������������λ�����ÿո������"<<endl;
    cin>>x>>y>>n;
    cout<<"x �� y�ĳ˻�Ϊ��"<<divideConquer(x,y,n)<<endl;
    return 0;
}
//���԰��� 1234 5678 4 
