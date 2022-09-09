#include <bitset>
#include <bits/stdc++.h>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <set>

using namespace std;

typedef long long ll;

ll pot(ll b,ll e){
	if(e==0)
		return 1;
	if(e==1)
		return b;
		
	ll res=b;
	while(--e>0)res*=b;
	return res;
}

ll INF=10000000;
ll n,w;

vector<vector<ll>> cache;
vector<ll> v;
	
bool dp(ll i,ll s){
	// base cases
	if(s > w)
		return false;
	if(i==n)
		return s==w;
	// dp check
	if(cache[i][s] != -1){
		return cache[i][s];
	}
	// recursive step
	bool sum = dp(i+1, s+v[i]);
	bool mul = dp(i+1, s*v[i]);
	bool pow = dp(i+1, pot(s,v[i]));

	cache[i][s] = (sum || mul || pow);

	return cache[i][s];
}

string reconstruct(ll i, ll s){
	// base case
	if(i == n) {
		return "";
	}
	// recursive step
	if(cache[i+1][s+v[i]]){
		return " + " + to_string(v[i]) + reconstruct(i+1, s+v[i]);
	}
	if(cache[i+1][s*v[i]]){
		return  " * " + to_string(v[i]) + reconstruct(i+1, s*v[i]);
	}
	if(cache[i+1][pot(s,v[i])]){
		return " ^ " + to_string(v[i]) + reconstruct(i+1, pot(s, v[i]));
	}

	// should never reach this point if there is a solution
	return "";
}

void solve(){
	cin>>n>>w;
	
	v = vector<ll>(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	cache.assign(n+1,vector<ll>(w+1,-1));

	bool possible = dp(1, v[0]);
	if(possible){
		string sol = to_string(v[0]) + reconstruct(1, v[0]);
		cout << sol << endl;
	} else {
		cout << "Impossible" << endl;
	}
}

int main(int argc, char **argv) {
	int testcases = 1;
	cin>>testcases;
	int cases = 0;
	while(cases++ != testcases){
		cout<<"Case #"<<cases<<": ";
		solve();
	}
}

