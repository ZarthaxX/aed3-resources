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

#define TESTCASES
#define IO_SPEEDUP

int INF=10000000;
int n;
vector<vector<int>> cache;

int dp(vector<int>& CW,vector<int>& CS,int i,int s){
	if(i==n)
		return 0;
	
	if(cache[i][s]!=-1){
		cerr<<"Collision!"<<endl;
		return cache[i][s];
	}
	
	int use_box=-INF;
	int skip_box=-INF;
	
	if(s-CW[i]>=0){
		use_box = 1 + dp(CW,CS,i+1,min(s-CW[i],CS[i]));
	}
	
	skip_box = dp(CW,CS,i+1,s);
	
	return cache[i][s] = max(use_box,skip_box);
}

int dp_iterative(vector<int>& CW,vector<int>& CS){
	
	vector<vector<int>> memo;
	
	int CW_sum = accumulate(CW.begin(),CW.end(),0);
	memo.assign(n+1,vector<int>(CW_sum+1,0));
	
	for(int i=n-1;0<=i;i--){
		for(int s=0;s<=CW_sum;s++){
			int use_box=-INF;
			int skip_box=-INF;
			
			if(s-CW[i]>=0){
				use_box = 1 + memo[i+1][min(s-CW[i],CS[i])];
			}
			
			skip_box = memo[i+1][s];
			memo[i][s] = max(use_box,skip_box);
		}
	}
	
	return memo[0][CW_sum];
}



void solve(){
	cin>>n;
	
	vector<int>CW(n);
	vector<int>CS(n);
	
	for(int i=0;i<n;i++)
		cin>>CW[i];
	for(int i=0;i<n;i++)
		cin>>CS[i];
	
	int CW_sum = accumulate(CW.begin(),CW.end(),0);
	cache.assign(n,vector<int>(CW_sum+1,-1));
	
	cout<<dp(CW,CS,0,CW_sum)<<endl;
	cout<<dp_iterative(CW,CS)<<endl;
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

