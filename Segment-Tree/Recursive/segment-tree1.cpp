#include<bits/stdc++.h>
using namespace std;

const int N;

int n, t[4*N];
/* -------------Simple recursive implementation for summation query and updation --------------------*/
void build(int a[], int v, int tl, int tr) { // v is current node, from main pass(a, 1, 0, n-1)
    if(tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2 + 1, tm+1, tr);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) { 
    if(l > r)
        return 0;
    if(l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum (v*2 + 1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int newVal) { //  going from node 1 to that particular node, imagine.
    if (tr == tl) {
        t[v] = newVal;
    }
    else {
        int tm = (tr + tl) / 2;
        if(pos <= tm) {
            update(v*2, tl, tm, pos, newVal);
        }
        else {
            update(v*2, tm+1, tr, pos, newVal);
        }
        t[v] = t[2*v] + t[2*v + 1];
    }
}

/* --------------------------------------------------------------------------------------------------*/