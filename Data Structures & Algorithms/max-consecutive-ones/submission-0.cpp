class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int maxConsecutiveOnes = 0;
      int onesCount = 0;
      for (auto index = 0; index < nums.size(); ++index) {
         if (nums[index] == 0) {
            maxConsecutiveOnes = max(maxConsecutiveOnes, onesCount);
            onesCount = 0;
         } else {
            ++onesCount;
         }
      }

      return max(maxConsecutiveOnes, onesCount);

    }
};