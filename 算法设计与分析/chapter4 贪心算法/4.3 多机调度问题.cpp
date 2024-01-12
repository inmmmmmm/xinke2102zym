#include<iostream> 
using namespace std;

#define N 7 
#define M 3 
int s[M]={0,0,0};
 
 
//求出目前处理作业的时间和 最小的机器号 
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

//求最终结果（最长处理时间） 
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

//机器数大于待分配作业数 
int setwork1(int t[], int n)
{
	int i=0;
	for(;i<n;i++)
		s[i]=t[i];
	int ma=max(s,N);
	return ma;
}

//机器数小于待分配作业数 
int setwork2(int t[],int n)
{
	int i;
	int mi=0;
	for (i=0;i<n;i++)
	{
		mi=min(M);
		cout<<"接下来由"<<mi+1<<"号机器处理任务"<<i+1<<endl;
		s[mi]=s[mi]+t[i];
	}
		int ma=max(s,M);
	return ma;
}

int main()
{
	int time[N]={16,14,6,5,4,3,2};//处理时间按从大到小排序 
	int maxtime;
	if(M>=N)
		maxtime=setwork1(time,N);
	else
		maxtime=setwork2(time,N);
	cout<<"最多耗费时间"<<maxtime<<endl;
}

