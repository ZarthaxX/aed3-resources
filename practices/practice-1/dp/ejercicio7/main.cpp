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
int m,n;

int BT(vector<vector<int>>& matrix, int i,int j){
	if(i==m-1&&j==n-1)
		return max(1,1-matrix[i][j]);
		
	if(i==m-1)
		return max(1,BT(matrix, i, j+1)-matrix[i][j]);
		
	if(j==n-1)
		return max(1,BT(matrix, i+1, j)-matrix[i][j]);
	
	return max(1,min(BT(matrix, i+1, j),BT(matrix, i, j+1))-matrix[i][j]);
}

vector<vector<int>> cache;

int DP(vector<vector<int>>& matrix, int i,int j){
	
	if(i==m-1&&j==n-1)
		return max(1,1-matrix[i][j]);
	
	if(cache[i][j] != -1)
		return cache[i][j];
	
	if(i==m-1)
		return cache[i][j] = max(1,DP(matrix, i, j+1)-matrix[i][j]);
		
	if(j==n-1)
		return cache[i][j] = max(1,DP(matrix, i+1, j)-matrix[i][j]);
	
	return cache[i][j] = max(1,min(DP(matrix, i+1, j),DP(matrix, i, j+1))-matrix[i][j]);
}

int DP_iterative_rows(vector<vector<int>>& matrix){

	vector<int> cache(n,-1);
	
	cache[n-1] = max(1,1-matrix[m-1][n-1]);
	
	for(int j=n-2;0<=j;j--)
		cache[j] = max(1,cache[j+1]-matrix[m-1][j]);
	
	for(int i=m-2;0<=i;i--){
		for(int j=n-1;0<=j;j--){
			if(j==n-1)
				cache[j] = max(1,cache[j]-matrix[i][j]);
			else
				cache[j] = max(1,min(cache[j],cache[j+1])-matrix[i][j]);
		}
	}
	
	return cache[0];
}

int DP_iterative_cols(vector<vector<int>>& matrix){

	vector<int> cache(m,-1);
	
	cache[m-1] = max(1,1-matrix[m-1][n-1]);
	
	for(int i=m-2;0<=i;i--)
		cache[i] = max(1,cache[i+1]-matrix[i][n-1]);
	
	for(int j=n-2;0<=j;j--){
		for(int i=m-1;0<=i;i--){
			if(i==m-1)
				cache[i] = max(1,cache[i]-matrix[i][j]);
			else
				cache[i] = max(1,min(cache[i],cache[i+1])-matrix[i][j]);
		}
	}
	
	return cache[0];
}

void solve(){
	cin>>m>>n;
	
	vector<vector<int>> matrix(m,vector<int>(n));
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
			
	cout<<BT(matrix,0,0)<<endl;
	
	cache.assign(m,vector<int>(n));
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cache[i][j]=-1;
			
	cout<<DP(matrix,0,0)<<endl;
	cout<<DP_iterative_rows(matrix)<<endl;
	cout<<DP_iterative_cols(matrix)<<endl;
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

