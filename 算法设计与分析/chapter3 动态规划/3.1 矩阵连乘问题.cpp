#include<iostream>
#include<iomanip>
using namespace std;

void matrixChain(int* p,int n,int** m,int** s)
{
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int r=2; r<=n;r++)
    {
        for(int i=1;i<=n-r+1;i++)
        {
            int j=i+r-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j; k++)
            {
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (t<m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void traceback(int** s,int i,int j)
{
    if(i==j)
        return;
    traceback(s,i,s[i][j]);
    traceback(s,s[i][j]+1,j);
    cout<<"Multiply A"<<i<<","<<s[i][j]<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
}

void Print(int** s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        Print(s, i, s[i][j]);
        Print(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int p[]={30,35,15,5,10,20,25};
    int n=sizeof(p)/sizeof(p[0])-1;
    int** m=new int*[n+1]; //创建一个二维数组
    int** s=new int*[n+1];
    for (int i=0;i<=n;i++) 
	{
        m[i]=new int[n+1]; //为每一行分配内存
        s[i]=new int[n+1];
    }
    matrixChain(p,n,m,s);
    traceback(s,1,n);
    Print(s,1,n);
    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        for (int j = 1; j <= n; j++)
//            cout << setw(8) << m[i][j];
//        cout << endl;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//            cout << setw(2) << s[i][j];
//        cout << endl;
//    }
//    //释放内存
//    for (int i = 0; i <= n; i++) {
//        delete[] m[i];
//        delete[] s[i];
//    }
//    delete[] m;
//    delete[] s;
    return 0;
}

