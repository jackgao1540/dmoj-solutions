#include <bits/stdc++.h>

using namespace std;

struct node{
    int visited;
    vector <int> outs;
};

vector <node> graph;

int isCyclic(int node){
    if(graph[node].visited == 1){
        return 1;
    }
    //go to neighbours
    graph[node].visited = 1;
    for(int i = 0; i < graph[node].outs.size(); i++){
        if(isCyclic(graph[node].outs[i]))return 1;
    }
    graph[node].visited = 2;
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    node temp;
    temp.visited = 0;
    for(int i = 0; i < n; i++)graph.push_back(temp);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a - 1].outs.push_back(b - 1);
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        if(graph[i].visited == 0){
            //cout << i << " " << isCyclic(i) << endl;
            if(isCyclic(i) == 1){
                c = 1;
                break;
            }   
        }
    }
    if(!c){
        cout << "Y";
    }else cout << "N";
    return 0;
}