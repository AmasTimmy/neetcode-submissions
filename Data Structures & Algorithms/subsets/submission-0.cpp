class Solution {
    void dfs(vector<int> const& nums, vector<int> result, int starting,
             vector<vector<int>>& subsets) {
        subsets.push_back(result);
        if (starting == nums.size()) return;

        for (int index = starting; index < nums.size(); index++) {
            result.push_back(nums[index]);
            dfs(nums, result, index + 1, subsets);
            result.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets{};
        dfs(nums, {}, 0, subsets);
        return subsets;
    }
};
