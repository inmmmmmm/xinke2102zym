#include<bits/stdc++.h>

using namespace std;

// 图的边结构体
struct Edge {
    int dest;   // 目标顶点
    int weight; // 边的权重

    Edge(int _dest, int _weight) : dest(_dest), weight(_weight) {}
};

// 图的顶点结构体
struct Vertex {
    int id;               // 顶点编号
    int distance;         // 从起始顶点到该顶点的距离
    vector<Edge> edges;   // 与该顶点相连的边

    Vertex(int _id) : id(_id), distance(INT_MAX) {}
};

// 分支限界算法求解单源最短路径
void branchAndBoundShortestPath(vector<Vertex>& graph, int start) {
    // 优先队列用于存储待处理的顶点，按照距离从小到大排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 设置起始顶点的距离为0，并将其加入队列
    graph[start].distance = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        // 取出队列中距离最小的顶点
        int u = pq.top().second;
        pq.pop();

        // 遍历顶点u的所有边
        for (const Edge& edge : graph[u].edges) {
            int v = edge.dest;
            int weight = edge.weight;

            // 如果经过顶点u到达顶点v的路径距离更短，则更新距离并将顶点v加入队列
            if (graph[u].distance + weight < graph[v].distance) {
                graph[v].distance = graph[u].distance + weight;
                pq.push(make_pair(graph[v].distance, v));
            }
        }
    }
}

int main() {
    int numVertices, numEdges, start;
    cout << "请输入顶点数和边数：";
    cin >> numVertices >> numEdges;

    vector<Vertex> graph(numVertices);

    cout << "请输入每条边的起始顶点、目标顶点和权重：" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].edges.emplace_back(dest, weight);
    }

    cout << "请输入起始顶点：";
    cin >> start;

    branchAndBoundShortestPath(graph, start);

    cout << "从顶点 " << start << " 出发到达其他顶点的最短路径为：" << endl;
    for (int i = 0; i < numVertices; i++) {
        if (graph[i].distance != INT_MAX) {
            cout << "到达顶点 " << i << " 的最短距离为：" << graph[i].distance << endl;
        } else {
            cout << "到达顶点 " << i << " 不存在路径" << endl;
        }
    }

    return 0;
}
