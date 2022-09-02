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



void solve(){
	ll nv,nw;
	cin>>nv>>nw;
	
	vector<int>v(nv),w(nw);
	
	for(int& e : v)
		cin>>e;
	for(int& e : w)
		cin>>e;
	
	sort(v.begin(),v.end());
	sort(w.begin(),w.end());
	
	int iv=0;
	int iw=0;
	int couples=0;
	
	while(iv<nv&&iw<nw){
		if(v[iv]<w[iw]){
			if(w[iw]-v[iv]==1){
				iw++;
				iv++;
				couples++;
			}else{
				iv++;
			}
		}else if(w[iw]<v[iv]){
			if(v[iv]-w[iw]==1){
				iw++;
				iv++;
				couples++;
			}else{
				iw++;
			}
		}else{
			iw++;
			iv++;
			couples++;
		}
	}
	
	cout<<couples<<endl;
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

