#include <iostream>
using namespace std;

//�������±�  ���±�arr[][] �˶�Ա����n=2^k
void Table(int**arr,int n)//�±��1��ʼ
{
	arr[1][1]=1;
	arr[1][2]=2;
	arr[2][1]=2;
	arr[2][2]=1;

	int i,j,half;
	// ѭ�� ���δ��� 2^2 ... 2^k��ѡ�ֱ����ճ�
	int num=2;//��ǰѡ����
	while(num<n)
	{
		half=num;//��ǰѡ�ֵ�һ��
		num=num*2;//��ǰѡ����(��һ��ѭ��4��ѡ��)

		//�������½�
		for(i=half+1;i<=num;i++)//��
			for(j=half+1;j<=num;j++)//��
				arr[i][j]=arr[i-half][j-half];

		//�������½�
		for(i=half+1;i<=num;i++)
			for (j=1; j<=half;j++)
				arr[i][j] =arr[i-half][j]+half;//�����һ��ѭ�����3,4��ѡ��

		//�������Ͻ�
		for(i=0;i<=half;i++)
			for(j=half+1;j<=num;j++)
				arr[i][j] =arr[i+half][j-half];
	}
}

int main()
{
	int** arr=new int*[9];
	for(int i=0;i<9;i++) 
		arr[i]=new int[9]; //Ϊÿһ�з����ڴ�
	Table(arr,8);
	for(int i=1;i<=8;i++) 
	{
		for(int j=1;j<=8;j++)
		{
			if(j==1)
				cout<<arr[i][j]<<"��  ";
			else
				cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
	//�ͷ��ڴ�
	for(int i=0;i<9;i++) 
		delete[]arr[i];
	delete[]arr;
	return 0;
}

