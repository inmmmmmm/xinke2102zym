#include<iostream> 
using namespace std;

#define N 7 
#define M 3 
int s[M]={0,0,0};
 
 
//���Ŀǰ������ҵ��ʱ��� ��С�Ļ����� 
int min(int m)
{
	int min=0;
	int i;
	for(i=1;i<m;i++)
	{
		if(s[min]>s[i])
			min=i;
	}
	return min;
}

//�����ս���������ʱ�䣩 
int max(int s[],int num)
{
	int max=s[0];
	for(int i=1;i<num;i++)
	{
		if(max<s[i])
			max=s[i];
	}
	return max;
}

//���������ڴ�������ҵ�� 
int setwork1(int t[], int n)
{
	int i=0;
	for(;i<n;i++)
		s[i]=t[i];
	int ma=max(s,N);
	return ma;
}

//������С�ڴ�������ҵ�� 
int setwork2(int t[],int n)
{
	int i;
	int mi=0;
	for (i=0;i<n;i++)
	{
		mi=min(M);
		cout<<"��������"<<mi+1<<"�Ż�����������"<<i+1<<endl;
		s[mi]=s[mi]+t[i];
	}
		int ma=max(s,M);
	return ma;
}

int main()
{
	int time[N]={16,14,6,5,4,3,2};//����ʱ�䰴�Ӵ�С���� 
	int maxtime;
	if(M>=N)
		maxtime=setwork1(time,N);
	else
		maxtime=setwork2(time,N);
	cout<<"���ķ�ʱ��"<<maxtime<<endl;
}

