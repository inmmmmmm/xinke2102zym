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
//�������� 
#include<bits/stdc++.h>
using namespace std;

const int maxnum=101;
bool a[maxnum][maxnum];//ͼ���ڽӾ���
bool x[maxnum]; //��ǰ��
int cn;//��ǰ�ŵĶ�����
int bestn;//��ǰ�����Ž�
int n;//ͼG�Ķ�����
int e;//ͼG�ı���
void backtrack(int i)
{
    int j;
    if(i>n)
    {
        bestn=cn;
        cout<<"��ǰ���Ž�Ϊ��"<<bestn<<endl;
        cout<<"�ڵ�Ϊ��";
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
        if(x[j]&&!a[j][i])//i��j������
        {
            ok=false;
            break;
        }
    }
    if(ok)//����������
    {
        cn++;
        x[i]=true;
        backtrack(i+1);
        cn--;
    }
    if(cn+n-i>bestn)  //��֦
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
    cout<<"������ͼ�ı����붥����"<<endl;
    cin>>n>>e;
    cout<<"��������������indexֵ"<<endl; 
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


