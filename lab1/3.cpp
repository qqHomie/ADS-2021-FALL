#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Deque {
    public:
    Node *front;
    Node *back;
    int sz;

    Deque(){
        front = NULL;
        back = NULL;
        sz = 0;
    }

    void push_front(int data){
        Node *node = new Node(data);
        if (sz == 0){
            front = back = node;
        }
        else {
            node->next = front;
            front->prev = node;
            front = front->prev;
        }
        sz++;
    }

    void push_back(int data){
        Node *node = new Node(data);
        if (sz == 0){
            back = front = node;
        }
        else{
            node->prev = back;
            back->next = node;
            back = back->next;
        }
        sz++;
    }

    void pop_front(){
        if (front == NULL){
            back = NULL;
        }
        else{
            front = front->next;
        }
        sz--;
    }

    void pop_back(){
        if (back == NULL){
            front = NULL;
        }
        else{
            back = back->prev;
        }
        sz--;
    }

    int sz1(){
        return this->sz;
    }
};

int main(){

    Deque *dq = new Deque();
    while(1){
        string s;
        cin >> s;
        if (s == "clear"){
            Deque *dq1 = new Deque();
            swap(dq, dq1);
            cout << "ok" << endl;
        }
        else if (s == "exit"){
            cout << "bye" << endl;
            return 0;
        }
        else if (s == "size"){
            cout << dq->sz1() << endl;
        }
        else if (s == "push_front"){
            int n;
            cin >> n;
            dq->push_front(n);
            cout << "ok" << endl;
        }
        else if (s == "push_back"){
            int n;
            cin >> n;
            dq->push_back(n);
            cout << "ok" << endl;
        }
        else if (s == "pop_front"){
            if (dq->sz == 0){
                cout << "error" << endl;
            } 
            else{
                cout << dq->front->data << endl;
                dq->pop_front();
            }
        }
        else if (s == "pop_back"){
            if (dq->sz == 0){
                cout << "error" << endl;
            }
            else{
                cout << dq->back->data << endl;
                dq->pop_back();
            }
        }
        else if (s == "front"){
            if (dq->sz == 0){
                cout << "error" << endl;
            }
            else{
                cout << dq->front->data << endl;
            }
        }
        else if (s == "back"){
            if (dq->sz == 0){
                cout << "error" << endl;
            }
            else{
                cout << dq->back->data << endl;
            }
        }
    }

    return 0;
}