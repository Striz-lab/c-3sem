#include <iostream>
#include <queue>

using namespace std;
    
struct node {
    int data;
    int count;
    node *left;
    node *right;
};
    
node* newNode(int data) {
  node* element = new node;
  element->data = data;
  element->count = 1;
  element->left = NULL;
  element->right = NULL;
  return element;
}
 
node* insert(node* element, int key) {
    if (element == NULL)
        return newNode(key);
    if (key < element->data)
        element->left = insert(element->left, key);
    else if (key > element->data)
        element->right = insert(element->right, key);
    else {
        element->count++;
    }
    return element;
}
 
int HeightBTree(node* Tree) {
    int x = 0, y = 0;
    if (Tree == NULL){
        cout << 100;
        exit(0);
    }
    if(Tree->left)
        x = HeightBTree(Tree->left);
    if (Tree->right)
        y = HeightBTree(Tree->right);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
 
int main() {
    
    int n, k = 0;
      node* root = NULL;
      while(cin){
          k++;
          cin >> n;
          if (n == 0)
              break;
          if (k == 1)
              root = insert(root, n);
          else
              insert(root, n);
    }

    cout << HeightBTree(root) << endl;
    return 0;
}

