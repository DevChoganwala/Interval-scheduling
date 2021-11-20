#include<bits/stdc++.h>

using namespace std;

// function to check whather given subset is non-ovelapping or not
bool is_non_ovelapping(vector<vector<int>> &choosen){
	for(int i=1; i<choosen.size(); i++)
		if(choosen[i][0] <= choosen[i-1][1])
			return false;
	return true;
}

int main(){
	
	int n; 

	// take the number of jobs as input
	cin >> n;
	vector<vector<int>> intervals(n, vector<int>(3,0));

	// take the job description
	// first one is start time
	// second one is end time
	// third one is weight of the job
	for(int i=0; i<n; i++)
		cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2]; 
	
	// sort the jobs based on end time
	sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2){
		return v1[1] < v2[1] || v1[1] == v2[1] && v1[0] < v2[0];
	});
        
    // variable which stores max profit
	long long max_profit = 0;
        
    // generate all subset
    // E.g. is mask = 10011, the subset includes 1,4 and 5th job.
	for(int mask=0; mask<(1<<n); mask++){

		// store the jobs
		vector<vector<int>> choosen;
		for(int j=0; j<n; j++)
			if((mask & (1<<j))	!= 0)
				choosen.push_back(intervals[j]);
        
        // check that choosend subset is non overlapping
        if(is_non_ovelapping(choosen)){

        	/// calculate the total weight
        	long long curr_profit = 0;
			for(int j=0; j<choosen.size(); j++)
				curr_profit += choosen[j][2];

			// update the max profit is current choosen subset has more total weight
			max_profit = max(max_profit, curr_profit);
        }
	}

	// print the max profit
	cout << max_profit;
    
}