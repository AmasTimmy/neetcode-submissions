class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        if (val > 50) return 0;
        int end = nums.size() - 1;
        int start = 0;
        while(start <= end) {
            if (nums[end] == val) {
                end--;
                continue;
            }
            if (nums[start] != val) {
                start++;
                continue;
            }
            std::swap(nums[start], nums[end]);
        }
        return start;
    }
};