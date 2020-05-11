#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
const int N = (2e5);
const ll mod = 1000000007;

vector<int> adj[N+1];
bool visited[N+1] ={0};
int dis[N+1];
bool col[N+1];
int intime[N+1];
int outtime[N+1];
int subSize[N+1];
int level[N+1];



void dfsSSSP(int v, int distance){ // for unweighted graph
    visited[v] = true;
    dis[v] = distance;
    for(int u : adj[v]){
        if(!visited[u]){
            dfsSSSP(u, distance+1);
        }
    }
}
int temp;
void dfs(int v){
    visited[v] = true;
    temp ++;
    for(int u : adj[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

bool dfsBipartite(int v, bool c){
    col[v] = c;
    visited[v] = 1;
    for(int u : adj[v]){
        if(!visited[u]){
            if(!(dfsBipartite(u, c^1)))
                return false;
        }
        else{
            if(col[v] == col[u])
                return false;
        }
    }
    return true;
}// graph can be disconnected also so check also for not visited nodes.

bool dfsIsCyclic(int v, int parent){
    visited[v] = 1;
    for(int u : adj[v]){
        if(!visited[u]){
            if(dfsIsCyclic(u, v))
                return true;
        }
        else{
            if(u != parent)
                return true;
        }
    }
    return false;
} // looking for back edge, i.e, the parent of a child who is ancestor but not parent.

int timer = 1;
void dfsTime(int v){
    intime[v] = timer++;
    visited[v] = 1;
    for(int u : adj[v]){
        if(!visited[v])
            dfsTime(u);
    }
    outtime[v] = timer++;
}

// size of subtree in O(N), we are here using the information of 
// the child node subtree size and adding the child node subtree
// size to the parent node.

int dfs_SubtreeSize(int v){
    visited[v] = true;
    int curr_size = 1;
    for (int u : adj[v]){
        if(!visited[u])
            curr_size += dfs_SubtreeSize(u);
    }
    subSize[v] = curr_size;
    return curr_size;
}

void bfsSSSP(int v){ // for unweighted graph
    visited[v] = true;
    dis[v] = 0;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int u : adj[curr]){
            if(!visited[u]){
                q.push(u);
                dis[u] = dis[curr] + 1;
                level[dis[u]]++;
                visited[u] = true;
            }
        }
    }
}








int main(){
    #ifndef ONLINE_JUDGE
        freopen("inn.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif
    
    

    return 0;



}
