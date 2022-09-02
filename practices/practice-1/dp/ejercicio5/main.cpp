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
vector<vector<int>> cache;

int dp(vector<int>& asteroids, int j, int c){
	
	if(j<c)
		return -INF;
	
	if(j==0)
		return 0;
	
	if(cache[j][c] != -1){
		cerr<<"Collision!"<<endl;
		return cache[j][c];
	}
	
	if(j==c){
		return cache[j][c] = dp(asteroids,j-1,c-1)-asteroids[j];
	}
	
	if(c == 0){
		int do_none = dp(asteroids,j-1, 0);
		int sell_one = dp(asteroids,j-1, 1)+asteroids[j];
		return cache[j][c] = max(do_none, sell_one);
	}
	
	int do_none = dp(asteroids,j-1,c);
	int buy_one = dp(asteroids,j-1,c-1)-asteroids[j];
	int sell_one = dp(asteroids,j-1,c+1)+asteroids[j];
	
	return cache[j][c] = max(do_none, max(buy_one, sell_one));
}

void solve(){
	int n;
	cin>>n;
	vector<int>asteroids(n+1);
	
	for(int i=0;i<n;i++)
		cin>>asteroids[i+1];
	
	cache.assign(n+1,vector<int>(n+1,-1));
	cout<< dp(asteroids, n, 0) << endl;
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

