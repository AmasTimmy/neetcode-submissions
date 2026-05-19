class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatestElement = -1;
        if (arr.size() == 1) return {greatestElement};

        for (int index = arr.size() - 1; index >= 0; index--) {
            auto currentElement = arr[index];
            arr[index] = greatestElement;
            greatestElement = max(currentElement, greatestElement);
        }
        return arr;
    }
};