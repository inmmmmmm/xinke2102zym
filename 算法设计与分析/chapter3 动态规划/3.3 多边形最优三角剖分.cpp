#include <iostream>
using namespace std;

const int N = 7;
int w[N][N] = {{0,2,2,3,1,4},{2,0,1,6,2,3},{2,1,0,2,1,4},{3,5,2,0,6,2},{1,2,1,6,0,1},{4,3,4,2,1,0}};
int t[N][N];
int s[N][N];
int weight(int a,int b,int c);
void minWeightTrian(int n, int t[N][N], int s[N][N]) {
    for(int i=1;i<=n;i++) t[i][i]=0;
    for(int r=2;r<=n;r++) {
        for(int i=1;i<=n-r+1;i++) {
            int j=i+r-1;
            t[i][j]=t[i+1][j]+weight(i-1,i,j);
            s[i][j]=i;
            for(int k=i+1;k<i+r-1;k++) {
                int u=t[i][k]+t[k+1][j]+weight(i-1,k,j);
                if(u<t[i][j]) {
                    t[i][j]=u;
                    s[i][j]=k;
                }
            }
        }
    }
}

void Traceback(int i,int j,int s[N][N]) {
    if(i==j) return;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    cout << "ÆÊ·ÖµãÔÚ£ºv" << (i-1) << " v" << j << " v" << s[i][j] << endl;
}

int weight(int a,int b,int c) {
    return w[a][b]+w[b][c]+w[a][c];
}

int main() {
    minWeightTrian(5,t,s);
    Traceback(1,5,s);
    return 0;
}



