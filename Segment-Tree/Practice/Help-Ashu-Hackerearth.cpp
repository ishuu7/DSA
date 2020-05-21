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

int a[N];
pair<int, int> t[4*N];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    pair <int, int> c = {a.first + b.first, a.second + b.second};
    return c;
}


void build(int v, int tl, int tr) {
    if(tl == tr){
        if(a[tl]&1){
            t[v] = {1, 0};
            return;
        }
        else {
            t[v] = {0, 1};
            return;
        }
    }
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = combine(t[2*v], t[2*v + 1]);
}

void update(int v, int tl, int tr, int pos, int newVal) {
    if(tl == tr) {
        if(a[tl]&1) {
            t[v] = {0, 1};
        }
        else {
            t[v] = {1, 0};
        }
        a[tl] = newVal;
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos <= tm)
        update(v*2, tl, tm, pos,newVal);
    else
        update(v*2 + 1, tm+1, tr, pos, newVal);
    t[v] = combine(t[v*2], t[v*2 + 1]);
}

int query1 (int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l)
        return 0;
    if(tl >= l && tr <= r)
        return t[v].first;
    int tm = (tl + tr) / 2;
    return query1(v*2, tl, tm, l, r) + query1(v*2 + 1, tm+1, tr, l, r);
}


int query2 (int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l)
        return 0;
    if(tl >= l && tr <= r)
        return t[v].second;
    int tm = (tl + tr) / 2;
    return (query2(v*2, tl, tm, l, r) + query2(v*2 + 1, tm+1, tr, l, r));
}

int main() {
    COOL
    int n, q;
    cin >> n;
    loop(i, 1, n+1)cin >> a[i];
    build(1, 1, n); 
    int l1, r1, x;
    cin >> q;
    while(q--) {
        cin >> x >> l1 >> r1;
        if(x == 1)
            cout << query2(1, 1, n, l1, r1) <<"\n";
        else if(x == 2) {
            cout << query1(1, 1, n, l1, r1) << "\n";
        }
        else {
            if(a[l1]%2 == r1%2)continue;
            update(1, 1, n, l1, r1);
        }
    }
    return 0;
}




