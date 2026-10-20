#include <iostream>
#include <queue>
using namespace std;

void DFS(int node, int graph[6][6], bool visited[]) {
    visited[node] = true;
    cout<< node << " ";

    for (int i = 0; i< 6; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i, graph, visited);
        }
    }
}

void BFS(int start, int graph[6][6]) {
    bool visited[6] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout<< node << " ";

        for (int i = 0; i< 6; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int graph[6][6] = {0};

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][5] = 1;

    bool visited[6] = {false};

    cout<< "DFS: ";
    DFS(0, graph, visited);

    cout<< "\nBFS: ";
    BFS(0, graph);

    return 0;
}
