#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int nv;
vector<int> g[200009];
int dpi[200009], dpe[200009];

void dfs(int v, int p)
{
	int nch = 0;
	int all_edges = 0;
	for(auto ch : g[v]){
		if(ch != p){
			++nch;
			dfs(ch, v);
			all_edges += max(dpi[ch], dpe[ch]);
		}
	}

	if(nch){
		int ansi = 0;
		for(auto ch : g[v]){
			if(ch != p){
				int rem_edges = all_edges - max(dpi[ch], dpe[ch]);
				int cur_edges = rem_edges + dpe[ch] + 1;
				ansi = max(ansi, cur_edges);
				dpe[v] += max(dpe[ch], dpi[ch]);
			}
		}
		dpi[v] = ansi;
	}
	else{
		// leaf
		dpi[v] = 0;
		dpe[v] = 0;
	}
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
	cout << max(dpi[1], dpe[1]) << '\n';
	return 0;
}
