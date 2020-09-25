#include <bits/stdc++.h>
#define int long long int
using namespace std;



const int N = 3e5 + 5;
 
int fact[N], invfact[N];
 
 
const int mod = 998244353;
 
int binpow(int base, int pow, int MOD) {
        if(pow == 0)
                return 1;
        int res = binpow(base, pow / 2, MOD);
        res %= mod;
        int ans = 1;
        if(pow & 1)
                ans *= base;
        return (ans * ((res * res) % mod) % mod);
}
 
int modInverse(int k) {
        return binpow(k, mod - 2, mod);
}
 
void fac(int n) {
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i <= n; i++) {
                fact[i] = fact[i - 1] * i;
                fact[i] %= mod;
        }
        invfact[n - 1] = modInverse(fact[n - 1]);
        //o(invfact[n - 1]);
        for(int i =n - 2; i >= 0; i--) {
                invfact[i] = invfact[i + 1] * (i + 1);
                invfact[i] %= mod;
        }
}


// gcd(a, b) using euclidean algo in O(log(min(a,b))) through lame's theorem
int gcdR(int a, int b){
        if(b != 0){
                return gcdR(b, a%b);
        }
        return a;
}

// gcd(a, b) non recursive
int gcd(int a, int b){
        while(b){
                a %= b;
                swap(a, b);
        }
        return a;
}


int lcm(int a, int b){
        return ((a)/gcd(a,b))*b; // to avoid integer flow
}

int extendedEuclidGCD(int a, int b, int &x, int &y){
        if(a == 0){
                x = 0;
                y = 1;
                return(a, b, x, y);
        }
        int x1, y1;
        int d;
        d = extendedEuclidGCD(b%a, a, x1, y1);
        x = y1 - (b/a)*x1;
        y = x1;
        return d;       
}


signed main() {
        #ifndef ONLINE_JUDGE
                freopen("in.txt", "r", stdin);
                freopen("op.txt", "w", stdout);
        #endif

        return 0;
}



