#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int maxN = 1000000;
int q[1000000];
int size = 0;

int vertices, edges, startVertex;
vector<int> adj[100];
bool visited[100];

bool empty(){
    return size == 0;
}

void push(int value){
    if(size == maxN) return;
    q[size] = value;
    size++;
}

void pop(){
    if(size == 0) return;
    for(int i = 0; i < size - 1; i++){
        q[i] = q[i + 1];
    }
    size--;
}

int front(){
    return q[0];
}

void enter(){
    cin >> vertices >> edges >> startVertex;
    for(int i = 1; i <= edges; i++){
        int vertex1, vertex2; cin >> vertex1 >> vertex2;
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);
    }

    for(int i = 1; i <= vertices; i++){
        sort(adj[i].begin(), adj[i].end());
    }
}

void BFS(int vertex){
    push(vertex);
    visited[vertex] = true;

    while(!empty()){
        int frontVertex = front(); pop();
        cout << frontVertex << " ";
        for(int adjacentVertex : adj[frontVertex]){
            if(!visited[adjacentVertex]){
                push(adjacentVertex);
                visited[adjacentVertex] = true;
            }
        }
    }
}

int main(){
    enter();
    BFS(startVertex);
}