// 测试案例 
//10 5 
//7 2 6 5 4
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
 
#define NUM 100
int n;
int c;
int w[NUM];
 
int MaxLoading()
{
	queue<int> Q;
	Q.push(-1);
	int i = 0;
	int Ew = 0;
	int bestw = 0;
	int r = 0;
	for(int j=1; j<n; j++)
		r += w[j];
	while (true)
	{
		int wt = Ew+w[i];
		if (wt<=c)
		{
			if (wt>bestw) bestw = wt;
			if (i<n-1) Q.push(wt);
		}
		if (Ew+r>bestw && i<n-1) Q.push(Ew);
		Ew = Q.front();
		Q.pop();
		if (Ew==-1)
		{
			if (Q.empty()) return bestw;
			Q.push(-1);
			Ew = Q.front();
			Q.pop();
			i++;
			r -= w[i];
		}
	}
	return bestw;
}
 
int main()
{
	cout<<"请输入载重量和集装箱的数量" <<endl;
	while(cin>>c>>n)
	{
		cout<<"请输入集装箱重量"<<endl;
		for(int i=0; i<n; i++)
			cin>>w[i];
		int ans  =  MaxLoading();
		if(ans) cout<<"最大载重"<<ans<<endl;
		else cout<<"No answer!"<<endl;
	}
	return 0;
}
