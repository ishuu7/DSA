#include <bits/stdc++.h>
using namespace std;
#define mod (1e9 + 7)
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)

// for claculating (a^n) with recursion

// kedane's algo
int maxSubArr(vector<ll>&nums){
	ll till = 0, ans = INT_MIN;
	for(ll u : nums){
		a += u;
		ans = ans(a, ans);
		a = max(a, 0);	
	}
	return ans;
}


ll binExpR(ll a, ll n){
	if(n == 0)
		return 1;
	ll res = binExp(a, n/2);
	if(n&1)
		return (a*res*(res));
	return res*res;
}

// for claculating (a^n) without recursion
ll binExp(ll a, ll n){
	ll res = 1;
	while(b > 0){
		if(b&1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}


// for calculating (a^n)%modu
long long binExpMod(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}



// gcd(a, b) using euclidean algo in O(log(min(a,b))) through lame's theorem
ll gcdR(ll a, ll b){
	if(b != 0){
		return gcd(b, a%b);
	}
	return a;
}

// gcd(a, b) non recursive
ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}


ll lcm(ll a, ll b){
	return ((a)/gcd(a,b))*b; // to avoid integer flow
}

ll extendedEuclidGCD(ll a, ll b, ll &x, ll &y){
	if(a == 0){
		x = 0;
		y = 1;
		return(a, b, x, y);
	}
	ll x1, y1;
	ll d;
	d = extendedEuclidGCD(b%a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;	
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("inpu.txt", "r", stdin);
		freopen("opt.txt", "w", stdout);
	#endif




		








	return 0;
}



