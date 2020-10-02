#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ncr[65][65];
void preCalc()
{
	for(int n = 0; n <= 30; ++n){
		for(int r = 0; r <= n; ++r){
			if(r == 0){
				ncr[n][r] = 1;
				continue;
			}
			ncr[n][r] = ncr[n - 1][r] + ncr[n - 1][r - 1];
		}
	}
}




int main()
{
	preCalc();
	return 0;
}
