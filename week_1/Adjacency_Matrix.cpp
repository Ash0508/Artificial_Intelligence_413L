
// Write a program to represent a graph using adjacency matrix.

#include <iostream>
using namespace std;

int main(){
    int edges, vertices;
    cout << "Enter the number of edges"<<endl;
    cin >> edges;
    cout << "Enter the number of vertices"<<endl;
    cin >> vertices;

    int graph[vertices][vertices];
    for (int i = 0; i < edges; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    int v1, v2;
    for (int i = 0; i < edges; i++)
    {
        cout<<"Enter the vertices for edge details"<<endl;
        cin>>v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    cout<<"The adjacency matrix is"<<endl;
    for (int i = 0; i < edges; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }    
    cout<<"The adjacency list is"<<endl;
    for(int i=0;i<edges;i++){
        cout<<i<<" -> ";
        for(int j=0;j<vertices;j++){
            if(graph[i][j]==1){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
