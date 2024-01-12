#include <iostream>
#include <algorithm>
using namespace std;

int partition(int array[],int low,int high)
{
    int pivot=array[high];
    int pointer=low;
    for(int i=low;i<high;i++) 
	{
        if(array[i]<=pivot) 
		{
            swap(array[i],array[pointer]);
            pointer++;
        }
    }
    swap(array[pointer],array[high]);
    return pointer;
}

void quickSort(int array[],int low,int high) 
{
    if (low<high) 
	{
        int position=partition(array,low,high);
        quickSort(array,low,position-1);
        quickSort(array,position+1,high);
    }
}

int main() 
{
    int array[]={4,8,3,7,9,5,2,6};
    int n=sizeof(array)/sizeof(array[0]);
    quickSort(array,0,n-1);
    cout<<"快速排序后的结果"<<endl;
    for(int i=0;i<n;i++)
        cout<<array[i]<<" ";
    cout<<endl;
    return 0;
}



