//
// Red-Black (balanced) tree
//
#ifndef RBTREE_H
#define RBTREE_H

template <typename vT>
class TreeNodeValue;    // Predefinition


// A node in Red-Black tree
template <typename kT, typename vT>
class Node {
public:
    Node<kT, vT>* left;            // pointer to the left son
    Node<kT, vT>* right;           // pointer to the right son
    Node<kT, vT>* parent;          // pointer to the parent
    bool        red;       // the node is red (true) or black (false)
    TreeNodeValue<vT>* value;  // The value of tree node: normally, it is
                           //     a pair (key, value of key)
    Node<kT, vT>():
        left(0),
        right(0),
        parent(0),
        red(false),
        value(0)
    {
    }
};

template <typename kT, typename vT>
struct Registry{
    typedef Node<kT, vT>* RBTreeNodePtr; // Pointer to the RBTreeNode
};

// An ABSTRACT class representing values in tree nodes
template <class vT>
class TreeNodeValue{
public:
    TreeNodeValue() {}
    virtual ~TreeNodeValue() {}   // virtual destructor

    // Abstract class has virtual methods unimplemented

    // The values can be compared
    virtual vT compareTo(const TreeNodeValue&) const = 0;

    bool operator==(const TreeNodeValue& k) const {
        return (compareTo(k) == 0);
    }
    bool operator!=(const TreeNodeValue& k) const {
        return (compareTo(k) != 0);
    }
    bool operator<(const TreeNodeValue& k) const {
        return (compareTo(k) < 0);
    }
    bool operator<=(const TreeNodeValue& k) const {
        return (compareTo(k) <= 0);
    }
    bool operator>(const TreeNodeValue& k) const {
        return (compareTo(k) > 0);
    }
    bool operator>=(const TreeNodeValue& k) const {
        return (compareTo(k) >= 0);
    }
    
};

template <typename kT, typename vT>
class RBTree {
public:
    // Header contains a pointer to the root of the tree
    // as a left son.
    // The tree may be empty, in this case header->left == 0
    Node<kT, vT>  header;
    vT numNodes;

    RBTree():
        header(),
        numNodes(0)
    {
        header.red = true;      // The header has the red color!
    }

    void clear();
    void erase() { clear(); }
    void removeAll() { clear(); }

    ~RBTree() { clear(); }

    Node<kT, vT>* root() { return header.left; }
    const Node<kT, vT>* root() const { return header.left; }

    vT size() const { return numNodes; }

    // Find a key in a subtree
    // In: key         -- a key to find;
    //     subTreeRoot -- a root of a subtree. If subTreeRoot == 0,
    //                    then find in complete tree
    // Out: node       -- a pointer to the node that contains a key,
    //                    if key is in the set,
    //                    or a pointer to a node that should be parent to
    //                    the node with the key given.
    // Return value: 0,   if the key is found;
    //               < 0, if the key is not found, and the key is less
    //                       than the value in the node;
    //               > 0, if the key is not found, and the key is greater
    //                       than the value in the node.
    kT find(
        const TreeNodeValue<vT>* key,
        const Node<kT, vT>* subTreeRoot = 0,
        typename Registry<kT, vT>::RBTreeNodePtr *node = 0) const;
    
    bool contains(
    const TreeNodeValue<vT>* key,
    const Node<kT, vT>* subTreeRoot = 0,
    typename Registry<kT, vT>::RBTreeNodePtr *node = 0) const;

    // Insert a key into the tree:
    //     create a new node and insert it as a leaf.
    // The color of a new node is red.
    // Should be called after the "find" method, which has returned
    //        a nonzero value (i.e. a key was not found)
    // Input: compare = result of comparing with a key of a parent node
    void insert(
        Node<kT, vT>* parentNode,
        TreeNodeValue<vT>* v,
        vT compare // negative => add as a left son, positive => right
    );

    // Rotate a node x to the left
    void rotateLeft(Node<kT, vT>* x);

    // Rotate a node x to the right
    void rotateRight(Node<kT, vT>* x);

    void rebalanceAfterInsert(Node<kT, vT>* x);

    // Remove a subtree and return the number of nodes removed
    vT removeSubtree(Node<kT, vT>* subTreeRoot);

protected:
    void eraseNode(Node<kT, vT>* node);

};

template <typename vT>
class Integer: public TreeNodeValue<vT> {
public:
    vT number; // The value of a node is an integer number

    Integer():
        TreeNodeValue<vT>(),
        number(0)
    {}

    Integer(int n):
        TreeNodeValue<vT>(),
        number(n)
    {}

    Integer(const Integer& n):
        TreeNodeValue<vT>(),
        number(n.number)
    {}

    virtual vT compareTo(const TreeNodeValue<vT>& v) const {
        return (number - ((const Integer&) v).number);
    }

    virtual ~Integer() {}
};


// Red-Black Tree
// class RBTree, implementation
#include <assert.h>
//#include "RBTree.h"

// Find a key in a subtree
// In: key  -- a key to find;
//     root -- a root of a subtree. If root == 0,
//             then find in complete tree
// Out: node -- a pointer to the node that contains a key,
//                  if key is in the set,
//              or a pointer to a node that should be parent to
//                  a node with this key in case of insertion
// Return value: true, if the subtree contains the key.
template <typename kT, typename vT>
kT RBTree<kT, vT>::find(
    const TreeNodeValue<vT>* key,
    const Node<kT, vT>* subTreeRoot,
    typename Registry<kT, vT>::RBTreeNodePtr *node
) const {
    //Node* node;
    const Node<kT, vT>* x;        // current node
    const Node<kT, vT>* y;        // its parent
    if (subTreeRoot == 0) {
        x = root();
        y = &header;
    } else {
        x = subTreeRoot;
        y = x->parent;
    }
    int n = (-1); // If tree is empty, add the new node as a left son of header
    while (x != 0) {
        const TreeNodeValue<vT>* currentKey = x->value;
        n = key->compareTo(*currentKey);
        y = x;
        if (n == 0) {
            // key is found
            if (node != 0)
                *node = const_cast<Node<kT, vT>*>(x);
            return 0;
        } else if (n < 0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // key is not in the tree
    if (node != 0)
        *node = const_cast<Node<kT, vT>*>(y);
    return n;
}



template <typename kT, typename vT>
bool RBTree<kT, vT>::contains(
    const TreeNodeValue<vT>* key,
    const Node<kT, vT>* subTreeRoot,
    typename Registry<kT, vT>::RBTreeNodePtr *node
) const {
    //Node* node;
    const Node<kT, vT>* x;        // current node
    const Node<kT, vT>* y;        // its parent
    if (subTreeRoot == 0) {
        x = root();
        y = &header;
    } else {
        x = subTreeRoot;
        y = x->parent;
    }
    int n = (-1); // If tree is empty, add the new node as a left son of header
    while (x != 0) {
        const TreeNodeValue<vT>* currentKey = x->value;
        n = key->compareTo(*currentKey);
        y = x;
        if (n == 0) {
            // key is found
            if (node != 0)
                *node = const_cast<Node<kT, vT>*>(x);
            return true;
        } else if (n < 0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // key is not in the tree
    if (node != 0)
        return false;
    return true;
}



// Insert a key into the tree:
//     create a new node and insert it as a leaf.
// The color of a new node is red.
// Should be called after the "find" method, when element was not found.
template <typename kT, typename vT>
void RBTree<kT, vT>::insert(
    Node<kT, vT>* parentNode,
    TreeNodeValue<vT>* key,
    vT compare
) {
    assert(parentNode != 0 && compare != 0);
    Node<kT, vT>* x = new Node<kT, vT>();
    x->value = key;
    x->parent = parentNode;
    if (parentNode == &header)
        x->red = false;                                 // The root of tree is black
    else
        x->red = true;                                  // Paint the new node in red
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
template <typename kT, typename vT>
void RBTree<kT, vT>::rotateLeft(Node<kT, vT>* x) {
    Node<kT, vT>* y = x->right;
    assert(y != 0);
    Node<kT, vT>* p = x->parent;
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
template <typename kT, typename vT>
void RBTree<kT, vT>::rotateRight(Node<kT, vT>* x) {
    Node<kT, vT>* y = x->left;
    assert(y != 0);
    Node<kT, vT>* p = x->parent;
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

template <typename kT, typename vT>
void RBTree<kT, vT>::rebalanceAfterInsert(Node<kT, vT>* x) {
    assert(x->red);
    while(x != root() && x->parent->red) {
        if (x->parent == x->parent->parent->left) {
                                                        // parent of x is a left son

            Node<kT, vT>* y = x->parent->parent->right; // y is the sibling of
                                                        //            parent of x
            if (y != 0 && y->red) {                     // if y is red
                x->parent->red = false;                 //     color parent of x in black
                y->red = false;                         //     color y in black
                x = x->parent->parent;                  //     x = grandparent of x
                x->red = true;                          //     color x in red
            } else {                                    // else y is black
                if (x == x->parent->right) {            //     if x is a right son
                    x = x->parent;                      //         x = parent of x
                    rotateLeft(x);                      //         left-rotate x
                }                                       //     end if
                assert(x == x->parent->left);           //     assert: x is a left son
                x->parent->red = false;                 //     color parent of x in black
                x->parent->parent->red = true;          // color grandparent in red
                rotateRight(x->parent->parent);         // right-rotate grandparent
            }                                           // endif
        } else {
                                                        // Mirror case: parent of x is a right son
            assert(x->parent == x->parent->parent->right);

            Node<kT, vT>* y = x->parent->parent->left;  // y is the sibling of
                                                        //           parent of x
            if (y != 0 && y->red) {                     // if y is red
                x->parent->red = false;                 //     color parent of x in black
                y->red = false;                         //     color y in black
                x = x->parent->parent;                  //     x = grandparent of x
                x->red = true;                          //     color x in red
            } else {                                    // else y is black
                if (x == x->parent->left) {             //     if x is a left son
                    x = x->parent;                      //         x = parent of x
                    rotateRight(x);                     //         right-rotate x
                }                                       //     end if
                assert(x == x->parent->right);          //   assert: x is a right son
                x->parent->red = false;                 //     color parent of x in black
                x->parent->parent->red = true;          //  color grandparent in red
                rotateLeft(x->parent->parent);          //  left-rotate grandparent
            }                                           // endif
        }
    }                                                   // end while

                                                        // Always color the root in black
    if (x == root()) {
        x->red = false;
    }
}

template <typename kT, typename vT>
void RBTree<kT, vT>::eraseNode(Node<kT, vT>* node) {
    delete node->value;
}

template <typename kT, typename vT>
void RBTree<kT, vT>::clear() {
    removeSubtree(root());
}

template <typename kT, typename vT>
vT RBTree<kT, vT>::removeSubtree(Node<kT, vT>* subTreeRoot) {
    vT numRemoved = 0;
    if (subTreeRoot == 0)
        return 0;
    if (subTreeRoot->left != 0)
        numRemoved += removeSubtree(subTreeRoot->left);  // recursive call
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

#endif /* RBTREE_H */
