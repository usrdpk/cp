/**
 * Range sum with, range updates
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mxn = 2e5 + 10;
const long long inf = 1e18;
long long arr[mxn];
long long seg[4 * mxn];
long long lazy[4 * mxn];

void push(int nd, int l, int r){

	// updates nd and pushes 
	// the lazy value to children if any
	seg[nd] += lazy[nd] * (r - l + 1);
	if(l != r){
		lazy[2 * nd] += lazy[nd];
		lazy[2 * nd + 1] += lazy[nd];
	}
	lazy[nd] = 0;
}

void build(int nd, int l, int r)
{
	if(l == r){
		seg[nd] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * nd, l, mid);
	build(2 * nd + 1, mid + 1, r);
	seg[nd] = seg[2 * nd] + seg[2 * nd + 1];
}

void range_update(int nd, int l, int r, int ql, int qr, int val)
{
	// make the node clean
	if(lazy[nd])
		push(nd, l, r);
	
	if(l > qr || r < ql)
		return;

	if(l >= ql && r <= qr){
		// set the lazy value
		lazy[nd] += val;
		// update node and push lazy to children
		push(nd, l, r);
		return;
	}
	int mid = (l + r) / 2;
	range_update(2 * nd, l, mid, ql, qr, val);
	range_update(2 * nd + 1, mid + 1, r, ql, qr, val);
	seg[nd] = seg[2 * nd] + seg[2 * nd + 1];
}

long long query(int nd, int l, int r, int ql, int qr)
{
	if(lazy[nd])
		push(nd, l, r);

	if(l > qr || r < ql)
		return 0;
	if(l >= ql && r <= qr){
		// the node is upto date for sure
		return seg[nd];
	}

	int mid = (l + r) / 2;
	long long lft = query(2 * nd, l, mid, ql, qr);
	long long rit = query(2 * nd + 1, mid + 1, r, ql, qr);
	return lft + rit;
}

int main()
{
	int n, q;
	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	build(1, 1, n);	
	for(int qi = 1; qi <= q; ++qi){
		int typ, a, b, u;
		cin >> typ;
		if(typ == 1){
			cin >> a >> b >> u;
			range_update(1, 1, n, a, b, u);
		}
		else{
			cin >> a;
			long long ans = query(1, 1, n, a, a);
			cout << ans << '\n';
		}
	}
	return 0;
}
