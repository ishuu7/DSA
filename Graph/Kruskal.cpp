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

struct edge{
    int a;
    int b;
    int w;
    
};

edge ar[N+1];

bool comp(edge a, edge b){
    if(a.w < b.w)
        return true;
    return false;
}



int summ = 0;

// Find using path compression.
int find(int a){
    if(parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b, int ww){
    a = find(a);
    b = find(b);
    if(a == b)return;
    parent[b] = a;
    summ += ww;
}

int main() {
    COOL
    #ifdef L
        //local = 'L';
        freopen("in.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int m;
    for(int i = 1; i <= n; i++)
        parent[i] = -1;
    cin >> m;
    int a1, b1, w1;
    loop(i,0,m){
        cin >> ar[i].a >> ar[i].b >> ar[i].w; 
    }
    sort(ar, ar + m, comp);
    for(int i = 0; i < m; i++){
        Union(ar[i].a, ar[i].b, ar[i].w);
    }
    cout << summ <<"\n";







    return 0;
}




