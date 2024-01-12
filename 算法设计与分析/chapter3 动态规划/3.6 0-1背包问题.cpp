#include <iostream>
using namespace std;

class Knapsack 
{
    public:
    int n; // ��Ʒ�ĸ���
    int* w; // ��Ʒ������
    int* val; // ��Ʒ�ļ�ֵ
    int m; // ����������
    int** v; // v[i][j]��ʾ��ǰi����Ʒ���ܹ�װ������Ϊj�ı����е�����ֵ
    int** path; // path[i][j]��ʾ��i����Ʒ�Ƿ񱻷����˱���

    Knapsack(int n,int* w,int* val,int m)//���캯������ʼ������
	{
        this->n=n;
        this->w=w;
        this->val=val;
        this->m=m;
        // ��̬�����ڴ�ռ�
        v=new int*[n+1];
        path=new int*[n+1];
        for(int i=0;i <=n;i++) 
		{
            v[i]=new int[m+1];
            path[i]=new int[m+1];
        }
        // ��ʼ����һ�к͵�һ��Ϊ0
        for(int i=0;i<=n;i++)
            v[i][0]=0;
        for(int i=0;i<=m;i++) 
            v[0][i]=0;
    }

    // �����������ͷ��ڴ�ռ�
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

    // ���㱳����������Ž�
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
                        // �ѵ�ǰ�������¼��path��
                        path[i][j]=1;
                    } 
					else 
                        v[i][j]=v[i-1][j];
                }
            }
        }
        // �������ֵ
        return v[n][m];
    }

    // ���ѡ�����Ʒ
    void printItems()
	{
        int i=n;
        int j=m;
        while (i>0 && j>0) 
		{
            if (path[i][j]==1) 
			{
                cout<<"��"<<i<<"����Ʒ���뵽����"<<endl;
                j-=w[i-1];
            }
            i--;
        }
    }
};

int main() 
{
    int n=3;// ��Ʒ�ĸ���
    int w[]={1,4,3}; // ��Ʒ������
    int val[]={15,30,20}; // ��Ʒ�ļ�ֵ
    int m=5;// ����������
    
    Knapsack ks(n,w,val,m);
    // ���㲢������ֵ
    int maxv=ks.polyMax();
    cout<<"���ֵΪ�� "<<maxv<<endl;
    // ���ѡ�����Ʒ
    ks.printItems();
    return 0;
}

