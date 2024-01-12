#include <iostream>
using namespace std;

class Hanoi
{
    static int m; //��̬��Ա����m����¼�ƶ�����
public:
    static void move(int number,char N,char M)
	{
        cout<<"��" <<(++m)<<"���ƶ�:"<<"��"<<number<<"��Բ�̴�"<<N<<"�Ƶ�"<<M<<endl;
    }

    static void hanoi(int n,char A,char B,char C)//�����ϲ�ͬ ��������A-C 
	{
        if(n==1)
            Hanoi::move(1,A,C);
        else
        {
            hanoi(n-1,A,C,B);
            Hanoi::move(n,A,C);
            hanoi(n-1,B,A,C);
        }
    }

    static int getM()
	{
        return m;
    }
};

int Hanoi::m = 0; //��̬��Ա�����ĳ�ʼ��

int main()
{
    char a='A';
    char b='B';
    char c='C';
    cout<<"��ŵ�����⣺��A���ϱ�Ŵ�С�ŵ���ŵ�Բ�̴�A��ͨ��B�������ƶ���C����ȥ"<<endl;
    cout<<"������Բ�̵ĸ�����";
    int n;
    cin>>n;
    Hanoi::hanoi(n,a,b,c);
    cout<<"�ƶ���"<< Hanoi::getM()<<"�Σ���A�ϵ�Բ�̶��ƶ�����C��"<<endl; //��Hanoi::getM()����ȡm��ֵ
    return 0;
}

