#include <iostream>
#include <algorithm>
using namespace std;

struct Element 
{
    float w;
    int i;
    Element(){} // 无参构造函数
    Element(float ww,int ii)
	{
        w=ww;
        i=ii;
    }
    bool operator<(const Element& x)const
	{
        return w<x.w;
    }
};

float maxloading(float c,float w[],int x[],int n) 
{
    Element d[n];
    for (int i=0;i<n;i++)
        d[i]=Element(w[i],i);
    sort(d,d+n);
    float opt=0;
    for (int i=0;i<n;i++)
        x[i]=0;
    for (int i=0;i<n && d[i].w<=c;i++)
	{
        x[d[i].i]=1;
        opt+=d[i].w;
        c-=d[i].w;
    }
    return opt;
}

int main() 
{
    float c=50;
    float w[]={10,20,30};
    int n = sizeof(w)/sizeof(w[0]);
    int x[n];
    float res = maxloading(c,w,x,n);
    cout<<"The maxLoading is "<<res<<endl;
    for(int i=0;i<n;i++)
        cout<<" ";
    return 0;
}

