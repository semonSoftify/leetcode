class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<std::vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return result;
    }
};