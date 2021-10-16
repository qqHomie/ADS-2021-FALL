#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
int cnt = 0;

struct Node{
    int data;
    Node *left, *right;
    Node (int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

struct BST{
    Node *root;
    BST(){
        root = nullptr;
    }
    Node *insert(Node *root, int data){
        if (root == nullptr){
            return new Node(data);
        }
        if (root->data > data){
            root->left = insert(root->left, data);
        }
        else if (root->data < data){
            root->right = insert(root->right, data);
        }
        return root;
    }

    void insert(int data){
        root = insert(root, data);
    }

    Node *right_most(Node *root){
        while (root->right != nullptr){
            root = root->right;
        }
        return root;
    }

    Node *del(Node *root, int to_delete){
        if (root->data > to_delete){
            root->left = del(root->left, to_delete);
        } else if (root->data < to_delete){
            root->right = del(root->right, to_delete);
        } else {
            if (root->left == nullptr and root->right == nullptr){
                return nullptr;
            } else if (root->left == nullptr){
                Node *right = root->right;
                delete(root);
                return right;
            } else if (root->right == nullptr) {
                Node *left = root->left;
                delete(root);
                return left;
            } else {
                Node *new_root = right_most(root->left);
                root->data = new_root->data;
                root->left = del(root->left, new_root->data);
                return root;
            }
        }
        return root;
    }

    int depth(Node *root){
        if (root == nullptr){
            return 0;
        }
        int d_left = depth(root->left);
        int d_right = depth(root->right);
        return max(d_left, d_right) + 1;
    }
    
    int depth() {
        return depth(root);
    }

    bool is_balanced(Node *root){
        if (root == nullptr) {
            return true;
        }
        bool is_left_balanced = is_balanced(root->left);
        bool is_right_balanced = is_balanced(root->right);
        bool is_root_balanced = (abs(depth(root->left) - depth(root->right)) <= 1);
        return is_left_balanced && is_right_balanced && is_root_balanced;
    }

    bool is_balanced(){
        return is_balanced(root);
    }

    void del(int to_delete){
        root = del(root, to_delete);
    }

    void inorder(Node* root){
        if (root == nullptr){
            return;
        }
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }

    void inorder() {
        inorder(root);
    }

    int cntnodes(Node *root){
        if (root != nullptr){
            cntnodes(root->left);
            cnt++;
            cntnodes(root->right);
        }
        return cnt;
    }

    void no_child(Node *root){
        if (root == nullptr){
            return;
        }
        no_child(root->left);
        if (root->left == nullptr && root->right == nullptr){
            cout << root->data << endl;
        }
        no_child(root->right);
    }

    void two_child(Node *root){
        if (root == nullptr){
            return;
        }
        two_child(root->left);
        if (root->left != nullptr && root->right != nullptr){
            cout << root->data << endl;
        }
        two_child(root->right);
    }
    void one_child(Node *root){
        if (root == nullptr){
            return;
        }
        one_child(root->left);
        if ((root->left == nullptr and root->right != nullptr) or (root->left != nullptr and root->right == nullptr)){
            cout << root->data << endl;
        }
        one_child(root->right);
    }
};

int main(){

    BST bst = BST();
    int x;
    while(1){
        cin >> x;
        if (x!=0){
            bst.insert(x);
        }else{
            break;
        }
    }

    if (bst.is_balanced()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}
