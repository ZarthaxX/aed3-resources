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

int INF=100000000;

//c
vector<vector<int>> cache;

//complejidad = 
int dp(vector<int>& cuts, int i, int j){

	if(cache[i][j] != -1){
		cerr<<"Collision!"<<endl;
		return cache[i][j];
	}
		
	int min_cut = INF;
	bool made_cut = false;
	
	for(int cut : cuts){
		if(i< cut && cut < j){
		   	made_cut=true;
		   	
			int tmp_cut = dp(cuts,i,cut) + 
						  dp(cuts,cut,j);
			
			min_cut = min(min_cut, tmp_cut);
		}
	}
	
	
	if(!made_cut)
		return 0;
	else
		min_cut += (j - i);
	
	return cache[i][j] = min_cut;
}

int dp_iterative(vector<int>& cuts, int length){

	vector<vector<int>> memo(length+1,vector<int>(length+1,-1));
	
	for(int i=0;i<=length;i++)
		memo[i][i]=0;
	
	for(int l=1;l<=length;l++){
		for(int i=0;i+l<=length;i++){
			
			int j=i+l;
			int min_cut = INF;
			bool made_cut = false;
			
			for(int cut : cuts){
				if(i< cut && cut < j){
				   	made_cut=true;
				   	
					int tmp_cut = memo[i][cut] + 
								  memo[cut][j];
					
					min_cut = min(min_cut, tmp_cut);
				}
			}
			
			if(i>length+1||j>length+1)
				throw -1;
				
			if(!made_cut)
				min_cut=0;
			else
				min_cut += (j - i);
				
			memo[i][j] = min_cut;
		}
	}
	return memo[0][length];
}

//d
//complejidad = cuts^3
int dp_2(vector<int>&cuts, int i, int j){
	
	if(j-i == 1)
		return 0;
		
	int min_cut = INF;
	
	for(int k=i+1;k<j;k++){
		int tmp_cut = dp_2(cuts,i,k) +
				  dp_2(cuts,k,j);	
				
		min_cut = min(min_cut, tmp_cut);
	}
	
	return min_cut + cuts[j]-cuts[i];
}

//complejidad = cuts^3
int dp_2_iterative(vector<int>&cuts){
	
	vector<vector<int>> memo(cuts.size(),vector<int>(cuts.size(),-1));
	
	for(int i=0;i<cuts.size()-1;i++)
		memo[i][i+1]=0;
	
	for(int l=2;l<cuts.size();l++){
	
		for(int i=0;i+l<cuts.size();i++){
			int j = i+l;
			int min_cut = INF;
			
			for(int k=i+1;k<j;k++){
				
				int tmp_cut = memo[i][k] +
				  			  memo[k][j];	
				
				min_cut = min(min_cut, tmp_cut);
			}
			
			memo[i][j]= min_cut + cuts[j]-cuts[i];
		}
	}
	
	return memo[0][cuts.size()-1];
}

void solve(){
	int length,n;
	cin>>length>>n;
	vector<int>cuts(n);
	
	for(int i=0;i<n;i++)
		cin>>cuts[i];

	cache.assign(length+1,vector<int>(length+1,-1));
	cout<< dp(cuts, 0, length) << endl;
	cout<< dp_iterative(cuts, length) << endl;
	
	//d
	cuts.push_back(0);
	cuts.push_back(length);
	sort(cuts.begin(),cuts.end());
	
	cout << dp_2(cuts,0,cuts.size()-1) << endl;
	cout << dp_2_iterative(cuts) << endl;
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

