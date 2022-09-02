#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")

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
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long ll;

#define TESTCASES
#define IO_SPEEDUP

ll pot(ll b,ll e){
	if(e==0)
		return 1;
	if(e==1)
		return b;
		
	ll res=b;
	while(--e>0)res*=b;
	return res;
}

int INF=10000000;
int n,w;

vector<vector<pair<int,string>>> cache;
	
pair<int,string> dp(vector<int>&v,int i,ll s){
	
	if(s > w)
		return make_pair(0,"");
	
	if(i==n){
		if(s==w)
			return make_pair(1,"");
		else
			return make_pair(0,"");
	}
	
	if(cache[i][s].first != -1){
		cerr<<"Collision!"<<endl;
		return cache[i][s];
	}
	
	pair<int,string> sum,mul,pow;
	
	sum = dp(v, i+1, s+v[i]);
	mul = dp(v, i+1, s*v[i]);
	pow = dp(v, i+1, pot(s,v[i]));
	
	sum.second="+"+sum.second;
	mul.second="*"+mul.second;
	pow.second="^"+pow.second;
	
	return cache[i][s] = max(sum,max(mul,pow));
}

pair<int,string> dp_iterative(vector<int>&v){
	
	vector<vector<pair<int,string>>> memo(n,vector<pair<int,string>>(w+1));
	
	memo[n-1][w]={1,""};
	
	for(int i=0;i<w;i++)
		memo[n-1][i]={0,""};
	
	for(int i=n-1;0<i;i--){
		for(ll s=0;s<=w;s++){
			
			pair<int,string> sum(0,""),mul(0,""),pow(0,"");
			
			if(s+v[i]<=w){
				sum=memo[i][s+v[i]];
				sum.second="+"+sum.second;
			}
			if(s*v[i]<=w){
				mul=memo[i][s*v[i]];
				mul.second="*"+mul.second;
			}
			if(pot(s,v[i])<=w){
				pow=memo[i][pot(s,v[i])];
				pow.second="^"+pow.second;
			}
			memo[i-1][s] = max(sum,max(mul,pow));
		}	
	}
	return memo[0][v[0]];
}

void solve(){
	cin>>n>>w;
	
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	cache.assign(n+1,vector<pair<int,string>>(w+1,make_pair(-1,"")));
	
	cout<<dp(v,1,v[0]).first<<" "<<dp(v,1,v[0]).second<<endl;
	cout<<dp_iterative(v).first<<" "<<dp_iterative(v).second<<endl;
}

int main(int argc, char **argv) {
	#ifdef IO_SPEEDUP
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#endif
	
	bool output_to_file=false;
	for(int i=0;i<argc;i++){
		string cmd(argv[i]);
		if(cmd=="read_from_input")
			freopen("input.txt", "rt", stdin);
		if(cmd=="write_to_output"){
			freopen("output.txt", "wt", stdout);
			output_to_file=true;
		}
	}
		
	int testcases = 1;
    #ifdef TESTCASES
	cin>>testcases;
	#endif
	int cases = 0;
	while(cases++ != testcases){
		if(output_to_file)
			cout<<"Case #"<<cases<<": ";
		solve();
		//if(testcases != 0)cout << "---------- END OF TEST " << testcases << " -------------" << endl;
	}
}

