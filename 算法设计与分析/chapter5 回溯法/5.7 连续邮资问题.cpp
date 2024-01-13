// ������ʵ�ֵ�������������Ļ��ݷ�
#include <iostream>
#include <climits>
using namespace std;

// ����һЩȫ�ֱ���
const int MAXL = 1500; // �����Ͻ�
const int MAXINT = INT_MAX; // ������
int n; // ��Ʊ�Ĳ�ͬ��ֵ������
int m; // ÿ���ŷ��������������Ʊ��
int maxR; // ��ǰ����ֵ
int x[6]; // ��ǰ��
int y[MAXL + 1]; // ����������������������Ʊ��
int bestx[6]; // ��ǰ���Ž�

// ����һ���������û��ݷ����������������
void backtrack(int i, int r) {
    // ����ÿ�����ʣ����������������������Ʊ��
    for (int j = 0; j <= x[i - 2] * (m - 1); j++) {
        if (y[j] < m) {
            for (int k = 1; k <= m - y[j]; k++) {
                if (y[j] + k < y[j + x[i - 1] * k]) {
                    y[j + x[i - 1] * k] = y[j] + k;
                }
            }
        }
    }
    // �ҵ�������������
    while (y[r] < MAXINT) {
        r++;
    }
    // ���������Ʊ��ȷ����
    if (i > n) {
        // �����ǰ���������Ž�
        if (r - 1 > maxR) {
            maxR = r - 1; // ��������ֵ
            for (int j = 1; j <= n; j++) {
                bestx[j] = x[j]; // �������Ž�
            }
        }
        return; // ������һ��
    }
    // ����y����
    int z[MAXL + 1];
    for (int k = 1; k <= MAXL; k++) {
        z[k] = y[k];
    }
    // ö�ٵ�i����Ʊ����ֵ
    for (int j = x[i - 1] + 1; j <= r; j++) {
        // �������r-jԪ�����������Ʊ��С��m
        if (y[r - j] < m) {
            x[i] = j; // ���õ�i����Ʊ����ֵΪj
            backtrack(i + 1, r + 1); // �������
            // �ָ�y����
            for (int k = 1; k <= MAXL; k++) {
                y[k] = z[k];
            }
        }
    }
}
// ����һ���������������������������ֵ
int maxStamp(int mm, int nn) {
    n = nn;
    m = mm;
    maxR = 0;
    for (int i = 1; i <= MAXL; i++) {
        y[i] = MAXINT; // ��ʼ��Ϊ�����
    }
    x[1] = 1; // ��һ����Ʊ����ֵΪ1
    y[0] = 0; // ����0Ԫ���ʲ���Ҫ��Ʊ
    backtrack(2, 1); // �������
    return maxR; // �������ֵ
}



int main() {
    int m = 4; // ÿ���ŷ��������������Ʊ��
    int n = 5; // ��Ʊ�Ĳ�ͬ��ֵ������
    int maxR = maxStamp(m, n); // �������������������ֵ
    cout << "���������������Ϊ��" << maxR << endl; // ������ֵ
    for (int i = 1; i <= n; i++) {
        cout << bestx[i] << " "; // ������Ž�
    }
    cout << endl;
    return 0;
}

