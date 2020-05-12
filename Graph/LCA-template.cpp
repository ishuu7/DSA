#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) if(local == 'L'){cerr <<#a <<" = " << a <<"\n";}
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
char local = '0';
const int N = 1e3;
const int maxN = 10;

vector<int> adj[N+1];
int level[N+1];
int LCA[N+1][maxN+1];

void dfs(int node, int par, int lvl){
    level[node] = lvl;
    LCA[node][0] = par;
    for(int child : adj[node]){
        if(child == par)continue;
        else {
            dfs(child, node, lvl+1);
        }
    }
}

void preProcess(int n){
    dfs(1, -1, 0); // assuming 1 as root.
    for(int i = 1; i <= maxN; i++){           // 2^maxN is maximum height of the tree.
        for(j = 1; j <=n; j++){
            if(LCA[j][i-1] != -1){      
                int par = LCA[j][i-1];
                LCA[j][i] = LCA[par][i-1]; // curr_node ka 2^ith parent = curr_node ka parent ka 2^i-1th parent.
            }
        }
    }
}


int getLca(int a, int b){
    if(level[a] < level[a])swap(a, b);
    int d = level[a] - level[b];
    while(d > 0){

        int d1 = log2(d); // jump(binary lifting)
        a = LCA[a][d1];
        d -= (1 << d1);
    }
    // a and b same level pe aa gaye ab
    if(a == b)return a;

    for(int i = maxN; i >= 0; i--){
        if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i])){ // atleast 2^ith parent exist kare, and agar kare to dono same nahin ho.
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    // ab dono ka parent LCA hai, (2^0th ancestor = 1)
    return LCA[a][0];
}



int main() {
    COOL
    #ifndef L
        //local = 'L';
        freopen("in.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif


    
    return 0;
}




