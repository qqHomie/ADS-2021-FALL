#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node (int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    public:
    Node *front;
    Node *back;
    int sz;

    Queue(){
        front = NULL;
        back = NULL;
        sz = 0;
    }

    void push(int data){
        Node *node = new Node(data);
        if (sz == 0){
            front = back = node;
        }
        else {
            back->next = node;
            back = node;
        }
        sz++;
    }

    void pop(){
        front = front->next;
        sz--;
    }

    int size(){
        return this->sz;
    }
};

int main(){

    Queue *qu = new Queue();
    while (1){
        string s;
        cin >> s;
        if (s == "size"){
            cout << qu->sz << endl;
        }
        else if (s == "pop"){
            if (qu->sz == 0){
                cout << "error" << endl;
            }
            else {
                cout << qu->front->data << endl;
                qu->pop();
            }
        }
        else if (s == "front"){
            if (qu->sz == 0){
                cout << "error" << endl;
            }
            else {
                cout << qu->front->data << endl;
            }
        }
        else if (s == "exit"){
            cout << "bye" << endl;
            return 0;
        }
        else if (s == "clear"){
            Queue *qu1 = new Queue();
            swap(qu, qu1);
            // st->clear();
            cout << "ok" << endl;
        }
        else if (s == "push"){
            int n;
            cin >> n;
            qu->push(n);
            cout << "ok" << endl;
        }
    }

    return 0;
}