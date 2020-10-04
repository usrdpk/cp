#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;


int nr, nc;
int sr, sc;
int er, ec;
char grid[1009][1009];
int dist[1000009];
char dir[1000009];
int parR[1000009];
int parC[1000009];
deque<pair<int, int>> q;

void setPar(int r, int c, int pr, int pc)
{
	int id = r * nc + c;
	parR[id] = pr;
	parC[id] = pc;
}

int getParR(int r, int c)
{
	int id = r * nc + c;
	return parR[id];
}

int getParC(int r, int c)
{
	int id = r * nc + c;
	return parC[id];
}

void setDir(int r, int c, char d)
{
	int id = r * nc + c;
	dir[id] = d;
}

char getDir(int r, int c)
{
	int id = r * nc + c;
	return dir[id];
}

void setDist(int r, int c, int d)
{
	int id = r * nc + c;
	dist[id] = d;

}

int getDist(int r, int c)
{
	int id = r * nc + c;
	return dist[id];
}

bool isGood(int r, int c)
{
	if(r > nr || r < 1)
		return false;
	if(c > nc || c < 1)
		return false;
	if(grid[r][c] == '#')
		return false;
	if(getDist(r, c) != -1)
		return false;
	return true;
}

void bfs()
{
	q.push_back({sr, sc});
	setDist(sr, sc, 0);
	while(!q.empty()){
		auto nd = q.front();
		q.pop_front();
		int r = nd.first;
		int c = nd.second;
		// cout << r << ' ' << c << ':' << dist[{r, c}] << endl;
		if(isGood(r + 1, c)){
			setDist(r + 1, c, getDist(r, c) + 1);
			setDir(r + 1, c, 'D');
			setPar(r + 1, c, r, c);
			q.push_back({r + 1, c});
		}
		if(isGood(r - 1, c)){
			setDist(r - 1, c, getDist(r, c) + 1);
			setDir(r - 1, c, 'U');
			setPar(r - 1, c, r, c);
			q.push_back({r - 1, c});
		}
		if(isGood(r, c + 1)){
			setDist(r, c + 1, getDist(r, c) + 1);
			setDir(r, c + 1, 'R');
			setPar(r, c + 1, r, c);
			q.push_back({r, c + 1});
		}
		if(isGood(r, c - 1)){
			setDist(r, c - 1, getDist(r, c) + 1);
			setDir(r, c - 1, 'L');
			setPar(r, c - 1, r, c);
			q.push_back({r, c - 1});
		}
	}
}

void printAns()
{
	if(getDist(er, ec) == -1)
		cout << "NO\n";
	else{
		cout << "YES\n";
		cout << getDist(er, ec) << '\n';
		string path = "";
		int r = er, c = ec;
		pair<int, int> bad = {-1, -1};
		while(!(r == sr && c == sc)){
			int xr = getParR(r, c);
			int xc = getParC(r, c);
			path += getDir(r, c);
			r = xr;
			c = xc;
		}
		reverse(path.begin(), path.end());
		cout << path << '\n';
	}
}

int main()
{
	cin >> nr >> nc;
	for(int r = 1; r <= nr; ++r)
		cin >> &grid[r][1];
	
	for(int r = 1; r <= nr; ++r)
		for(int c = 1; c <= nc; ++c){
			if(grid[r][c] == 'A'){
				sr = r;
				sc = c;
			}
			if(grid[r][c] == 'B'){
				er = r;
				ec = c;
			}
			setDist(r, c, -1);
			setDir(r, c, 'X');
			setPar(r, c, -1, -1);
		}
	bfs();
	printAns();
	return 0;
}
