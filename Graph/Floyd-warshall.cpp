#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
const int N = 501;
int adj[N][N];
int dis[N][N];

void floydWarshall() {
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j)dis[i][j] = 0;
			else if(adj[i][j]) dis[i][j] = adj[i][j];
			else {
				dis[i][j] = 1e18;
			}
		}
	}

	for(int interM = 1; interM <= n; interM++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][interM] + dis[interM][j]);
			}
		}
	}

}



int32_t main() {
	#ifdef L
        //local = 'L';
        freopen("in.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif
	int q;
	cin >> n >> m >> q;
	int a, b, w;
	while(m--) {
		cin >> a >> b  >> w;
		if(adj[a][b] == 0) {
			adj[a][b] = w;
			adj[b][a] = w;
		}
		else {
			adj[a][b] = min(adj[a][b], w);
			adj[b][a] = min(adj[b][a], w);
		}
	}
	floydWarshall();
	while(q--) {
		cin >> a >> b;
		if(dis[a][b] != 1e18)
			cout << dis[a][b] <<"\n";
		else cout << -1 <<"\n";
	}


}
