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
const int N = 1e5;
int parent[N+1];
int R[N+1];
const int mod = 1e9 + 7;


// Find using path compression.
int find(int a){
    if(parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)return;
    parent[a] += parent[b];
    parent[b] = a;
}


void UnionByRank(int a, int b){ // for the find function to work in log(N) time.
    a = find(a);
    b = find(b);
    if(a == b)return;
    if(R[a] > R[b]){
        // a will be parent,
        parent[b] = a;
        R[a] += R[b];
    }
    else {
        parent[a] = b;
        R[b] += R[a];
    }
}

int main() {
    COOL
    #ifndef L
        //local = 'L';
        freopen("in.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif
    memset(parent, -1, sizeof(parent));
    memset(R, 1, sizeof(R));






    return 0;
}




