#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int nv, ne;
int dist[100009];
int par[100009];
vector<int> g[100009];

void bfs()
{
	deque<int> q;
	q.push_back(1);
	dist[1] = 0;
	par[1] = -1;

	while(!q.empty()){
		int v = q.front();
		q.pop_front();
		for(auto ch : g[v])
			if(dist[ch] == -1){
				dist[ch] = dist[v] + 1;
				par[ch] = v;
				q.push_back(ch);
			}
	}
}

void printAns()
{
	if(dist[nv] == -1)
		cout << "IMPOSSIBLE\n";
	else{
		cout << dist[nv] + 1 << '\n';
		vector<int> path;
		int v = nv;
		path.emplace_back(v);
		while(par[v] != -1){
			path.emplace_back(par[v]);	
			v = par[v];
		}
		reverse(path.begin(), path.end());
		for(auto s : path)
			cout << s << ' ';
		cout << '\n';
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
	for(int i = 0; i <= nv; ++i)
		dist[i] = -1;
	bfs();
	printAns();
}
