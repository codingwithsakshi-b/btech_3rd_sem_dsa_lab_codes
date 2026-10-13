#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void breadthFirstSearch(const vector<vector<int>>& graph, int startVertex) {
    vector<bool> visited(graph.size(), false);
    queue<int> vertices;

    visited[startVertex] = true;
    vertices.push(startVertex);

    cout << "BFS traversal: ";
    while (!vertices.empty()) {
        int currentVertex = vertices.front();
        vertices.pop();
        cout << currentVertex << " ";

        for (int neighbor : graph[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                vertices.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int vertexCount, edgeCount;

    cout << "Enter number of vertices: ";
    if (!(cin >> vertexCount) || vertexCount <= 0) {
        cout << "Invalid number of vertices." << endl;
        return 1;
    }

    cout << "Enter number of edges: ";
    if (!(cin >> edgeCount) || edgeCount < 0) {
        cout << "Invalid number of edges." << endl;
        return 1;
    }

    vector<vector<int>> graph(vertexCount);
    cout << "Enter each edge as two vertices (0 to " << vertexCount - 1
         << "):" << endl;

    for (int i = 0; i < edgeCount; ++i) {
        int firstVertex, secondVertex;
        if (!(cin >> firstVertex >> secondVertex) ||
            firstVertex < 0 || firstVertex >= vertexCount ||
            secondVertex < 0 || secondVertex >= vertexCount) {
            cout << "Invalid edge. Vertex numbers must be between 0 and "
                 << vertexCount - 1 << "." << endl;
            return 1;
        }

        graph[firstVertex].push_back(secondVertex);
        graph[secondVertex].push_back(firstVertex);
    }

    int startVertex;
    cout << "Enter starting vertex: ";
    if (!(cin >> startVertex) || startVertex < 0 ||
        startVertex >= vertexCount) {
        cout << "Invalid starting vertex. Enter a value between 0 and "
             << vertexCount - 1 << "." << endl;
        return 1;
    }

    breadthFirstSearch(graph, startVertex);
    return 0;
}
