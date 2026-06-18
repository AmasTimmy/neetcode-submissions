class KthLargest {
  std::priority_queue<int> m_maxHeap{};
  int m_kth{};

 public:
  KthLargest(int k, vector<int>& nums) : m_kth(k) {
    for (auto element : nums) {
      m_maxHeap.push(element);
    }
  }

  int add(int val) {
    m_maxHeap.push(val);
    std::vector<int> elements;
    elements.reserve(m_kth);
    for (int index = 0; index < m_kth; index++) {
      elements.push_back(m_maxHeap.top());
      m_maxHeap.pop();
    }
    for (int index = 0; index < m_kth; index++) {
      m_maxHeap.push(elements[index]);
    }
    return elements[elements.size() - 1];
  }
};
