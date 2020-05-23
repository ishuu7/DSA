#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 1;
int n, m;
int x = 1;
vector<pair<int, int> > adj[N];
priority_queue<pair<int, int> >q;
int dis[N];
vector<int> visited(N, false);

void SSSP() {
	for(int i = 2; i <= n; i++)
		dis[i] = 1e18;
	q.push({0, x});
	while(q.size()) {
		int a = q.top().second;
		q.pop();
		if(visited[a])continue;
		visited[a] = true;
		for(auto u : adj[a]) {
			int b = u.first;
			int w = u.second;
			if (dis[a]+w < dis[b]) {
				dis[b] = dis[a]+w;
				q.push({-dis[b],b});
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
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	SSSP();
	for(int i = 1; i <= n; i++)
		cout << dis[i] <<" ";

}
