#include <iostream>
#include <cmath>
using namespace std;

// 合并a[1:m]和a[m+1:r]到b[1:r] 
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

//对数组进行一趟归并
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

// 对数组进行归并排序
void mergeSort(int a[],int n)
{
    int*b=new int[n];//动态分配
    int s=1;
    while(s<n)
	{
        mergePass(a,b,s,n);
        // 输出一趟归并后的结果
        cout<<"归并后的数组为："<<endl;
        for(int i=0;i<n;i++)
        	cout<<b[i]<<" ";
        cout<<endl;
        s+=s;
        mergePass(b,a,s,n);
        // 输出一趟归并后的结果
        cout<<"归并后的数组为："<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        s+=s;
    }
    delete[]b;//释放
}

int main()
{
    int a[]={4,8,3,7,9,5,2,6};
    int n=sizeof(a)/sizeof(a[0]);//计算数组的长度
    cout<<"排序前："<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    mergeSort(a,n);
    cout<<"递归实现合并排序后："<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

