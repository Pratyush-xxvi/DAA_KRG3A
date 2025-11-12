// exp4_singly.cpp
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    T val; Node *next;
    Node(T v): val(v), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList {
    Node<T>* head;
    Node<T>* tail;
public:
    SinglyLinkedList(): head(nullptr), tail(nullptr) {}
    ~SinglyLinkedList(){ while (head) { auto t = head; head = head->next; delete t; } }

    void insertBeginning(T v) {
        Node<T>* n = new Node<T>(v);
        n->next = head;
        head = n;
        if (!tail) tail = head;
    }
    void insertEnd(T v) {
        Node<T>* n = new Node<T>(v);
        if (!tail) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    bool deleteBeginning() {
        if (!head) return false;
        Node<T>* t = head; head = head->next;
        if (!head) tail = nullptr;
        delete t; return true;
    }
    bool deleteEnd() {
        if (!head) return false;
        if (head == tail) { delete head; head = tail = nullptr; return true; }
        Node<T>* cur = head;
        while (cur->next != tail) cur = cur->next;
        delete tail;
        tail = cur;
        tail->next = nullptr;
        return true;
    }
    void print() const {
        for(Node<T>* p=head; p; p=p->next) cout << p->val << " ";
        cout << "\n";
    }
};

int main(){
    SinglyLinkedList<int> l;
    l.insertEnd(1); l.insertEnd(2); l.insertBeginning(0);
    l.print(); // 0 1 2
    l.deleteBeginning();
    l.print(); // 1 2
    l.deleteEnd();
    l.print(); // 1
}
