#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(int i = (int)a ; i < (int)b ; i++)
#define rtloop(i,a,b) for(int i = (int)a; i >= (int)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) if(local == 'L'){cerr <<#a <<" = " << a <<"\n";}
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//char local = '0';

const int N = 1e5 + 1;

int a[N], t[4*N];

void build(int v, int tl, int tr) {
    if(tl == tr){
        t[v] = a[tl];
        return;
    }
    int tm = (tr + tl) / 2;
    build(v*2, tl, tm);
    build(v*2 + 1, tm+1, tr);
    t[v] = min(t[2*v], t[2*v + 1]);
}

int getMin(int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l)
        return INT_MAX;
    if(tl >= l && tr <= r)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(getMin(v*2, tl, tm, l, r), getMin(v*2 + 1, tm+1, tr, l, r));
}


int main() {
    COOL
    int n, q;
    cin >> n;
    loop(i, 1, n+1)cin >> a[i];
    build(1, 1, n); 
    int l1, r1;
    cin >> q;
    while(q--) {
        cin >> l1 >> r1;
        cout << getMin(1, 1, n, l1+1, r1+1) << "\n";
    }
    return 0;
}




