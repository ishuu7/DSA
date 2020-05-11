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
const int mod = 1e9 + 7;

int find(int a){
    if(parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    parent[a] += parent[b];
    parent[b] = a;
}

int main() {
    COOL
    #ifdef L
        //local = 'L';
        freopen("in.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif
    for(int i = 0; i <= N; i ++){
        parent[i] = -1;
    }
    int n, m;
    cin >> n >> m;
    int a, b;
    loop(i,0,m){
        cin >> a >> b;
        a = find(a);
        yo(a);
        b = find(b);
        yo(b);
        if(a != b)Union(a, b);
    }
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        if(parent[i] < 0){
            ans = (ans * abs(parent[i]))%mod;
        }
    }
    cout << ans <<"\n";



    return 0;
}




