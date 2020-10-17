#include <iostream>
#include <set>
#include <vector>

using namespace std;

const long long inf = 1e18 + 100;
const int maxv = 1e5;
int nv, ne;
vector<pair<int, int>> g[maxv + 10];

long long dist[maxv + 10];

void djikstra(int sv)
{
	for(int i = 0; i <= nv; ++i)
		dist[i] = inf;
	
	set<pair<long long, int>> q;
	dist[sv] = 0;
	q.insert({dist[sv], sv});	
	
	while(!q.empty()){
		// take the least dist vertex from q
		int cv = (*q.begin()).second;
		q.erase(q.begin());
		// relax its children
		for(auto ch : g[cv]){
			int chv = ch.first;
			int ecost = ch.second;
			if(dist[cv] + ecost < dist[chv]){
				q.erase({dist[chv], chv});
				dist[chv] = dist[cv] + ecost;
				q.insert({dist[chv], chv});
			} 
		}
	}
}

int main()
{

	cin >> nv >> ne;
	for(int i = 1; i <= ne; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		// the graph is directed 
		// g[b].emplace_back(make_pair(a, c));
	}
	djikstra(1);
	for(int i = 1; i <= nv; ++i){
		cout << dist[i] << ' ';
	}
	cout << '\n';
	return 0;
}
