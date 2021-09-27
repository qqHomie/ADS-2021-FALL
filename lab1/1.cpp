#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node *top;
    int size1;

    Stack(){
        top = NULL;
        size1 = 0;
    }

    void push(int data){
        Node *node = new Node(data);
        size1++;
        node->next = top;
        top = node;
    }

    void pop(){
        if (top != NULL){
            top = top->next;
            size1--;
        }
    }

    int size(){
        return this->size1;
    }

    void clear(){
        this->size1 = 0;
    }

    int back(){
        return top->data;
    }
};

int main(){

    Stack *stc = new Stack();

    while(1){
        string s;
        cin >> s;
        if (s == "push"){
            int n;
            cin >> n;
            stc->push(n);
            cout << "ok" << endl;
        }
        else if (s == "pop"){
            if (stc->size1 == 0){
                cout << "error" << endl;
            }
            else{
                cout << stc->top->data << endl;
                stc->pop();
            }
        }
        else if (s == "back"){
            if (stc->size1 == 0){
                cout << "error" << endl;
            }
            else {
                cout << stc->back() << endl;
            }
        }
        else if (s == "size"){
            cout << stc->size() << endl;;
        }
        else if (s == "clear"){
            Stack *stc1 = new Stack();
            swap(stc, stc1);
            cout << "ok" << endl;
        }
        else if (s == "exit"){
            cout << "bye" << endl;
            return 0;
        }
    }

    return 0;
}