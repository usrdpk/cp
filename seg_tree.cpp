#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mxn = 2e5 + 10;
long long arr[mxn];
long long seg[4 * mxn];

void build(int nd, int l, int r)
{
	if(l == r){
		seg[nd] = arr[l];
		return;
	}

	int mid = (l + r) / 2;
	int lft = 2 * nd;
	int rt = lft + 1;
	build(lft, l, mid);
	build(rt, mid + 1, r);

	seg[nd] = seg[lft] + seg[rt];
}

void point_update(int nd, int l, int r, int pos, int val)
{
	if(l == r && l == pos){
		seg[nd] = val;
		return;
	}
	
	int mid = (l + r) / 2;
	if(pos >= l && pos <= mid){
		point_update(2 * nd, l, mid, pos, val);
	}
	else if(pos > mid && pos <= r){
		point_update(2 * nd + 1, mid + 1, r, pos, val);
	}
	else{
		return;
	}
	seg[nd] = seg[2 * nd] + seg[2 * nd + 1];
}

long long query(int nd, int l, int r, int ql, int qr)
{
	if(r < ql || l > qr)
		return 0;
	if(l >= ql && r <= qr)
		return seg[nd];
	int mid = (l + r) / 2;
	long long lft = query(2 * nd, l, mid, ql, qr);
	long long rt = query(2 * nd + 1, mid + 1, r, ql, qr);
	return lft + rt;
}

int main()
{
	int n, q;
	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	build(1, 1, n);	
	for(int qi = 1; qi <= q; ++qi){
		int typ, a, b;
		cin >> typ >> a >> b;
		if(typ == 1){
			point_update(1, 1, n, a, b);
		}
		else{
			long long ans = query(1, 1, n, a, b);
			cout << ans << '\n';
		}
	}
	return 0;
}
