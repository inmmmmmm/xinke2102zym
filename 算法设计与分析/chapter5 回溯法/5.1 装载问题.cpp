// ���԰��� 
//5 10 
//7 2 6 5 4
#include<iostream>
#include<algorithm>
using namespace std;

int n,c;//��װ�������ִ���������
int*a;//������
bool*b;//����Ƿ�ѡ��
int sum,minn;//��ǰ�����������������

void f(int k) 
{
  if(k==n+1)
  {
    if(sum>minn)
      minn=sum;
    if(minn==c)
	{
      cout<<minn<<endl;
      exit(0);
    }
    return;
  }
  for(int i=k;i<=n;i++)
  {
    if(sum==c)
	{
      cout<<c<<endl;
      exit(0);
    }
    if(b[i])
      continue;
    if(a[i]+sum<=c)
	{
      b[i]=true;
      sum+=a[i];
      f(k+1);
      b[i]=false;
      sum-=a[i];
    }
	else
      f(n+1);
  }
}

int main()
{
  cout<<"������ n����װ������c���ִ���������"<<endl;
  cin>>n>>c;
  a=new int[n+1];
  b=new bool[n+1];
  fill(b,b+n+1,false);//��ʼ��false
  int ab=0;
  cout<<"�������������"<<endl;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    ab+=a[i];
    if(a[i]==c)
	 {
      cout<<c<<endl;
      return 0;
    }
  }
  if(ab<=c) 
  {
    cout<<ab<<endl;
    return 0;
  }
  sort(a+1,a+n+1);
  f(1);
  cout<<minn<<endl;
  delete[]a;
  delete[]b;
  return 0;
}



