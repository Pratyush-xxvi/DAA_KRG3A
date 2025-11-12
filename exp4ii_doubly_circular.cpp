// exp4_doubly_circular.cpp
#include <bits/stdc++.h>
using namespace std;

// Doubly linked list
template<typename T>
struct DNode{ T val; DNode *prev,*next; DNode(T v):val(v),prev(nullptr),next(nullptr){} };

template<typename T>
class DoublyLinkedList {
    DNode<T>* head; DNode<T>* tail;
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList(){ while(head){ auto t=head; head=head->next; delete t; } }

    void insertBeginning(T v){
        auto n = new DNode<T>(v);
        n->next = head;
        if(head) head->prev = n;
        head = n;
        if(!tail) tail = head;
    }
    void insertEnd(T v){
        auto n = new DNode<T>(v);
        n->prev = tail;
        if(tail) tail->next = n;
        tail = n;
        if(!head) head = tail;
    }
    bool deleteBeginning(){
        if(!head) return false;
        auto t = head; head = head->next;
        if(head) head->prev = nullptr; else tail = nullptr;
        delete t; return true;
    }
    bool deleteEnd(){
        if(!tail) return false;
        auto t = tail; tail = tail->prev;
        if(tail) tail->next = nullptr; else head = nullptr;
        delete t; return true;
    }
    void print(){ for(auto p=head;p;p=p->next) cout<<p->val<<" "; cout<<"\n"; }
};

// Circular singly linked list
template<typename T>
struct CNode{ T val; CNode *next; CNode(T v):val(v),next(nullptr){} };

template<typename T>
class CircularLinkedList {
    CNode<T>* tail; // tail->next is head
public:
    CircularLinkedList(): tail(nullptr) {}
    ~CircularLinkedList(){ if(!tail) return; CNode<T>* h=tail->next; tail->next=nullptr; while(h){ auto t=h; h=h->next; delete t; } }

    void insertBeginning(T v){
        auto n = new CNode<T>(v);
        if(!tail){ tail = n; tail->next = tail; return; }
        n->next = tail->next;
        tail->next = n;
    }
    void insertEnd(T v){
        insertBeginning(v);
        tail = tail->next; // new node becomes tail
    }
    bool deleteBeginning(){
        if(!tail) return false;
        CNode<T>* head = tail->next;
        if(head == tail){ delete head; tail = nullptr; return true; }
        tail->next = head->next;
        delete head; return true;
    }
    bool deleteEnd(){
        if(!tail) return false;
        if(tail->next == tail){ delete tail; tail=nullptr; return true; }
        CNode<T>* cur = tail->next;
        while(cur->next != tail) cur = cur->next;
        cur->next = tail->next;
        delete tail;
        tail = cur;
        return true;
    }
    void print(){
        if(!tail){ cout << "\n"; return; }
        CNode<T>* p = tail->next;
        do { cout << p->val << " "; p = p->next; } while(p != tail->next);
        cout << "\n";
    }
};

int main(){
    DoublyLinkedList<int> dl;
    dl.insertEnd(1); dl.insertBeginning(0); dl.print();
    dl.deleteEnd(); dl.print();

    CircularLinkedList<int> cl;
    cl.insertEnd(5); cl.insertBeginning(4); cl.print();
    cl.deleteBeginning(); cl.print();
}
