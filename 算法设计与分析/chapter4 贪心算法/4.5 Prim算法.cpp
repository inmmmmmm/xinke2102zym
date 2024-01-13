/*�������� 
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
    int minDist[MAX]; //minDist[i]:��ʾ��iΪ�յ�ıߵ���СȨֵ,��minDist[i]==0��ʾi�������S 
    int parent[MAX]; //��ʾ��ӦminDist[i]�����
    int i, j, min, minid, sum = 0;
    for (i = 2; i <= n; i++)
    {
        minDist[i] = graph[1][i];//lowcost��Ŷ���1�ɴ���·������
        parent[i] = 1;//��ʼ����1λ��ʼ��
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
                min = minDist[j];//�ҳ�Ȩֵ��̵�·������
                minid = j; //�ҳ���С��ID
            }
        }
        printf("V%d-V%d=%d\n",parent[minid],minid,min);
        sum += min;//���
        minDist[minid] = 0;//�ô����·����Ϊ0,����MST
		 
        for (j = 2; j <= n; j++)
        {
            if (graph[minid][j] < minDist[j])//����һ��ֱ��Ķ������·������
            {
                minDist[j] = graph[minid][j];
                parent[j] = minid;
            }
        }
    }
    printf("��СȨֵ֮��=%d\n",sum);
}
 
int main()
{
    int i, j, k, m, n;
    int x, y, cost;
    scanf("%d%d",&m,&n);//m=����ĸ�����n=�ߵĸ���
 
	//��ʼ��ͼ
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m; j++)
        {
            graph[i][j] = MAXCOST;
        }
    }
    //����ͼ 
    for (k = 1; k <= n; k++)
    {
    scanf("%d%d%d",&i,&j,&cost);
        graph[i][j] = cost;
        graph[j][i] = cost;
    }
 
    prim(graph, m);
    return 0;
}
 
 
 
