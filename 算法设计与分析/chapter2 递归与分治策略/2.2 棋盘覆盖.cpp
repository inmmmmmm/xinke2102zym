#include <iostream>
#include<iomanip> 
using namespace std;

static int tile=1;
static int size=8;
static int board[8][8];//8*8������ 

void chessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size==1)
        return;
    int t=tile++;//L�͹��ƺ� 
	int s=size/2;//�ָ����� 
	
    if(dr<tr+s && dc<tc+s)//���Ͻ� 
        chessBoard(tr,tc,dr,dc,s);
    else//�����ⷽ�� 
    {
        board[tr+s-1][tc+s-1]=t;
        chessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    
    if(dr<tr+s && dc>=tc+s)//���Ͻ� 
        chessBoard(tr,tc+s,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s]=t;
        chessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    
    if (dr>=tr+s && dc<tc+s)//���½� 
        chessBoard(tr + s, tc, dr, dc, s);
    else
    {
        board[tr+s][tc+s-1]=t;
        chessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    
    if (dr>=tr+s && dc>=tc+s)//���½� 
        chessBoard(tr+s,tc+s,dr,dc,s);
    else
    {
        board[tr+s][tc+s]=t;
        chessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}

int main()
{
    board[2][2]=0;
    chessBoard(0,0,2,2,size);//���� 
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout<<setw(5)<<board[i][j];//ʹ��ͷ�ļ�<iomanip>���setw�������������� 
        cout<<endl;
    }
    return 0;
}


