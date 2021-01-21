#include<iostream>
#include<queue>

struct node {
    int key_value;
    int self;
    int r_index;
    int l_index;
    node* left;
    node* right;
};


class btree{
public:
    node* root;
    btree() {
        root = NULL;
    }
    ~btree() {
        destroy_tree(root);
    }

    void insert(int key, int s, int l, int r){
        if(root!=NULL) {
            insert(key, s, l, r, root);
        }
        else {
            root=new node;
            root->key_value=key;
            root->self = s;
            root->l_index = l;
            root->r_index = r;
            root->left=NULL;
            root->right=NULL;
          }
    }

private:

    void insert(int key, int s, int l, int r, node* leaf) {
        if (key < leaf->key_value) {
            if (leaf->left != NULL) {
                insert(key, s,l,r, leaf->left);
            }
            else {
                leaf->left = new node;
                leaf->left->key_value = key;
                leaf->left->self = s;
                leaf->left->l_index = l;
                leaf->left->r_index = r;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        }
        else if (key >= leaf->key_value) {
            if (leaf->right != NULL) {
                insert(key, s, l, r, leaf->right);
            }
            else {
                leaf->right = new node;
                leaf->right->key_value = key;
                leaf->right->self = s;
                leaf->right->l_index = l;
                leaf->right->r_index = r;
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
        }
    }

    void destroy_tree(node *leaf) {
        if(leaf!=NULL)    {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }
};



int main() {
    int n;
    std::cin >> n;
    btree tree;
    int value, l, r;
    for (int i = 0; i < n; ++i) {
        std::cin >> value >> l >> r;
        tree.insert(value, i, l, r);
    }
    std::queue<node*> ans;
    ans.push(tree.root);
    while(!ans.empty()) {
        node* N = ans.front();
        if (N->left == NULL) {
            if (N->l_index != -1) {
                std::cout << "NO";
                return 0;
            }
        } else {
            if (N->l_index != N->left->self) {
                std::cout << "NO";
                return 0;
            }
        }
        if (N->right == NULL) {
            if (N->r_index != -1) {
                std::cout << "NO";
                return 0;
            }
        } else {
            if (N->r_index != N->right->self) {
                std::cout << "NO";
                return 0;
            }
        }
        if (N->left != NULL) ans.push(N->left);
        if (N->right != NULL) ans.push(N->right);
        ans.pop();
    }
    std::cout << "YES";
    return 0;
}

