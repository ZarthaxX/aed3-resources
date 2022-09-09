#include <bitset>
#include <bits/stdc++.h>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
	while(--e>0)
		res*=b;

	return res;
}

ll INF=10000000;
ll n,w;

vector<vector<ll>> cache;
vector<ll> v;

ll dp(){
	
	cache.assign(n+1,vector<ll>(w+1,-1));

	cache[n][w] = true;
	for(ll i=0;i<w;i++)
		cache[n][i] = false;
	
	for(ll i=n-1;0<i;i--){
		for(ll s=0;s<=w;s++){
			ll sum = 0, mul = 0, pow = 0;
			if(s+v[i]<=w){
				sum=cache[i+1][s+v[i]];
			}
			if(s*v[i]<=w){
				mul=cache[i+1][s*v[i]];
			}
			if(pot(s,v[i])<=w){
				pow=cache[i+1][pot(s,v[i])];
			}

			cache[i][s] = (sum || mul || pow);
		}	
	}

	return cache[1][v[0]];
}

string reconstruct(){
	string solution = to_string(v[0]);
	ll s = v[0];
	ll i = 1;

	while(i < n){
		if(s+v[i] < w+1 && cache[i+1][s+v[i]]){
			solution += " + " + to_string(v[i]);
			s = s + v[i];
		} else if(s*v[i] < w+1 && cache[i+1][s*v[i]]){
			solution += " * " + to_string(v[i]);
			s = s * v[i];
		} else if(pot(s,v[i]) < w+1 && cache[i+1][pot(s,v[i])]){
			solution += " ^ " + to_string(v[i]);
			s = pot(s, v[i]);
		}
		i++;
	}
	
	return solution;
}

void solve(){
	cin>>n>>w;
	
	v = vector<ll>(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	bool possible = dp();
	if(possible){
		string sol = reconstruct();
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