class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> lookup{};

        for (int index = 0; index < nums.size(); ++index) {
            if (lookup.contains(nums[index])) {
                return {lookup[nums[index]], index};
            } else {
                lookup[target - nums[index]] = index;
            }
        }
        return {-1, -1};
    }
};
