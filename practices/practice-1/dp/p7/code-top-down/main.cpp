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

int INF=2000000000;
vector<vector<int>> cache;

vector<int> asteroids;

int dp(int j, int c){
	// base case
	if(j == 0) {
		if(c == 0)
			return 0;
		return -INF;
	}
	// illegal, can't go below 0 asteroids
	if(c < 0)
		return -INF;
	
	if(cache[j][c] != -1){
		return cache[j][c];
	}
	
	int doNone = dp(j-1,c);
	int buyOne = dp(j-1,c-1)-asteroids[j];
	int sellOne = dp(j-1,c+1)+asteroids[j];
	
	return cache[j][c] = max(doNone, max(buyOne, sellOne));
}

void solve(){
	int n;
	cin>>n;
	asteroids = vector<int>(n+1);
	
	for(int i=0;i<n;i++)
		cin>>asteroids[i+1];
	
	cache.assign(n+1,vector<int>(n+1,-1));

	cout<< dp(n, 0) << endl;
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