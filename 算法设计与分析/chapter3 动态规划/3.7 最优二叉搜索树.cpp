#include<iostream>
using namespace std;

#define N 5//关键字的最大个数 

double C[N+1][N+1];//存储最优二叉搜索树的平均查找代价
int R[N+1][N+1];//存储最优二叉搜索树的根节点
double OptimalBST(double p[ ],int n)
{
    int i,j,k,d,mink;
    double min,sum;
    for (i=1;i<=n;i++)               
    {
        C[i][i-1]=0;
        C[i][i]=p[i-1];
        R[i][i]=i;
    }
    C[n][n-1]=0;
    for (d=1;d<n;d++)               
        for (i=1;i<=n-d;i++)
        {
            j=i+d;
            min=1000;
            mink=i;
            sum=0;    
            for(k=i;k<=j;k++)
            {
                sum=sum+p[k-1];
                if(C[i][k-1]+C[k+1][j]<min)
                {
                    min=C[i][k-1]+C[k+1][j];
                    mink=k;
                }
            }
            C[i][j]=min+sum;
            R[i][j]=mink;
        }
    return C[1][n];
}
int main()
{
    int i,j;
    double p[]={0.1,0.2,0.4,0.3};//存储的是关键字的访问概率 
    cout<<OptimalBST(p,4)<<endl;
    for(i=1;i<6;i++)//输出C数组的内容，用来查看每个子问题的最优代价
    {
        for(j=0;j<5;j++)
            cout<<C[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<6;i++)//输出R数组的内容，用来查看每个子问题的最优根节点
    {
        for(j=0;j<5;j++)
            cout<<R[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}

