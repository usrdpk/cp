// Find the longest subarray with distinct elements.

#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	map<int, int> cnt;
	int mx = 0;
	for(int s = 0, e = 0; s < n; ++s){
		while(e < n && cnt[a[e]] < 1){
			++cnt[a[e]];
			++e;
		}
		mx = max(mx, e - s);
		--cnt[a[s]];
	}	
	cout << mx << '\n';
	return 0;
}
