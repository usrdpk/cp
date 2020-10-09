#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int nv;
vector<int> g[200009];

// max length path ending at i
int dp[200009];
// max length path passing throug i
int path[200009];
int dia;

void dfs(int v, int p)
{
	int nch = 0;
	for(auto ch : g[v]){
		if(ch == p)
			continue;
		dfs(ch, v);
		++nch;
	}

	if(nch){
		// not leaf
		// find two children having 
		// max length paths ending at them
		int f = -1, s = -1;
		for(auto ch : g[v]){
			if(ch == p)
				continue;
			if(dp[ch] > f){
				s = f;
				f = dp[ch];
			}
			else if(dp[ch] > s){
				s = dp[ch];
			}
		}
		if(nch > 1)
			path[v] = f + s + 2;
		else
			path[v] = f + 1;
		dp[v] = f + 1;
	}
	else{
		dp[v] = 0;
		path[v] = 0;
	}
	dia = max(dia, path[v]);
}

int main()
{
	cin >> nv;
	for(int i = 1; i < nv; ++i){
		int a, b;
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	
	dfs(1, 0);
	cout << dia << '\n';
	return 0;
}
