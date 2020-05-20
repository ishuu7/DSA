#include<bits/stdc++.h>
using namespace std;

// Question - GCD of range of array and single point updation.


const int N;
int n, t[4*N];

void build(int a[], int v, int tl, int tr) {
	if(tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tr + tl) / 2;
		build(a, v*2, tl, tm);
		build(a, v*2 + 1, tm+1, tr);
		t[v] = __gcd(t[v*2], t[v*2 + 1]);
	}
}

int getGcd(int v, int tl, int tr, int l, int r) {
	if(l == tl && r == tr)
		return t[v];
	int tm = (tr + tl) / 2;
	if(min(r, tm) <= l && max(tm, r) >= r) {
		return __gcd(getGcd(v*2, tl, tr, l, min(r, tm)), getGcd(v*2 + 1, tl, tr, max(l, tm), r));
	}
}

void update(int v, int pos, int tl, int tr, int newVal) {
	if(tl == tr)
		t[v] = newVal;
	else {
		int tm = (tl + tr) / 2;
		if(pos <= tm) {
			update(v*2, pos, tl, tm, newVal);
		}
		else 
			update(v*2 + 1, pos, tm+1, tr, newVal);
		t[v] = __gcd(t[v*2], t[v*2 + 1]);
	}
}



int main() {

}
