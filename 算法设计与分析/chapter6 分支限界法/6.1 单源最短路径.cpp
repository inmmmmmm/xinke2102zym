#include<bits/stdc++.h>

using namespace std;

// ͼ�ı߽ṹ��
struct Edge {
    int dest;   // Ŀ�궥��
    int weight; // �ߵ�Ȩ��

    Edge(int _dest, int _weight) : dest(_dest), weight(_weight) {}
};

// ͼ�Ķ���ṹ��
struct Vertex {
    int id;               // ������
    int distance;         // ����ʼ���㵽�ö���ľ���
    vector<Edge> edges;   // ��ö��������ı�

    Vertex(int _id) : id(_id), distance(INT_MAX) {}
};

// ��֧�޽��㷨��ⵥԴ���·��
void branchAndBoundShortestPath(vector<Vertex>& graph, int start) {
    // ���ȶ������ڴ洢������Ķ��㣬���վ����С��������
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // ������ʼ����ľ���Ϊ0��������������
    graph[start].distance = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        // ȡ�������о�����С�Ķ���
        int u = pq.top().second;
        pq.pop();

        // ��������u�����б�
        for (const Edge& edge : graph[u].edges) {
            int v = edge.dest;
            int weight = edge.weight;

            // �����������u���ﶥ��v��·��������̣�����¾��벢������v�������
            if (graph[u].distance + weight < graph[v].distance) {
                graph[v].distance = graph[u].distance + weight;
                pq.push(make_pair(graph[v].distance, v));
            }
        }
    }
}

int main() {
    int numVertices, numEdges, start;
    cout << "�����붥�����ͱ�����";
    cin >> numVertices >> numEdges;

    vector<Vertex> graph(numVertices);

    cout << "������ÿ���ߵ���ʼ���㡢Ŀ�궥���Ȩ�أ�" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].edges.emplace_back(dest, weight);
    }

    cout << "��������ʼ���㣺";
    cin >> start;

    branchAndBoundShortestPath(graph, start);

    cout << "�Ӷ��� " << start << " ��������������������·��Ϊ��" << endl;
    for (int i = 0; i < numVertices; i++) {
        if (graph[i].distance != INT_MAX) {
            cout << "���ﶥ�� " << i << " ����̾���Ϊ��" << graph[i].distance << endl;
        } else {
            cout << "���ﶥ�� " << i << " ������·��" << endl;
        }
    }

    return 0;
}
