#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define debug(s, x) cout << s << " = " <<x <<"\n"

// Undirected graph ke liye

class graph{
    int v;
    list<int> *adj; // pointers to the dynamic array
public:
    graph(int v){
        this -> v = v;
        adj = new list <int> [v];
    }
    void addEdge(int v, int w){
        adj[v].pb(w);
        adj[w].pb(v);
    }
    bool isCyclicSub(int v, bool visited[], int parent){ // sub-graph ka cycle detection.
        visited[v] = true; 
    	for (int i : adj[v]) { 
            if(!visited[i]){
                if(isCyclicSub(i, visited, v)) // DFS maara agar agla visited nahi hai toh
                    return true;
            }
            else if(i != parent) // agar agla visited hai aur parent nahi hai to cycle hai.
                return true;
        }
        return false;
    }

    bool isCyclic(){
        bool *visited = new bool[v];
        for(int j = 0; j < v; j++){
            visited[j] = false;
        }
        for(int u = 0; u < v; u++){
            if(!visited[u])
                if (isCyclicSub(u, visited, -1)) 
                    return true;
        }
        return false;
        
    }

};

int main() { 
	graph g1(5); 
	g1.addEdge(1, 0); 
	g1.addEdge(0, 2); 
	g1.addEdge(2, 1); 
	g1.addEdge(0, 3); 
	g1.addEdge(3, 4); 
	if(g1.isCyclic())cout << "Graph contains cycle\n";
    else cout << "Graph doesn't contain cycle\n"; 

	graph g2(3); 
	g2.addEdge(0, 1); 
	g2.addEdge(1, 2); 
	g2.isCyclic()? cout << "Graph contains cycle\n": 
				cout << "Graph doesn't contain cycle\n"; 

	return 0; 
} 

