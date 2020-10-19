#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int nv, ne;

vector<int> g[100005];
vector<int> ans;
int indeg[100005];

int main()
{
	cin >> nv >> ne;
	for(int i = 1; i <= ne; ++i){
		int f, s;
		cin >> f >> s;
		g[f].push_back(s);
		++indeg[s];
	}
	
	vector<int> ans;
	// maintain a queue with vertices with indegree = 0
	queue<int> q;
	for(int v = 1; v <= nv; ++v){
		if(!indeg[v]){
			q.push(v);
		}
	}

	while(!q.empty()){
		// get a vertex with indegree = 0
		int v = q.front();
		ans.push_back(v);
		q.pop();
		// update its neighbours
		for(auto nbr : g[v]){
			--indeg[nbr];
			if(!indeg[nbr])
				q.push(nbr);
		}
	}
	
	// if a vertex with indegree != 0 exists,
	// then not a DAG
	int cycle = 0;
	for(int v = 1; v <= nv; ++v){
		if(indeg[v])
			cycle = 1;
	}
	if(cycle){
		cout << "IMPOSSIBLE\n";
	}
	else{
		for(auto v : ans)
			cout << v << ' ';
		cout << '\n';
	}
	
	return 0;
}
