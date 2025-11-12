// exp1_stack_template.cpp
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
    vector<T> data;
    size_t capacity;
public:
    Stack(size_t cap=100): capacity(cap) { data.reserve(cap); }
    bool isEmpty() const { return data.empty(); }
    bool isFull() const { return data.size() >= capacity; }
    bool push(const T &x) {
        if (isFull()) return false;
        data.push_back(x);
        return true;
    }
    bool pop() {
        if (isEmpty()) return false;
        data.pop_back();
        return true;
    }
    // returns optional-like behavior
    optional<T> top() const {
        if (isEmpty()) return nullopt;
        return data.back();
    }
    size_t size() const { return data.size(); }
};

int main(){
    Stack<int> st(5);
    cout << "push 10,20,30\n";
    st.push(10); st.push(20); st.push(30);
    if (!st.isEmpty()) cout << "Top: " << *st.top() << "\n";
    cout << "pop\n"; st.pop();
    if (!st.isEmpty()) cout << "Top: " << *st.top() << "\n";
    cout << "isFull? " << st.isFull() << " size=" << st.size() << "\n";
}
