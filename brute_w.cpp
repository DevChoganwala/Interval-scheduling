// Given a set of jobs with their starting and ending times, find the maximum size of the subset, such that jobs in the subset do not overlap. 
// O(n!)

#include<bits/stdc++.h>
#include <chrono>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<vector<int> >a;

	for( int i=0 ; i<n ; i++)
	{
		int x , y , w;
		cin >> x >> y >> w;
		vector<int> curr;
		curr.push_back(x);
		curr.push_back(y);
		curr.push_back(w);
		a.push_back(curr);
	}
	auto start = high_resolution_clock::now();
	vector<int>pr;
	for( int i=0 ; i<n ; i++)
	{
		pr.push_back(i);
	}

	int fact = 1;
	for( int i=1 ; i<=n ; i++)
	{
		fact = fact*i;
	}

	int ans = 0;

	for( int i=1 ; i<=fact+1 ; i++)
	{
		vector<vector<int>>b;

		for( int j=0 ; j<n ; j++)
		{
			b.push_back(a[pr[j]]);
		}

		int mx = 0 , count = b[0][2] , prev = b[0][1];

		for( int j=1 ; j<n ; j++)
		{
			if(b[j][0]>prev)
				count += b[j][2];
			else
			{
				mx = max( mx , count );
				count = b[j][2];
			}
			prev = b[j][1];
		}

		ans = max( ans , mx );

		next_permutation( pr.begin() , pr.end() );
	}

	cout << ans << "\n";
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout<<duration.count()<<endl;
}