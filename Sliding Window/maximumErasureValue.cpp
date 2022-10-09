class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0,ans=0;
        int start = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            auto it = mp.find(nums[i]);
            if(it!=mp.end() and it->second!=-1){
                int idx = mp[nums[i]];
                while(start<idx+1){
                    sum-=nums[start];
                    mp[nums[start]]=-1;
                    start++;
                }
                start = idx+1;  
            }
            mp[nums[i]] = i;
            ans = max(ans,sum);
        }
        return ans;
    }
};

