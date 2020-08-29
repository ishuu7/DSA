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


int dp[21][1 << 21];


// dp[i][mask] representing the value to assign the job from i to n, currently having the mask people

int n;
int cost[21][21]; // cost[i][j] represent the the cost to assign the ith job to jth people.
int fun(int i, int mask) {
        if(i == n)
                return 0;
        if(dp[i][mask] != -1)
                return dp[i][mask];
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) {
                        ans = min(ans, cost[j][i] + fun(i + 1, mask ^ (1 << j)));
                }
        }
        return dp[i][mask] = ans;
}

void solve() {
        memset(dp, -1, sizeof dp);
        cin >> n;
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                        cin >> cost[i][j];
                }
        }


        cout << fun(0, (1 << n) - 1) << "\n";
}



signed main() {
        #ifndef L
            //local = 'L';
            freopen("in.txt", "r", stdin);
            freopen("op.txt", "w", stdout);
        #endif
        // int t;
        // cin >> t;
        // rep(i,1,t + 1)
                solve();
        return 0;
}

