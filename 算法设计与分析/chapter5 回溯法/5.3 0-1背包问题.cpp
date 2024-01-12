//测试案例
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
    cout << "请输入物品的个数：";
    cin >> num;
    int* weights = new int[num];
    int* values = new int[num];
    cout << "请输入每件物品的重量：";
    for (unsigned i = 0; i < num; i++)
    {
        cin>>weights[i];
    }
    cout << "请输入每件物品的价值：";
    for (unsigned i = 0; i < num; i++)
    {
        cin >> values[i];
    }
    cout << "请输入包的最大承重：";
    cin >> capacity;
    cout << "该问题的最优解为：" << maxValue(weights, values, num, capacity);
    return 0;
}


 
