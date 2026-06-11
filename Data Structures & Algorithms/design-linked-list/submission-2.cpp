class MyLinkedList {
    struct Node {
        int val{};
        Node* next{};
    };
    Node* list{};

   public:
    MyLinkedList() {}

    int get(int index) {
        int i = 0;
        auto* current = list;
        if (!current) return -1;

        while (current && i < index) {
            current = current->next;
            i++;
        }
        if (!current) return -1;
        return current->val;
    }

    void addAtHead(int val) {
        auto* node = new Node{val, nullptr};
        node->next = list;
        list = node;
    }

    void addAtTail(int val) {
        auto* current = list;
        if (!current) {
            addAtHead(val);
            return;
        }
        auto* node = new Node{val, nullptr};
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }

    void addAtIndex(int index, int val) {
        auto* current = list;
        if (!current) {
            if (index == 0) addAtHead(val);
            return;
        }
        auto* node = new Node{val, nullptr};
        int i = 0;
        Node* prev = nullptr;
        while (current && i < index) {
            prev = current;
            current = current->next;
            i++;
        }

        if (prev->next) {
            auto* nextNode = prev->next;
            prev->next = node;
            node->next = nextNode;
        } else {
            if (i == index)
                prev->next = node;
            else
                delete node;
        }
    }

    void deleteAtIndex(int index) {
        int i = 0;
        auto* current = list;
        if (!current) return;
        Node* prev = nullptr;
        while (current && i < index) {
            prev = current;
            current = current->next;
            i++;
        }
        if (!prev) {
            list = current->next;
            delete current;
            return;
        }
        if (current) {
            prev->next = current->next;
            delete current;
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */