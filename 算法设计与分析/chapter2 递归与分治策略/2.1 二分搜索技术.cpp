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
	return -1;//û�ҵ�λ�� 
}

int main()
{
	int a[]={1,11,21,31,41,51,61,71,81,91};
	int n=sizeof(a)/sizeof(a[0]);
	int x;
	cout<<"������һ����: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";//��ʾ 
	cout<<endl;
	
	cout<<"������Ҫ���ҵ�Ԫ�أ�";
	cin>>x;
	cout<<"Ҫ���ҵ�Ԫ����ֵΪ:"<<x<<endl;
	int result=binarySearch(a,x,n);
	if (result==-1)
		cout<<"\nû���ڸ��б����ҵ���Ԫ��!"<<endl;
	else
		cout<<"\n��Ԫ�����б��е��±�Ϊ: "<<result<<endl;
	return 0;
}

