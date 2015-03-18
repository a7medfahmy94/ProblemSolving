/*
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=467&page=show_problem&problem=2989
 *
 * to say that C is the LCA(A,B) means that
 * C is the least common multiple of A & B
 *
 * We have A & C and we need to find the minimum B
 * such that LCA(A,B) = C
 *
 * If we have A & B we can easily obtain C by "factorizing"
 * A and B to their prime factors , and compare each prime factor
 * of A to its corresponding one of B,call it P,
 * to construct a number C that is divisible by both A and B
 * that number (C) must have P in its prime factors
 * not only that, but also the power of P in C has to be
 * at least the max(power of P in A,power of P in B).
 *
 * As we're looking for the minimum such C, we'll take that max
 *
 * Now we have A,C , we compare each prime factor
 * if primeFactorC[i] > primeFactorA[i]
 * then this prime has to come from B, include it in result.
 *
 * Ex:
 * A = 6 , C = 54
 * factorization of A:
 * 2 * 3
 * factorization of C:
 * 2 * 3 * 3 * 3
 *
 * C has 1 of 2 , also is A , so B doesn't need any 2's
 * C has 3 of 3 , but A has only 1, so B has to have 3^3
 *
 * so the answer is 3*3*3 = 27.
 *
 */
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define F first
#define S second
#define all(x) (x).begin(),(x).end()

using namespace std;



void factorize(int n,map<int,int>&f){
	for(int i = 2 ; i <= n / i; ++i){
		while(!(n%i)){
			n/=i;
			++f[i];
		}
	}
	if(n-1)++f[n];
}



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t , a , b;
	cin >> t;
	while(t --> 0){
		cin >> a >> b;
		if(b%a){
			cout << "NO SOLUTION\n";
			continue;
		}
		map<int,int> af , bf;
		factorize(a,af);factorize(b,bf);
		int ans = 1;
		for(auto& x: bf){
			if(x.S > af[x.F]){
				ans *= round(pow(x.F,x.S));
			}
		}
		cout << ans << endl;
	}
}
