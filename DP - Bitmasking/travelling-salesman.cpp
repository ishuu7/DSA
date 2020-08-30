// https://practice.geeksforgeeks.org/problems/travelling-salesman-problem/0

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = (int)a ; i < (int)b ; i++)
#define rrep(i,a,b) for(int i = (int)a; i >= (int)b; i--)
#define pb push_back
#define vi vector<int>
#define yo(a) if(local == 'L'){cerr <<#a <<" = " << a <<"\n";}
#define yo2(a, b) if(local == 'L'){cerr <<#a <<" = " << a <<", " << #b << " = " b <<"\n";}
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define minHeap priority_queue<int, vector<int>, greater<int> >
#define maxHeap priority_queue<int>


int dp[1 << 13][13];


int n;
int cost[13][13];
int fun(int mask, int curr) {
        if(mask == 1)
                return cost[curr][0];
        if(dp[mask][curr] != -1)
                return dp[mask][curr];
        int ans = INT_MAX;
        for(int city = 1; city < n; city++) {
                if(mask & (1 << city))
                        ans = min(ans, cost[curr][city] + fun(mask ^ (1 << city), city));
        }
        return dp[mask][curr] = ans;
        
}

void solve() {
        memset(dp, -1, sizeof dp);
        cin >> n;
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                        cin >> cost[i][j];
                }
        }

        cout << fun((1 << n) - 1, 0) << "\n";
}



signed main() {
        #ifdef L
            //local = 'L';
            freopen("in.txt", "r", stdin);
            freopen("op.txt", "w", stdout);
        #endif
        int t;
        cin >> t;
        rep(i,1,t + 1)
                solve();
        return 0;
}

