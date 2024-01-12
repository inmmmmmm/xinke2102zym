/*
5 7

1 2
1 4
1 5
2 3
2 5
3 5
4 5
*/
//书上例子 
#include<bits/stdc++.h>
using namespace std;

const int maxnum=101;
bool a[maxnum][maxnum];//图的邻接矩阵
bool x[maxnum]; //当前解
int cn;//当前团的顶点数
int bestn;//当前的最优解
int n;//图G的顶点数
int e;//图G的边数
void backtrack(int i)
{
    int j;
    if(i>n)
    {
        bestn=cn;
        cout<<"当前最优解为："<<bestn<<endl;
        cout<<"节点为：";
        for(j=1; j<=n; j++)
        {
            if(x[j])
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
        return ;
    }

    bool ok=true;
    for(j=1; j<i; j++)
    {
        if(x[j]&&!a[j][i])//i与j不相连
        {
            ok=false;
            break;
        }
    }
    if(ok)//进入左子树
    {
        cn++;
        x[i]=true;
        backtrack(i+1);
        cn--;
    }
    if(cn+n-i>bestn)  //剪枝
    {
        x[i]=false;
        backtrack(i+1);
    }
}

int main()
{
    int i,u,v;
    memset(a,false,sizeof(a));
    memset(x,false,sizeof(x));
    cout<<"请输入图的边数与顶点数"<<endl;
    cin>>n>>e;
    cout<<"接下来请输入结点index值"<<endl; 
    for(i=0; i<e; i++)
    {
        cin>>u>>v;
        a[u][v]=true;
        a[v][u]=true;
    }
    cn=bestn=0;
    backtrack(1);
    return 0;
}


