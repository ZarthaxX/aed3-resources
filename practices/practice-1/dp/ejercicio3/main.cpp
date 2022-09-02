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


/*
d)complejidad de DP: n*k en el peor caso (igualmente nos toma n*k inicializar la matriz
DP es mejor que BT cuando n*k << 2^n, sino BT por la inicializacion de la matriz ( se puede discutir igual )

e)typo en el 4) dice M[i,j] := M[i - 1, j] ? (j - C[j] = 0 ? M[i - 1, j - C[j]]), el C[j] deberia ser C[i]

f)
para mejorarla, se puede modificar la M[i,j], para que sea M[j], de tal forma que tenga la ultima
fila procesada, y luego otra M'[j] donde se pondran los valores de la fila que esta siendo procesada

*/
void solve(){

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

