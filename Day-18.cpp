// Job Sequencing Problem
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution 
{
    public:
    bool static comp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int count =0, profit=0;
        sort(arr, arr+n, comp);
        int maxi =arr[0].dead;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i].dead);
        }
        int slot[maxi+1];
        for(int i=0;i<=maxi;i++) slot[i]=-1;
        
        int countJobs=0, jobProfit=0;
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j]==-1){
                    slot[j]=i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countJobs, jobProfit};
    } 
};
