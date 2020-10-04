#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int nv, ne;
int vis[100009];
int color[100009];
vector<int> g[100009];
bool isColorable = true;

void dfs(int v, int col)
{
	vis[v] = 1;
	color[v] = col;
	// check if back edges violates any coloring
	for(auto bk : g[v])
		if(vis[bk] && color[bk] == col)
			isColorable = false;
	// color children
	for(auto ch : g[v])
		if(!vis[ch])
			dfs(ch, 1 ^ col);

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
	
	for(int i = 1; i <= nv; ++i)
		if(!vis[i])
			dfs(i, 1);
	if(isColorable){
		for(int i = 1; i <= nv; ++i)
			cout << color[i] + 1 << ' ';
		cout << '\n';
	}
	else{
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}
