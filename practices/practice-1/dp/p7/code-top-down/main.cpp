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

#define INF 2000000000

typedef long long LL;

using namespace std;

vector<vector<LL>> cache;

long long n;
vector<LL> asteroids;

LL dp(LL j, LL c){
	// base case
	if(j == n) {
		// we got to the end without asteroids
		if(c == 0)
			return 0;
		// we still have at least 1 asteroid, so it's an illegal state
		return -INF;
	}

	// illegal state, can't go below 0 asteroids at any given point
	if(c < 0)
		return -INF;
	
	// check if we already computed this state
	if(cache[j][c] != -1){
		return cache[j][c];
	}
	
	// recursive step
	LL doNone = dp(j+1, c);
	LL buyOne = dp(j+1, c+1) - asteroids[j];
	LL sellOne = dp(j+1, c-1) + asteroids[j];
	
	// save result in cache and return result
	return cache[j][c] = max(doNone, max(buyOne, sellOne));
}

void solve(){
	cin>>n;

	asteroids = vector<LL>(n);
	
	for(int i=0;i<n;i++)
		cin>>asteroids[i];
	
	cache.assign(n,vector<LL>(n,-1));

	cout<< dp(0, 0) << endl;
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