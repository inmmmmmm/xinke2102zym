#include <iostream>
using namespace std;

const int N=10;
void MNS(int c[],int n,int **size);
void Traceback(int c[],int **size,int n,int net[],int &m);

int main()
{
	int c[]={0,8,7,4,2,5,1,9,3,10,6};
	int **size=new int*[N+1];
	for(int i=0;i<=N;i++)
	{
		size[i]=new int[N+1];
	}
	MNS(c,N,size);
	cout<<"最大不相交连接数目为"<<size[N][N]<<endl;
	int net[N],m;
	Traceback(c,size,N,net,m);
	cout<<"最大不相交连接线分别为:"<<endl;
	for(int i=m-1;i>=0;i--)
	{
		cout<<"("<<net[i]<<","<<c[net[i]]<<")";
		
	} 
	cout<<endl;
	
}

void MNS(int c[],int n,int **size)
{
	for(int j=0;j<c[1];j++)
		size[1][j]=0;
	for(int j=c[1];j<=n;j++)
	{
		size[1][j]=1;	
	} 
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<c[i];j++)
		{
			size[i][j]=size[i-1][j];
		}
		for(int j=c[i];j<=n;j++)
		{
			size[i][j]=max(size[i-1][j],size[i-1][c[i]-1]+1);
		}
		
	}
	size[n][n]=max(size[n-1][n],size[n-1][c[n]-1]+1);
}
	 
void Traceback(int c[],int **size,int n,int net[],int &m)
{
	int j=n;
	m=0;
	for(int i=n;i>1;i--)
	{
		if(size[i][j]!=size[i-1][j])
		{
			net[m++]=i;
			j=c[i]-1;
		}
	}
	
	if(j>=c[1])
	{
		net[m++]=1;
	}
}
