#include <iostream>
using namespace std;

class Hanoi
{
    static int m; //静态成员变量m，记录移动次数
public:
    static void move(int number,char N,char M)
	{
        cout<<"第" <<(++m)<<"次移动:"<<"将"<<number<<"号圆盘从"<<N<<"移到"<<M<<endl;
    }

    static void hanoi(int n,char A,char B,char C)//和书上不同 我这里是A-C 
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

int Hanoi::m = 0; //静态成员变量的初始化

int main()
{
    char a='A';
    char b='B';
    char c='C';
    cout<<"汉诺塔问题：把A塔上编号从小号到大号的圆盘从A塔通过B辅助塔移动到C塔上去"<<endl;
    cout<<"请输入圆盘的个数：";
    int n;
    cin>>n;
    Hanoi::hanoi(n,a,b,c);
    cout<<"移动了"<< Hanoi::getM()<<"次，把A上的圆盘都移动到了C上"<<endl; //用Hanoi::getM()来获取m的值
    return 0;
}

