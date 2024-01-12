#include<iostream> 
#include <string>
#include <algorithm>
using namespace std;

//测试案例：
//A:abcbdab  B:bdcaba 
string s1,s2;
int b[1000][1000];//用于辅助记录


void PrintLCS(int m,int n)//打印最长公共子串子串
{
    if(n==0 || m==0)
        return;
    if(b[n][m]==1)
	{
        PrintLCS(m-1,n-1);
        cout<<s1[m-1];
    }
	else if(b[n][m]==2)
        PrintLCS(m-1,n);
	else
        PrintLCS(m,n-1);
}

int main() 
{
	cout<<"请输入第一组序列A："<<endl; 
    cin>>s1;
    cout<<"请输入第二组序列B："<<endl; 
    cin>>s2;
   
    int m=s1.size();
    int n=s2.size();
    
    int dp[n+1][m+1];

    for(int i = 0; i<n+1;i++)
		dp[i][0]=0;
    for(int i=0;i<m+1;i++)
		dp[0][i]=0;

    for(int i=1;i<n+1;i++)
	{
        for(int j=1;j<m+1;j++)
		{
            if(s1[j-1]==s2[i-1])
			{
                dp[i][j]=dp[i-1][j-1]+1;
                b[i][j]=1;
            }
			else if(dp[i][j-1]>dp[i-1][j])
			{
                dp[i][j]=dp[i][j-1];
                b[i][j] = 2;
            }
			else
			{
                dp[i][j] = dp[i-1][j];
                b[i][j] = 3;
            }
        }
    }
    PrintLCS(m, n);

    return 0;
}
