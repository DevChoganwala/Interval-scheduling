// Given a set of jobs with their starting and ending times, find the maximum size of the subset, such that jobs in the subset do not overlap. 
// nlogn

#include<bits/stdc++.h>

using namespace std;

bool cmp( vector<int> &a , vector<int> &b )
{
	return a[1] < b[1];
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>>a;

	for( int i=0 ; i<n ; i++)
	{
		int x , y;
		cin >> x >> y;
		a.push_back({x,y});
	}

	sort( a.begin() , a.end() , cmp );

	int dp[n];

	memset( dp , 0 , sizeof(dp) );

	for( int i=0 ; i<n ; i++)
	{
		int mx = 0;

		int l = 0 , r = i-1 , mid , idx = -1;

		while(l<=r)
		{
			mid = (l+r)/2;
			if(a[mid][1]<a[i][0])
			{
				idx = mid;
				l = mid+1;
			}
			else
				r = mid-1;
		}

		if(idx!=-1)
			mx = dp[idx];

		dp[i] = max( (i!=0) ? dp[i-1] : 0 , mx+1 );
	}

	cout << dp[n-1] << endl;
}