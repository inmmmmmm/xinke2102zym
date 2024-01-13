/*测试用例 
8 12
1 2 2
1 3 3
2 2 1
2 3 4
2 4 18
2 7 7
3 8 8
4 6 3
4 5 5
5 6 4
7 8 2
7 8 1
*/
#include<stdio.h>
#define MAX 100
#define MAXCOST 100000
 
int graph[MAX][MAX];
 
void prim(int graph[][MAX], int n)
{
    int minDist[MAX]; //minDist[i]:表示以i为终点的边的最小权值,当minDist[i]==0表示i点加入了S 
    int parent[MAX]; //表示对应minDist[i]的起点
    int i, j, min, minid, sum = 0;
    for (i = 2; i <= n; i++)
    {
        minDist[i] = graph[1][i];//lowcost存放顶点1可达点的路径长度
        parent[i] = 1;//初始化以1位起始点
    }
    parent[1] = 0;
    minDist[1] = 0;
    
    for (i = 2; i <= n; i++)
    {
        min = MAXCOST;
        minid = 0;
        for (j = 2; j <= n; j++)
        {
            if (minDist[j] < min && minDist[j] != 0)
            {
                min = minDist[j];//找出权值最短的路径长度
                minid = j; //找出最小的ID
            }
        }
        printf("V%d-V%d=%d\n",parent[minid],minid,min);
        sum += min;//求和
        minDist[minid] = 0;//该处最短路径置为0,加入MST
		 
        for (j = 2; j <= n; j++)
        {
            if (graph[minid][j] < minDist[j])//对这一点直达的顶点进行路径更新
            {
                minDist[j] = graph[minid][j];
                parent[j] = minid;
            }
        }
    }
    printf("最小权值之和=%d\n",sum);
}
 
int main()
{
    int i, j, k, m, n;
    int x, y, cost;
    scanf("%d%d",&m,&n);//m=顶点的个数，n=边的个数
 
	//初始化图
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m; j++)
        {
            graph[i][j] = MAXCOST;
        }
    }
    //输入图 
    for (k = 1; k <= n; k++)
    {
    scanf("%d%d%d",&i,&j,&cost);
        graph[i][j] = cost;
        graph[j][i] = cost;
    }
 
    prim(graph, m);
    return 0;
}
 
 
 
