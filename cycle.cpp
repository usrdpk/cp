#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int nv, ne;
vector<int> g[100009];
int par[100009];
int vis[100009];

vector<int> ans;
int cycle;

void dfs(int v, int p)
{
	vis[v] = 1;
	par[v] = p;

	for(auto ch : g[v])
		if(!vis[ch]){
			dfs(ch, v);
			// stop if you found a cycle
			if(cycle)
				return;
		}
		else{
			// ignore the parent
			if(ch == par[v])
				continue;
			// cycle
			cycle = 1;
			int cur = v;
			while(cur != ch){
				ans.emplace_back(cur);
				cur = par[cur];
			}
			ans.emplace_back(ch);
			ans.emplace_back(v);
			return;
		}
}

int main()
{
	cin >> nv >> ne;
	for(int i = 0; i < ne; ++i){
		int a, b;
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	

	for(int v = 1; v <= nv; ++v){
		if(!vis[v]){
			dfs(v, 0);
			if(cycle)
				break;
		}
	}
	if(cycle){
		cout << ans.size() << '\n';
		for(auto v : ans)
			cout << v << ' ';
		cout << '\n';
	}
	else
		cout << "IMPOSSIBLE\n";
	return 0;
}
