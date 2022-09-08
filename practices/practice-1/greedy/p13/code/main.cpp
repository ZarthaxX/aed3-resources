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

using namespace std;

void solve(){
	priority_queue<int, vector<int>, greater<int>> people1;
	priority_queue<int, vector<int>, greater<int>> people2;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int p;
		cin >> p;
		people1.push(p);
	}
	cin >> n;
	for(int i=0; i<n; i++){
		int p;
		cin >> p;
		people2.push(p);
	}

	int couples = 0;
	while(!people1.empty() && !people2.empty()) {
		int p1 = people1.top();
		int p2 = people2.top();

		if(abs(p1 - p2) <= 1) {
			couples++;
			people1.pop();
			people2.pop();
		} else if(p1 < p2){
			people1.pop();
		}else{
			people2.pop();
		}
	}

	cout << couples << endl;
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

