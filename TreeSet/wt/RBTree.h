//
// Red-Black (balanced) tree
//
#ifndef RBTREE_H
#define RBTREE_H

class TreeNodeValue;    // Predefinition


// A node in Red-Black tree
class Node {
public:
    Node* left;   // pointer to the left son
    Node* right;  // pointer to the right son
    Node* parent; // pointer to the parent
    bool        red;    // the node is red (true) or black (false)
    TreeNodeValue* value;  // The value of tree node: normally, it is
                           //     a pair (key, value of key)
    Node():
        left(0),
        right(0),
        parent(0),
        red(false),
        value(0)
    {
    }
};

typedef Node* RBTreeNodePtr; // Pointer to the RBTreeNode

// An ABSTRACT class representing values in tree nodes
class TreeNodeValue {
public:
    TreeNodeValue() {}
    virtual ~TreeNodeValue() {}   // virtual destructor

    // Abstract class has virtual methods unimplemented

    // The values can be compared
    virtual int compareTo(const TreeNodeValue&) const = 0;

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


class RBTree {
public:
    // Header contains a pointer to the root of the tree
    // as a left son.
    // The tree may be empty, in this case header->left == 0
    Node  header;
    int numNodes;

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

    Node* root() { return header.left; }
    const Node* root() const { return header.left; }

    int size() const { return numNodes; }

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
    int find(
        const TreeNodeValue* key,
        const Node* subTreeRoot = 0,
        RBTreeNodePtr* node = 0
    ) const;
    
    /*bool contains(
        const TreeNodeValue* key,
        const Node* subTreeRoot = 0,
        RBTreeNodePtr* node = 0
    ) const;*/

    // Insert a key into the tree:
    //     create a new node and insert it as a leaf.
    // The color of a new node is red.
    // Should be called after the "find" method, which has returned
    //        a nonzero value (i.e. a key was not found)
    // Input: compare = result of comparing with a key of a parent node
    void insert(
        Node* parentNode,
        TreeNodeValue* v,
        int compare // negative => add as a left son, positive => right
    );

    // Rotate a node x to the left
    void rotateLeft(Node* x);

    // Rotate a node x to the right
    void rotateRight(Node* x);

    void rebalanceAfterInsert(Node* x);

    // Remove a subtree and return the number of nodes removed
    int removeSubtree(Node* subTreeRoot);

protected:
    void eraseNode(Node* node);

};

class Integer: public TreeNodeValue {
public:
    int number; // The value of a node is an integer number

    Integer():
        TreeNodeValue(),
        number(0)
    {}

    Integer(int n):
        TreeNodeValue(),
        number(n)
    {}

    Integer(const Integer& n):
        TreeNodeValue(),
        number(n.number)
    {}

    virtual int compareTo(const TreeNodeValue& v) const {
        return (number - ((const Integer&) v).number);
    }

    virtual ~Integer() {}
};

#endif /* RBTREE_H */
