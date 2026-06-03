class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> distincts{};

        for (auto element : nums) {
            if (distincts.contains(element)) return true;
            distincts.insert(element);
        }
        return false;
    }
};