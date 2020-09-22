#include <iostream>
#include <vector>
using namespace std;

int numSubmat(vector<vector<int>> &mat)
{

	int nr = mat.size();
	int nc = mat[0].size();

	vector<vector<int>> hgt(nr, vector<int>(nc, 0));
	
	// calculate heights
	for(int c = 0; c < nc; ++c){
		for(int r = 0; r < nr; ++r){
			if(r == 0){
				if(mat[r][c] == 1)
					hgt[r][c] = 1;
				continue;
			}

			if(mat[r][c] == 1)
				hgt[r][c] = hgt[r - 1][c] + 1;
		}
	}
	
	int ans = 0;
	for(int r = 0; r < nr; ++r){
		for(int c = 0; c < nc; ++c){
			if(mat[r][c] == 0)
				continue;
			int w = 0, mnh = 1e9;
			for(int cc = c; cc >= 0; --cc){
				if(mat[r][cc] == 0)
					break;
				++w;
				mnh = min(mnh, hgt[r][cc]);
				ans += w * mnh;
				// subtract sub rectangles counted for prev col
        ans -= mnh * (w - 1);
			}
		}
	}	
	return ans;
}

int main()
{
	vector<vector<int>> mat1 = {
		{1, 0, 1},
		{1, 1, 0},
		{1, 1, 0}
	};	
	cout << numSubmat(mat1) << endl;
	vector<vector<int>> mat2 = {
		{0, 1, 1, 0},
		{0, 1, 1, 1},
		{1, 1, 1, 0}
	};	
	cout << numSubmat(mat2) << endl;
	vector<vector<int>> mat3 = {
		{1, 1, 1, 1, 1, 1},
	};	
	cout << numSubmat(mat3) << endl;
	
	vector<vector<int>> mat4 = {
		{1, 0, 1},
		{0, 1, 0},
		{1, 0, 1}
	};	
	cout << numSubmat(mat4) << endl;
	return 0;
}
