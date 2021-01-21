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
    else
        element->count++;
    return element;
}
  
void printAsLevelOrder(node* elem, int &n) {
    if (elem == NULL){
        for (int i = 0; i < 100; i++)
            cout << i << " ";
        exit(0);
    }
    queue<node*> q;
    q.push(elem);
    while (!q.empty()) {
        node* elem = q.front();
        cout << elem->data << " ";
        q.pop();
        if (elem->left != NULL)
            q.push(elem->left);
        if (elem->right != NULL)
            q.push(elem->right);
    }
}
  
int main() {
    
    int n, k = 0;
    //cout << n;
      node* root = NULL;
      while(cin >> n){
          k++;
          //cin >> n;
          if (n == 0)
              break;
          if (k == 1)
              root = insert(root, n);
          else
              insert(root, n);
    }

    printAsLevelOrder(root, n);
    
    cout << endl;
    return 0;
}
