#include<iostream>
#include<cmath>
using namespace std;

const int N=10;//���޻ʺ���� 
int n;//ʵ�ʻʺ���� 
int x[N];//��Żʺ�λ�ã�x[i]::��i�еĻʺ���ڵ�x[i]��
int count=0;//��ĸ���

// �жϵ�k���ʺ��Ƿ���Է��ڵ�x[k]��
bool place(int k)
{
    for(int i=1; i<k;i++)
	{
    	if(x[i]==x[k] || abs(x[i]-x[k])==abs(i-k))
		{
            return false;//��ͬһ�л�ͬһ�Խ�����
        }
    }
    return true;
}

// ���ݷ����n������
void backtrack(int k)
{
    if(k>n)//����Ѿ�������n���ʺ�,��ֱ�������
	{
    	count++;
        cout<<"��"<<count<<":"<<endl;
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
	else//�ڵ�k�е�ÿһ�з��õ�k���ʺ�
	{
        for(int i=1;i<=n;i++)
		{
            x[k]=i;//����k���ʺ���ڵ�i��
            if(place(k))//���Է��� 
                backtrack(k+1);
        }
    }
}

int main()
{
    cout<<"������ʺ���(n): ";
    cin>>n;
    backtrack(1);//��1��ʼ 
    cout<<"�������һ���У�"<<count<<"��"<<endl;
    return 0;
}

