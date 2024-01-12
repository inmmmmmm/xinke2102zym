#include <iostream>
using namespace std;

int n;
int m[101][101][2];
char op[101];
int v[101];
int minf,maxf;
int minv;

void MinMax(int i,int s,int j)
{
    int e[5];
    int a=m[i][s][0], b=m[i][s][1];
    int r=(i+s-1)%n+1,c=m[r][j-s][0],d=m[r][j-s][1];//c为最小值 d为最大值 
    if(op[r]=='+')
	{
        minf=a+c;
        maxf=b+d;
    } 
	else
	{
        e[1]=a*c;
        e[2]=a*d;
        e[3]=b*c;
        e[4]=b*d;
        minf=e[1];
        maxf=e[1];
        for(int k=2; k<5;k++) 
		{
            if(minf>e[k])
				minf=e[k];
            if(maxf<e[k])
				maxf=e[k];
        }
    }
}

int polyMax() 
{
    for(int j=2;j<=n;j++) 
	{
        for(int i=1;i<=n;i++)
		{
            for(int s=1;s<j;s++)
			 {
                MinMax(i,s,j);
                if(m[i][j][0]>minf)
					m[i][j][0] = minf;
                if(m[i][j][1]<maxf)
					m[i][j][1] = maxf;
            }
        }
    }
    int temp=m[1][n][1];
    minv=m[1][n][0];//用来存储最小值 
    for(int i=2;i<=n;i++) 
	{
        if (temp<m[i][n][1]) 
			temp=m[i][n][1];
		if (minv>m[i][n][0]) 
			minv=m[i][n][0];
    }
    return temp;
}

int main() 
{
    n=4;
    for(int i=0; i<=n;i++)
	{
        for(int j=0; j<=n;j++) 
		{
            m[i][j][0]=0;
            m[i][j][1]=0;
        }
    }
    op[0]='+';
    op[1]='*';
    op[2]='+';
    op[3]='*';
    op[4]='+';
    v[1]=2;
    v[2]=3;
    v[3]=4;
    v[4]=5;
    for (int i=1;i<=4;i++) 
	{
        m[i][1][0]=v[i];
        m[i][1][1]=v[i];
    }
    int maxv=polyMax();
    cout<<"最大值为： "<<maxv<<endl;
    cout<<"最小值为： "<<minv<<endl;
    return 0;
}


