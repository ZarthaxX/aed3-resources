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
	int n;
	cin >> n;

	// Store multiset in ascending order
	priority_queue<int, vector<int>, greater<int>> nums;
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		nums.push(num);
	}

	// while there are at least 2 elements, add the 2 smallest elements and store result in multiset
	int cost = 0;
	while(nums.size() > 1){
		int top1 = nums.top();
		nums.pop();
		int top2 = nums.top();
		nums.pop();

		int nextNum = top1 + top2;
		cost += nextNum;

		nums.push(nextNum);
	}

	cout << cost << endl;
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

