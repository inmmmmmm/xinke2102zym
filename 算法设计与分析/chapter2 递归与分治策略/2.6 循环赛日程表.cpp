#include <iostream>
using namespace std;

//生成赛事表  赛事表arr[][] 运动员人数n=2^k
void Table(int**arr,int n)//下标从1开始
{
	arr[1][1]=1;
	arr[1][2]=2;
	arr[2][1]=2;
	arr[2][2]=1;

	int i,j,half;
	// 循环 依次处理 2^2 ... 2^k个选手比赛日程
	int num=2;//当前选手数
	while(num<n)
	{
		half=num;//当前选手的一半
		num=num*2;//当前选手数(第一次循环4个选手)

		//处理右下角
		for(i=half+1;i<=num;i++)//行
			for(j=half+1;j<=num;j++)//列
				arr[i][j]=arr[i-half][j-half];

		//处理左下角
		for(i=half+1;i<=num;i++)
			for (j=1; j<=half;j++)
				arr[i][j] =arr[i-half][j]+half;//这里第一次循环变成3,4号选手

		//处理右上角
		for(i=0;i<=half;i++)
			for(j=half+1;j<=num;j++)
				arr[i][j] =arr[i+half][j-half];
	}
}

int main()
{
	int** arr=new int*[9];
	for(int i=0;i<9;i++) 
		arr[i]=new int[9]; //为每一行分配内存
	Table(arr,8);
	for(int i=1;i<=8;i++) 
	{
		for(int j=1;j<=8;j++)
		{
			if(j==1)
				cout<<arr[i][j]<<"号  ";
			else
				cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
	//释放内存
	for(int i=0;i<9;i++) 
		delete[]arr[i];
	delete[]arr;
	return 0;
}

