class BrowserHistory {
  struct Node {
    string m_url;
    Node* m_next{};
    Node* m_prev{};
  };

  Node* m_history{};
  Node* m_currentPage{};

 public:
  BrowserHistory(string homepage) {
    m_history = new Node{homepage, nullptr, nullptr};
    m_currentPage = m_history;
  }

  void visit(string url) {
    if (!m_currentPage) return;
    auto* nextHistory = m_currentPage->m_next;
    m_currentPage->m_next = new Node{url, nullptr, m_currentPage};
    m_currentPage = m_currentPage->m_next;

    while (nextHistory) {
      auto* next = nextHistory->m_next;
      delete nextHistory;
      nextHistory = next;
    }
  }

  string back(int steps) {
    for (int index = 0; index < steps; ++index) {
      if (m_currentPage)
        m_currentPage = m_currentPage->m_prev;
      else
        break;
    }
    if (!m_currentPage) {
      m_currentPage = m_history;
    }
    return m_currentPage->m_url;
  }

  string forward(int steps) {
    for (int index = 0; index < steps; ++index) {
      if (m_currentPage) {
        if (m_currentPage->m_next)
          m_currentPage = m_currentPage->m_next;
        else
          break;
      }
    }

    return m_currentPage->m_url;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */