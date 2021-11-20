// Given a set of jobs with theirs starting, ending times, and their weights, find the subset of non-overlapping intervals having maximum total weight.
// nlogn 

#include<bits/stdc++.h>

using namespace std;

bool cmp( vector<long long> &a , vector<long long> &b )
{
	return a[1] < b[1];
}

int main()
{
	long long n;
	cin >> n;

	vector<vector<long long>>a;

	for( long long i=0 ; i<n ; i++)
	{
		long long x , y , w;
		cin >> x >> y >> w;
		a.push_back({x,y,w});
	}

	sort( a.begin() , a.end() , cmp );

	long long dp[n];

	memset( dp , 0 , sizeof(dp) );

	for( long long i=0 ; i<n ; i++)
	{
		long long mx = 0;

		long long l = 0 , r = i-1 , mid , idx = -1;

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

		dp[i] = max( (i!=0) ? dp[i-1] : 0 , mx+a[i][2] );
	}

	cout << dp[n-1] << endl;
}