#include <iostream>
#include <set>
#include <vector>

using namespace std;
const long long inf = 1e18;
const int mxv = 500;
int nv, ne;
long long dist[mxv + 5][mxv + 5];

void floyd_warshall()
{
	// we use the adj matrix to calculate dp too
	// without intermediate vertices in the path,
	// the shortest route is the edje itself
	for(int k = 1; k <= nv; ++k){
		for(int sv = 1; sv <= nv; ++sv){
			for(int ev = 1; ev <= nv; ++ev){
				dist[sv][ev] = min(dist[sv][ev], dist[sv][k] + dist[k][ev]);
			}
		}
	}
	
}

int main()
{

	int q;
	cin >> nv >> ne >> q;

	// there may be multiple edges bw two vertices	
	for(int va = 0; va <= nv; ++va){
		for(int vb = 0; vb <= nv; ++vb){
			dist[va][vb] = inf;
			if(va == vb){
				// dont forget
				dist[va][vb] = 0;
			}
		}
	}
	
	for(int i = 1; i <= ne; ++i){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}
	
	floyd_warshall();
	while(q--){
		int a, b;
		cin >> a >> b;
		if(dist[a][b] == inf)
			cout << -1 << '\n';
		else
			cout << dist[a][b] << '\n';
	}
	return 0;
}
