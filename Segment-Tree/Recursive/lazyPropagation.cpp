#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i,a,b) for(int i = (int)a ; i < (int)b ; i++)
#define rtloop(i,a,b) for(int i = (int)a; i >= (int)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) if(local == 'L'){cerr <<#a <<" = " << a <<"\n";}
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 2e5 + 1;

int a[N], t[4*N], lazy[4*N];

void build(int v, int tl, int tr) {
	if(tl == tr) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) /2;
	build(v*2, tl, tm);
	build(v*2 + 1, tm+1, tr);
	t[v] = (t[v*2] + t[v*2 + 1]);
}

void rangeUpdate(int v, int tl, int tr, int l, int r, int newVal) {
	if(lazy[v] != 0) {
		int val = lazy[v];
		lazy[v] = 0;
		t[v] += val*(tr - tl + 1);
		if(tl != tr) {
			lazy[2*v] += val;
			lazy[2*v + 1] += val;
		}
	}

	if(tl > r || tr < l)
		return;
	if(tl >= l && tr <= r) {
		int val = (tr - tl + 1)*newVal;
		t[v] += val;
		if(tl != tr) {
			lazy[2*v] += newVal;
			lazy[2*v + 1] += newVal;
			return;
		}
	}

	int mid = tl + ((tr - tl) / 2);
	rangeUpdate(v*2, tl, tm, l, r, newVal);
	rangeUpdate(v*2 + 1, tm + 1, tr, l, r, newVal);
	t[v] = t[2*v] + t[2*v + 1];
}

int query(int v, int tl, int tr, int l, int r) {
	if(lazy[v] != 0) {
		int val = lazy[v];
		lazy[v] = 0;
		t[v] += (val*(tr - tl + 1));

		if(tr != tl) {
			lazy[2*v] += val;
			lazy[2*v + 1] += val;
		}
	}
	if(tl > r || tr < l)
		return 0;

	if(tl >= l && tr <= r) {
		return t[v];
	}
	int mid = (tl + tr) / 2;
	return query(2*v, tl, tm, l, r) + query(2*v + 1, tm+1, tr, l, r);
}

int main() {
	int n, q;
	cin >> n >> q;
	build(1, 1 n);
	int x, l, r, newVal;
	while(q--) {
		cin >> x;
		if(x == 1){
			cin >> l >> r;
			cout << query(1, 1, n, l, r);
		}
		else{
			cin >> l >> r >> newVal; 
			rangeUpdate(1, 1, n, l, r, newVal);
		}
	}
}
