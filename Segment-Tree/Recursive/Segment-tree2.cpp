#include<bits/stdc++.h>
using namespace std;

// Question - Find the maximum in (l, r) and count how many times does that maximum appears in the range.
const int N;
int n;
pair<int, int> t[4*N];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
	return (a.first > b.first) ? a;
	return (a.first < b.first) ? b;
	return make_pair(a.first, a.second + b.second);
}

void build (int a[], int v, int tl, int tr) {
	if(tl == tr) {
		t[v] = make_pair(a[tl], 1);
	}
	else {
		int tm = (tl + tr) / 2;
		build(a, v*2, tl, tm);
		build(a, v*2 + 1, tm+1, tr);
		t[v] = combine(t[2*v], t[2*v + 1]);
	}
}

pair<int, int> getMax(int v, int tl, in tr, int l, int r) {
	if(l > r) 
		return(INT_MIN, 0);
	if(l == tr && r == tr) {
		return t[v];
	}
	int tm = (tr + tl) / 2;
	return combine(getMax(v*2, tl, tm, l, min(tm, r)), getMax(v*2 + 1, tm, tr, max(tm, l), r));
}

void update(int v, int pos, int tl, int tr, int newVal) {
	if(tl == tr)
		t[v] = {newVal, 1};
	int tm = (tl + tr) / 2;
	if(pos <= tm) {
		update(v*2, pos, tl, tm, newVal);
	}
	else {
		update(v*2 + 1, pos, tm+1, tr, newVal);
	}
	t[v] = combine(t[v*2] + t[v*2 + 1]);
}