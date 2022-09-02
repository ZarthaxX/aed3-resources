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

int INF=2000000000;

	
pair<int,int> bt(vector<int>&monedas,int i,int j){
	if(i==0){
		if(j<=0)
			return {-j,0};
		else
			return {INF,INF};
	}
	
	pair<int,int> no_uso = bt(monedas,i-1,j);
	pair<int,int> uso = bt(monedas,i-1,j-monedas[i-1]);
	uso.second++;
	
	return min(no_uso,uso);
}

vector<vector<pair<int,int>>>memo;

pair<int,int> dp(vector<int>&monedas,int i,int j){
	if(j<=0)
		return {-j,0};
	if(i==0)
		return {INF,INF};
	
	if(memo[i][j]==make_pair(-1,-1)){
		pair<int,int> no_uso = dp(monedas,i-1,j);
		pair<int,int> uso = dp(monedas,i-1,j-monedas[i-1]);
		uso.second++;
	
		memo[i][j]=min(no_uso,uso);
	}
		
	return memo[i][j];
}
/*
b) complejidad = 2^n
*/

//ej g) dp iterativo
pair<int,int> dp_iterativo(vector<int>&monedas,int n,int k){

	vector<vector<pair<int,int>>> memo2=vector<vector<pair<int,int>>>(n+1,vector<pair<int,int>>(k+1,make_pair(-1,-1)));
	memo2[0][0]={0,0};
	for(int j=1;j<=k;j++)
		memo2[0][j]={INF,INF};
	for(int i=1;i<=n;i++)
		memo2[i][0]={0,0};
		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			pair<int,int> use,no_use;
			if(j-monedas[i-1]<0)
				use = make_pair(-(j-monedas[i-1]),1);
			else{
				use = memo2[i-1][j-monedas[i-1]];
				use.second++;
			}
			no_use=memo2[i-1][j];
			
			memo2[i][j]=min(use,no_use);
		}
	}
		
}

//ej g) dp iterativo
pair<int,int> dp_iterativo2(vector<int>&monedas,int n,int k){

	vector<vector<pair<int,int>>> memo2(2,vector<pair<int,int>>(k+1,make_pair(-1,-1)));
	memo2[0][0]={0,0};
	for(int j=1;j<=k;j++)
		memo2[0][j]={INF,INF};
		
	int last_row=0;
	
	for(int i=1;i<=n;i++){
		int actual_row=(last_row+1)%2;
		for(int j=1;j<=k;j++){
			pair<int,int> use,no_use;
			if(j-monedas[i-1]<0)
				use = make_pair(-(j-monedas[i-1]),1);
			else{
				use = memo2[last_row][j-monedas[i-1]];
				use.second++;
			}
			no_use=memo2[last_row][j];
			
			memo2[actual_row][j]=min(use,no_use);
		}
		
		last_row=(last_row+1)%2;
	}
	
	return memo2[last_row][k];
}

void solve(){
	int n,k;
	cin>>n;
	cin>>k;
	vector<int>monedas(n);
	for(int i=0;i<n;i++)
		cin>>monedas[i];
		
	memo=vector<vector<pair<int,int>>>(n+1,vector<pair<int,int>>(k+1,make_pair(-1,-1)));
	
	auto solution=dp(monedas,n,k);
	cout<<solution.first<<" "<<solution.second<<endl;
	
	//solution=bt(monedas,n,k);
	//cout<<solution.first<<" "<<solution.second<<endl;
	
	
	solution = dp_iterativo(monedas,n,k);
	
	cout<<memo[n][k].first<<" "<<memo[n][k].second<<endl;
	
	solution = dp_iterativo2(monedas,n,k);
	
	cout<<memo[n][k].first<<" "<<memo[n][k].second<<endl;
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
		}else
			cout<<cmd<<endl;
	}
	cout<<"\"aaa\""<<endl;
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

