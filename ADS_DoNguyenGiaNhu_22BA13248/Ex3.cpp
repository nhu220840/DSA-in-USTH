/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, s;
vector<int> adj[1001];
bool visited[1001];

void bubbleSort(vector<int>& a){  
    int n = a.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){  
            if(a[j] < a[j + 1]){  
                swap(a[j], a[j + 1]); 
            }
        }
    }
}

void DFS(int u){
    cout << u << " ";
    visited[u] = true;

    for(int x : adj[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

void insertToAdjacent(vector<int> a[], int u, int v){
    a[u].push_back(v);
}

int main(){
    
    insertToAdjacent(adj, 20, 8);
    insertToAdjacent(adj, 20, 81);
    insertToAdjacent(adj, 8, 3);
    insertToAdjacent(adj, 8, 13);
    insertToAdjacent(adj, 81, 70);
    insertToAdjacent(adj, 81, 310);

    s = 20;
    
    for(int i = 1; i <= 1000; i++){
        if(!adj[i].empty()){
            bubbleSort(adj[i]);
        }
    }
    DFS(s);
}
