#include <iostream>
#include <cmath>
using namespace std;

// �ϲ�a[1:m]��a[m+1:r]��b[1:r] 
void merge(int a[],int b[],int m,int n,int r)
{
    int i=m,j=n+1,k=m;
    while((i <= n) && (j <= r))
	{
        if (a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    if (i>n)
	{
        for(int q=j;q<=r;q++) 
            b[k++]=a[q];
    }
    else
	{
        for(int q = i; q <= n; q++)
            b[k++] = a[q];
    }
}

//���������һ�˹鲢
void mergePass(int x[],int y[],int s,int n)
{
    int i=0;
    while(i<=n-2*s)
	{
        merge(x,y,i,i+s-1,i+2*s-1);
        i=i+2*s;
    }
    if(i+s<n)
        merge(x,y,i,i+s-1,n-1);
    else
	{
        for(int j=i;j<n;j++)
            y[j]=x[j];
    }
}

// ��������й鲢����
void mergeSort(int a[],int n)
{
    int*b=new int[n];//��̬����
    int s=1;
    while(s<n)
	{
        mergePass(a,b,s,n);
        // ���һ�˹鲢��Ľ��
        cout<<"�鲢�������Ϊ��"<<endl;
        for(int i=0;i<n;i++)
        	cout<<b[i]<<" ";
        cout<<endl;
        s+=s;
        mergePass(b,a,s,n);
        // ���һ�˹鲢��Ľ��
        cout<<"�鲢�������Ϊ��"<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        s+=s;
    }
    delete[]b;//�ͷ�
}

int main()
{
    int a[]={4,8,3,7,9,5,2,6};
    int n=sizeof(a)/sizeof(a[0]);//��������ĳ���
    cout<<"����ǰ��"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    mergeSort(a,n);
    cout<<"�ݹ�ʵ�ֺϲ������"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

