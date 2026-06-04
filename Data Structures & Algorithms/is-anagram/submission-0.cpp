class Solution {
    static bool isOccurenceEmpty(std::array<int, 26> const& arr) {
        for (auto element : arr) {
            if (element != 0) return false;
        }
        return true;
    }

   public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> occurences{};

        for (auto ch : s) {
            occurences[ch - 'a']++;
        }

        for (auto ch : t) {
            occurences[ch - 'a']--;
        }

        return isOccurenceEmpty(occurences);
    }
};
