class Solution{
public:
vector<int>dp;

int solve(int idx,vector<int>&arr,int d){
if(dp[idx]!=-1)
return dp[idx];

int n=arr.size();
int maxJumps=1;

for(int i=idx-1;i>=max(0,idx-d);i--){
if(arr[i]>=arr[idx])
break;

maxJumps=max(maxJumps,1+solve(i,arr,d));
}

for(int i=idx+1;i<=min(n-1,idx+d);i++){
if(arr[i]>=arr[idx])
break;

maxJumps=max(maxJumps,1+solve(i,arr,d));
}

return dp[idx]=maxJumps;
}

int maxJumps(vector<int>&arr,int d){
int n=arr.size();

dp.resize(n,-1);

int answer=1;

for(int i=0;i<n;i++){
answer=max(answer,solve(i,arr,d));
}

return answer;
}
};