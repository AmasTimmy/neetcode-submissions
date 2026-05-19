class MinStack {
    struct Node {
        int m_element;
        int m_minInRemaining;
    };
    std::stack<Node> m_stack{};

   public:
    MinStack() = default;

    void push(int val) {
        if (m_stack.empty()) {
            m_stack.push({val, val});
        } else {
            auto lastMinElement = m_stack.top().m_minInRemaining;
            m_stack.push({val, min(val, lastMinElement)});
        }
    }

    void pop() { m_stack.pop(); }

    int top() { return m_stack.top().m_element; }

    int getMin() { return m_stack.top().m_minInRemaining; }
};
