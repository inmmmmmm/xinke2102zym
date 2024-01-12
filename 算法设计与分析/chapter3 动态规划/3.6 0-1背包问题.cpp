#include <iostream>
using namespace std;

class Knapsack 
{
    public:
    int n; // 物品的个数
    int* w; // 物品的重量
    int* val; // 物品的价值
    int m; // 背包的容量
    int** v; // v[i][j]表示在前i个物品中能够装入容量为j的背包中的最大价值
    int** path; // path[i][j]表示第i个物品是否被放入了背包

    Knapsack(int n,int* w,int* val,int m)//构造函数，初始化数据
	{
        this->n=n;
        this->w=w;
        this->val=val;
        this->m=m;
        // 动态分配内存空间
        v=new int*[n+1];
        path=new int*[n+1];
        for(int i=0;i <=n;i++) 
		{
            v[i]=new int[m+1];
            path[i]=new int[m+1];
        }
        // 初始化第一行和第一列为0
        for(int i=0;i<=n;i++)
            v[i][0]=0;
        for(int i=0;i<=m;i++) 
            v[0][i]=0;
    }

    // 析构函数，释放内存空间
    ~Knapsack() 
	{
        for(int i=0; i<=n;i++)
		{
            delete[]v[i];
            delete[]path[i];
        }
        delete[]v;
        delete[]path;
    }

    // 计算背包问题的最优解
    int polyMax()
	{
        for(int i=1;i<=n;i++) 
		{
            for(int j=1;j<=m;j++) 
			{
                if(w[i-1]>j)
                    v[i][j] = v[i-1][j];
				else
				{
                    if (v[i-1][j]<val[i-1]+v[i-1][j-w[i-1]]) 
					{
                        v[i][j]=val[i-1]+v[i-1][j-w[i-1]];
                        // 把当前的情况记录到path中
                        path[i][j]=1;
                    } 
					else 
                        v[i][j]=v[i-1][j];
                }
            }
        }
        // 返回最大值
        return v[n][m];
    }

    // 输出选择的商品
    void printItems()
	{
        int i=n;
        int j=m;
        while (i>0 && j>0) 
		{
            if (path[i][j]==1) 
			{
                cout<<"第"<<i<<"个商品放入到背包"<<endl;
                j-=w[i-1];
            }
            i--;
        }
    }
};

int main() 
{
    int n=3;// 物品的个数
    int w[]={1,4,3}; // 物品的重量
    int val[]={15,30,20}; // 物品的价值
    int m=5;// 背包的容量
    
    Knapsack ks(n,w,val,m);
    // 计算并输出最大值
    int maxv=ks.polyMax();
    cout<<"最大值为： "<<maxv<<endl;
    // 输出选择的商品
    ks.printItems();
    return 0;
}

