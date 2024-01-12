#include<iostream>
#include<cmath>
using namespace std;

const int N=10;//上限皇后个数 
int n;//实际皇后个数 
int x[N];//存放皇后位置，x[i]::第i行的皇后放在第x[i]列
int count=0;//解的个数

// 判断第k个皇后是否可以放在第x[k]列
bool place(int k)
{
    for(int i=1; i<k;i++)
	{
    	if(x[i]==x[k] || abs(x[i]-x[k])==abs(i-k))
		{
            return false;//在同一列或同一对角线上
        }
    }
    return true;
}

// 回溯法求解n后问题
void backtrack(int k)
{
    if(k>n)//如果已经放置了n个皇后,则直接输出解
	{
    	count++;
        cout<<"解"<<count<<":"<<endl;
        for(int i=1;i<=n;i++)
		{
            for(int j=1;j<=n;j++)
			{
                if(x[i]==j)
                    cout << "q ";
				else
                    cout << ". "; 
            }
            cout<<endl;
        }
        cout<<endl;
    }
	else//在第k行的每一列放置第k个皇后
	{
        for(int i=1;i<=n;i++)
		{
            x[k]=i;//将第k个皇后放在第i列
            if(place(k))//可以放置 
                backtrack(k+1);
        }
    }
}

int main()
{
    cout<<"请输入皇后数(n): ";
    cin>>n;
    backtrack(1);//从1开始 
    cout<<"解决方案一共有："<<count<<"个"<<endl;
    return 0;
}

