// Write a program to find the nodes connected to the source node in exactly 2-hop distance.
#include <iostream>

using namespace std;

const int MAX_NODES = 100;

void addEdge(int adjList[][MAX_NODES], int u, int v) {
    adjList[u][v] = 1;
    adjList[v][u] = 1;
}

void findTwoHopNeighbors(int adjList[][MAX_NODES], int nodes, int source, int result[]) {
    bool visited[MAX_NODES] = {false};
    
    for (int neighbor = 0; neighbor < nodes; ++neighbor) {
        if (adjList[source][neighbor]) {
            visited[neighbor] = true;
            for (int secondHopNeighbor = 0; secondHopNeighbor < nodes; ++secondHopNeighbor) {
                if (adjList[neighbor][secondHopNeighbor] && secondHopNeighbor != source && !visited[secondHopNeighbor]) {
                    result[secondHopNeighbor] = 1;
                }
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    int adjList[MAX_NODES][MAX_NODES] = {0};

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    int twoHopNeighbors[MAX_NODES] = {0};
    findTwoHopNeighbors(adjList, numNodes, sourceNode, twoHopNeighbors);

    cout << "Nodes connected to " << sourceNode << " in exactly 2-hop distance:";
    for (int i = 0; i < numNodes; ++i) {
        if (twoHopNeighbors[i]) {
            cout << " " << i;
        }
    }
    cout << endl;

    return 0;
}
