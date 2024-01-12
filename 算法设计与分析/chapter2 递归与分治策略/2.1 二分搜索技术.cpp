#include <iostream>
using namespace std;

int binarySearch(int a[], int x, int n)
{
	int left=0;
	int right=n-1;
	while (left<=right)
	{
		int mid=(left+right)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			right=mid-1;
		else
			left=mid+1;
	}
	return -1;//没找到位置 
}

int main()
{
	int a[]={1,11,21,31,41,51,61,71,81,91};
	int n=sizeof(a)/sizeof(a[0]);
	int x;
	cout<<"请输入一组数: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";//显示 
	cout<<endl;
	
	cout<<"请输入要查找的元素：";
	cin>>x;
	cout<<"要查找的元素数值为:"<<x<<endl;
	int result=binarySearch(a,x,n);
	if (result==-1)
		cout<<"\n没有在该列表中找到该元素!"<<endl;
	else
		cout<<"\n该元素在列表中的下标为: "<<result<<endl;
	return 0;
}

