#include <bits/stdc++.h>
using namespace std;
#define int long long
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


/*
        Bellman Ford is used to find the shortest paths from source to all the other vertices of the graph.
        Conditions -> Should not have a negative cycle.
        Advantage over Dijkstra -> Can be used for negative weights. And is used to find negative cycles in the graph also.
        How does it work -> Initialise source vertex distance as 0 and all other vertex distance as infinite, and relax all
                            the egdes for |V| - 1 times, if does not contain the negative cycle.

                            If it contains the negative cycle then relax all the edges for one more time and see if distance 
                            of any vertex changes, for negative cycle detection.
        Time Complexity -> O(|V| * |E|)
*/

struct edge {
        int b, w;
};
const int inf = 1e18;
vector<vector<edge>> adj, adj2;
vector<bool> visited;

void SSSP(int source, vector<int>& dis, int &n, vector<bool>& visited) {
        dis[source] = 0;
        for(int i = 1; i < n; i++) {
                for(int j = 1; j <= n; j++) {
                        for(auto &e : adj[j]) {
                                int u = j;
                                int v = e.b;
                                int w = e.w;
                                if(dis[v] > dis[u] + w) {
                                        dis[v] = dis[u] + w;
                                }
                        }
                }
        }

        for(int j = 1; j <= n; j++) {
                for(auto &e : adj[j]) {
                        int u = j;
                        int v = e.b;
                        int w = e.w;
                        if(dis[v] > dis[u] + w) {
                                // negative cyle present

                        }
                }
        }
}



signed main() {
        #ifndef L
                freopen("in.txt", "r", stdin);
                freopen("op.txt", "w", stdout);
        #endif
        int n;
        cin >> n;
        adj = vector<vector<edge>>(n + 1);
        adj2 = vector<vector<edge>>(n + 1);
        visited = vector<bool> (n, false);

        int m;
        cin >> m;

        for(int i = 0; i < m; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                adj[u].push_back({v, w});
                adj2[v].push_back({u, w});
        }

        int source = 1;
        int destination = n;
        vector<int> dis(n + 1, -inf);
        vector<bool> vis(n + 1, false);

        SSSP(source, dis, n, visited);

        COOL;
        return 0;
}
