// Red-Black Tree
// class RBTree, implementation
#include <assert.h>
#include "RBTree.h"

// Find a key in a subtree
// In: key  -- a key to find;
//     root -- a root of a subtree. If root == 0,
//             then find in complete tree
// Out: node -- a pointer to the node that contains a key,
//                  if key is in the set,
//              or a pointer to a node that should be parent to
//                  a node with this key in case of insertion
// Return value: true, if the subtree contains the key.
int RBTree::find(
    const TreeNodeValue* key,
    const Node* subTreeRoot,
    RBTreeNodePtr* node
) const {
    //Node* node;
    const Node* x;        // current node
    const Node* y;        // its parent
    if (subTreeRoot == 0) {
        x = root();
        y = &header;
    } else {
        x = subTreeRoot;
        y = x->parent;
    }
    int n = (-1); // If tree is empty, add the new node as a left son of header
    while (x != 0) {
        const TreeNodeValue* currentKey = x->value;
        n = key->compareTo(*currentKey);
        y = x;
        if (n == 0) {
            // key is found
            if (node != 0)
                *node = const_cast<Node*>(x);
            return 0;
        } else if (n < 0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // key is not in the tree
    if (node != 0)
        *node = const_cast<Node*>(y);
    return n;
}



/*int RBTree::find(
    const TreeNodeValue* key,
    RBTreeNodePtr* node
)
{
    Node* v, vp;
    TreeNodeValue* y;
    int res = -1;
    v = node.root;
    vp = node.root;
    while (v != 0){
        y = v->value;       // y = значение в вершине v
        if (x == y){         // x равно значению в вершине =>
            *node = v;      //   запомним указатель на вершину
            return 0;       //   успешное завершение
        } else if (x < y){    // x меньше значения в вершине =>
            vp = v;         //   запомним указатель на отца
            res = -1;       //   запомним результат сравнения
            v = v->left;    //   переходим к левому сыну
        } else{             // иначе     // x > y
            vp = v;         //   запомним указатель на отца
            res = 1;        //   запомним результат сравнения
            v = v->right;   //   переходим к правому сынy
        }
    }
                            // x не содержится в дереве
    *node = &vp;             // *node = указатель на отца
    return res;
}*/
//bool RBTree::contains() ;


// Insert a key into the tree:
//     create a new node and insert it as a leaf.
// The color of a new node is red.
// Should be called after the "find" method, when element was not found.
void RBTree::insert(
    Node* parentNode,
    TreeNodeValue* key,
    int compare
) {
    assert(parentNode != 0 && compare != 0);
    Node* x = new Node();
    x->value = key;
    x->parent = parentNode;
    if (parentNode == &header)
        x->red = false;     // The root of tree is black
    else
        x->red = true;      // Paint the new node in red
    if (compare < 0) {
        // Insert as a left son
        assert(parentNode->left == 0);
        parentNode->left = x;
    } else {
        // Insert as a right son
        assert(parentNode != &header && parentNode->right == 0);
        parentNode->right = x;
    }
    ++numNodes;

    if (x != root())
        rebalanceAfterInsert(x);
}

// Rotate a node x to the left    //
//        x                y      //
//       / \              / \     //
//      a   y    --->    x   c    //
//         / \          / \       //
//        b   c        a   b      //
void RBTree::rotateLeft(Node* x) {
    Node* y = x->right;
    assert(y != 0);
    Node* p = x->parent;
    y->parent = p;
    if (x == p->left) {
        // x is the left son of its parent
        p->left = y;
    } else {
        // x is the right son of its parent
        p->right = y;
    }
    x->right = y->left;
    if (y->left != 0)
        y->left->parent = x;
    y->left = x;
    x->parent = y;
}

// Rotate a node x to the right   //
//        x                y      //
//       / \              / \     //
//      y   c    --->    a   x    //
//     / \                  / \   //
//    a   b                b   c  //
void RBTree::rotateRight(Node* x) {
    Node* y = x->left;
    assert(y != 0);
    Node* p = x->parent;
    y->parent = p;
    if (x == p->left) {
        // x is the left son of its parent
        p->left = y;
    } else {
        // x is the right son of its parent
        p->right = y;
    }
    x->left = y->right;
    if (y->right != 0)
        y->right->parent = x;
    y->right = x;
    x->parent = y;
}

void RBTree::rebalanceAfterInsert(Node* x) {
    assert(x->red);
    while(x != root() && x->parent->red) {
        if (x->parent == x->parent->parent->left) {
            // parent of x is a left son

            Node* y = x->parent->parent->right; // y is the sibling of
                                             //            parent of x
            if (y != 0 && y->red) {          // if y is red
                x->parent->red = false;      //     color parent of x in black
                y->red = false;              //     color y in black
                x = x->parent->parent;       //     x = grandparent of x
                x->red = true;               //     color x in red
            } else {                         // else y is black
                if (x == x->parent->right) { //     if x is a right son
                    x = x->parent;           //         x = parent of x
                    rotateLeft(x);           //         left-rotate x
                }                            //     end if
                assert(x == x->parent->left);//     assert: x is a left son
                x->parent->red = false;      //     color parent of x in black
                x->parent->parent->red = true;  // color grandparent in red
                rotateRight(x->parent->parent); // right-rotate grandparent
            }                                // endif
        } else {
            // Mirror case: parent of x is a right son
            assert(x->parent == x->parent->parent->right);

            Node* y = x->parent->parent->left; // y is the sibling of
                                             //           parent of x
            if (y != 0 && y->red) {          // if y is red
                x->parent->red = false;      //     color parent of x in black
                y->red = false;              //     color y in black
                x = x->parent->parent;       //     x = grandparent of x
                x->red = true;               //     color x in red
            } else {                         // else y is black
                if (x == x->parent->left) {  //     if x is a left son
                    x = x->parent;           //         x = parent of x
                    rotateRight(x);          //         right-rotate x
                }                            //     end if
                assert(x == x->parent->right); //   assert: x is a right son
                x->parent->red = false;      //     color parent of x in black
                x->parent->parent->red = true; //  color grandparent in red
                rotateLeft(x->parent->parent); //  left-rotate grandparent
            }                                // endif
        }
    } // end while

    // Always color the root in black
    if (x == root()) {
        x->red = false;
    }
}

void RBTree::eraseNode(Node* node) {
    delete node->value;
}

void RBTree::clear() {
    removeSubtree(root());
}

int RBTree::removeSubtree(Node* subTreeRoot) {
    int numRemoved = 0;
    if (subTreeRoot == 0)
        return 0;
    if (subTreeRoot->left != 0)
        numRemoved += removeSubtree(subTreeRoot->left); // recursive call
    if (subTreeRoot->right != 0)
        numRemoved += removeSubtree(subTreeRoot->right); // recursive call

    if (subTreeRoot->parent->left == subTreeRoot)
        subTreeRoot->parent->left = 0;
    else
        subTreeRoot->parent->right = 0;

    eraseNode(subTreeRoot);
    delete subTreeRoot;
    ++numRemoved;
    --numNodes;

    assert(numNodes >= 0);

    return numRemoved;
}

