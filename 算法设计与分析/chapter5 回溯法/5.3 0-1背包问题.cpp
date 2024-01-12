//���԰���
// 5
// 1 2 3 4 5
// 5 4 3 2 1
// 10
#include<iostream>
#include<stack>
using namespace std;

int maxValue(int w[], int v[], const unsigned& length, const unsigned& capacity)
{
    stack<int> Bag;
    int max = 0;
    int weight = 0;
    int value = 0;
    int i;

    for (i = 0; ; i++)
    {
        if (weight + w[i] <= capacity)
        {
            Bag.push(i);
            weight += w[i];
            value += v[i];
        }
        else
        {
        }

        if (i == length - 1)
        {
            if (max < value)
            {
                max = value;
            }
            {
                i = Bag.top();
                Bag.pop();
                weight -= w[i];
                value -= v[i];
                if (i == length - 1)
                {
                    if (Bag.empty())break;
                    i = Bag.top();
                    Bag.pop();
                    weight -= w[i];
                    value -= v[i];
                }
            }
        }
    }
    return max;
}

int main(void)
{
    unsigned num, capacity;
    cout << "��������Ʒ�ĸ�����";
    cin >> num;
    int* weights = new int[num];
    int* values = new int[num];
    cout << "������ÿ����Ʒ��������";
    for (unsigned i = 0; i < num; i++)
    {
        cin>>weights[i];
    }
    cout << "������ÿ����Ʒ�ļ�ֵ��";
    for (unsigned i = 0; i < num; i++)
    {
        cin >> values[i];
    }
    cout << "��������������أ�";
    cin >> capacity;
    cout << "����������Ž�Ϊ��" << maxValue(weights, values, num, capacity);
    return 0;
}


 
