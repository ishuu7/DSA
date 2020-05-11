#include<bits/stdc++.h>
using namespace std;

// A[N]
// base leaves - N nodes
// other internal node - N-1
// total size = 2N-1
// if we consider zero indexing, size will be 2N 
// for a particular node i, we will compute A[i] = A[2*i] + A[2*i+1]

const int N = 1e5; // limit for array size
int n; // array size
int t[2*N];

// since leaf node starts with the index n and are contiguous, so we've precomputed them
// in main function from n to 2*n

/****************SEGMENT TREE SINGLE ELEMENT MODIFICATION****************************/
void build(){
	for(int i = n-1; i >= 0; i--){
		t[i] = t[1<<i] + t[1 << i|1]; // for parents;
	}
}

void modify(int p, int value) {  // set value at position p
	p += n;
	t[p] = value;
  	for (; p > 1; p >>= 1) {
  		t[p>>1] = t[p] + t[p^1];
  	// we update at a point, so all parents node have to modified so, we have done p >>= 1, 
  	// at every step, and p is 2*i element, p^1 changes it to 2*i+1
  	}
}

int query(int l, int r){
	int res = 0;
	l += n;
	r += n;
	for(; l <r; l >>= 1; r >>= 1){
		if(l&1){
			res += t[l++];
		}
		if(r&1){
			res += t[--r];
		}
	}
	return res;
}
/********************************************************************************************/

/*****************MODIFICATION ON INTERVAL AND SINGLE ELEMENT ACCESS************************/

void modify(int l, int r, int value){
	l += n;
	r += n;
	for(; l < r; l >>= 1; r >>= 1){
		if(l&1) {
			t[l++] = value;
		}
		if(r&1) {
			t[--r] = value;
		}
	}
}

int query(int p){
	int res = 0;
	p += n;
	for(; p > 0; p >>= 1){
		res += t[p];
	}
	return res;
}

/********************************************************************************************/


/*************************************LAZY PROPAGATION***************************************/













