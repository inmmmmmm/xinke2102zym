//Project2: ��������

#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

const int length = 6;
int m = length,
    n = length,
    grid[length+2][length + 2];   

struct Position{
    int row, col;
};

void Print(){
    for (int i = 1; i < length+1; i++){
        for (int j = 1; j < length + 1; j++)
            cout << setw(3) << grid[i][j];
        cout << endl;
    }
    cout << endl;
}

bool FindPath(Position start, Position finish, int& PathLen, Position*& path){

    Position nextStep[4];
    nextStep[0].row = 0;nextStep[0].col = 1;//��
    nextStep[1].row = 1;nextStep[1].col = 0;//��
    nextStep[2].row = 0; nextStep[2].col = -1;//��
    nextStep[3].row = -1;nextStep[3].col = 0;//��

    Position here, next;
    here.row = start.row;
    here.col = start.col;
    grid[start.row][start.col] = 1;
    queue<Position> Q;

    while (true){ //������ڿɴ﷽��
        for (int i = 0; i < 4; i++){  //�����ĸ� 
            next.row = here.row + nextStep[i].row;
            next.col = here.col + nextStep[i].col;
            if (grid[next.row][next.col] == 0 && next.row != -1 && next.col != -1){ 
                grid[next.row][next.col] = grid[here.row][here.col] + 1; 		
                if ((next.row == finish.row) && (next.col == finish.col)) 
                    break; 

                Q.push(next);
            }
        }
        //��������
        if ((next.row == finish.row) && (next.col == finish.col)) 
            break;
        if (Q.empty()) return false;

        here = Q.front();
        Q.pop();

    }
    PathLen = grid[finish.row][finish.col];
    path = new Position[PathLen];
    //����
    here = finish;
    for (int j = PathLen - 1; j >= 0; j--){
        path[j] = here;
        //�����ķ���
        for (int i = 0; i < 4; i++){
            next.row = here.row + nextStep[i].row;
            next.col = here.col + nextStep[i].col;
            if (grid[next.row][next.col] == j){
                break;
            }
        }
        here = next;
    }
    return PathLen;
}
int main(){
    int countNum = 0;
    //�谭
    grid[2][3] =  grid[3][4] = grid[3][5] = grid[4][2] = -1;

    Position start;//��ʼ
    start.row = 2; start.col = 1;
    cout << "�������:"
        << " "  << start.row
        << " " << start.col << endl;

    Position finish;//����
    finish.row = 4;finish.col = 6;
    cout << "�����յ�:"
        << " "  << finish.row
        << " " << finish.col << endl;

    Position* path;
    FindPath(start, finish, countNum, path);
    cout << "\n���ս��: " << endl;
    Print();
    //���ս��
    cout << "·�����ȣ� " << countNum - 1<< endl;
    for (int i = 1; i < countNum; i++){
        cout << "->(" << path[i].row
            << "," << path[i].col << ")";
    }
    cout << endl;

    return 0;
}
