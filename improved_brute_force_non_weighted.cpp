#include<bits/stdc++.h>

using namespace std;

// check that given subset of jobs is non_overlapping or onot
bool is_non_overlapping(vector<vector<int>> &choosen){
	for(int i=1; i<choosen.size(); i++)
		if(choosen[i][0] <= choosen[i-1][1])
			return false;
	return true;
}

int main(){
	int n; 

	// take the number of jobs as input
	cin >> n;

	vector<vector<int>> intervals(n, vector<int>(2,0));

	// take the job start and end time
	for(int i=0; i<n; i++)
		cin >> intervals[i][0] >> intervals[i][1]; 
	
	// sort the intervals by the end time
	sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2){
		return v1[1] < v2[1] || v1[1] == v2[1] && v1[0] < v2[0];
	});
        
    // variable to store the size of largest non-ovelapping subset
	int max_non_overlap = 0;
    
    // generate the all subset 
    // E.g. is mask = 10011 and n = 5, then the current subset includes 1,2 and 5th job.   
	for(int mask=0; mask<(1<<n); mask++){

		// now, store the job in the subset
		vector<vector<int>> choosen;
		for(int j=0; j<n; j++)
			if((mask & (1<<j))	!= 0)
				choosen.push_back(intervals[j]);
        
        // if choosen subset of jobs is non overlapping
        if(is_non_overlapping(choosen)){

        	// if current choosen subset is larger than previously choosen subset, update the max non overlap subset size
        	if(max_non_overlap < __builtin_popcount(mask))
				max_non_overlap = __builtin_popcount(mask);
        }
	}

	// print the size of largest non-overlapping subset
	cout << max_non_overlap;
    
}