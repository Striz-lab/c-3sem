//
// Test of class RBTree representing Red-Black Tree
// We work with the set of integer values
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "RBTree.h"

static bool writeIntegerTree(const Node* root, FILE* f, int level = 0);
static bool readIntegerTree(RBTree& tree, FILE* f);
static void printHelp();



int main() {
    printf("Test of Red-Black Tree class\n");
    printHelp();
    FILE* f = NULL;

    // Define a random tree with 20 nodes
    time_t t = time(0); // Current time in seconds since 1 Jan 1970
    srand(t);

    RBTree tree;
    char line[256];
    while (true) {
        printf("Command>");
        if (fgets(line, 254, stdin) == NULL)
            break;

        // Parse a command
        line[254] = 0;
        int len = strlen(line);
        // Remove "\r\n" at the end of line
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = 0; --len;
        }
        if (len > 0 && line[len-1] == '\r') {
            line[len-1] = 0; --len;
        }
        if (len == 0)   // Empty command
            continue;

        int i = 0;
        // Skip a space in beginning of line
        while (i < len && isspace(line[i])) ++i;
        int commandBeg = i;
        while (i < len && isalpha(line[i])) ++i;
        int commandEnd = i;
        int commandLen = commandEnd - commandBeg;

        if (
            strncmp("gentree", line+commandBeg, commandLen) == 0
        ) {
            // Generate a random tree with n nodes
            while (i < len && isspace(line[i])) ++i; // Skip a space
            if (i >= len || !isdigit(line[i])) {
                printf("Incorrect command.\n");
                printHelp();
                continue;       // Incorrect command
            }
            int n = atoi(line + i);

            // Generate a random tree
            tree.clear();
            int j = 0;
            if (n > 100)
                n = 100;        // Maximum 100 nodes
            while (j < n) {
                Integer num(rand() % 100 + 1);
                Node* node;
                int c = tree.find(&num, tree.root(), &node);
                if (c != 0) { // if value is not in the tree
                    Integer* v = new Integer(num);
                    tree.insert(node, v, c);
                    ++j;
                }
            }

            // Print a tree to stdout
            writeIntegerTree(tree.root(), stdout);

        } else if (
            strncmp("add", line+commandBeg, commandLen) == 0
        ) {
            // Add a node with a given value to the tree
            while (i < len && isspace(line[i])) ++i; // Skip a space
            if (i >= len || !isdigit(line[i])) {
                printf("Incorrect command.\n");
                printHelp();
                continue;       // Incorrect command
            }
            int n = atoi(line + i);

            Integer num(n);
            Node* node;
            int c = tree.find(&num, tree.root(), &node);
            if (c != 0) { // if value is not in the tree
                Integer* v = new Integer(num);
                tree.insert(node, v, c);
            }

            // Print a tree to stdout
            writeIntegerTree(tree.root(), stdout);

        } else if (
            strncmp("quit", line+commandBeg, commandLen) == 0
        ) {
            break;

        } else if (
            strncmp("init", line+commandBeg, commandLen) == 0
        ) {
            tree.clear();

            // Print a tree to stdout
            writeIntegerTree(tree.root(), stdout);

        } else if (
            strncmp("show", line+commandBeg, commandLen) == 0
        ) {
            // Print a tree to stdout
            writeIntegerTree(tree.root(), stdout);

        } else if (
            strncmp("help", line+commandBeg, commandLen) == 0
        ) {
            printHelp();

        } else {
            printf("Incorrect command.\n");
            printHelp();

        } // end if
    } // end while

    return 0;
}

// Recursive function
static bool writeIntegerTree(
    const Node* root, FILE* f, int level /* = 0 */
) {
    int i;
    for (i = 0; i < level; ++i) {
        fprintf(f, "    ");
    }
    if (root == 0) {
        fprintf(f, "null\n");
    } else {
        Integer* v = (Integer*) root->value;
        fprintf(f, "%d ", v->number);
        if (root->red)
            fprintf(f, " red\n");
        else
            fprintf(f, " black\n");
        writeIntegerTree(root->left, f, level+1);
        writeIntegerTree(root->right, f, level+1);
    }

    return true;
}

// Read a tree from a stream
// Example:                               //
//                 10 black               //
//                /        \              //
//            5 red         15 black      //
//           /   \          /    \        //
//        null  7 black   null    null    //
//               /  \                     //
//            null  null                  //
// is represented as                      //
// 10 black
//     5 red
//         null
//         7 black
//             null
//             null
//     15 black
//         null
//         null
// This is a recursive function
//
static bool readIntegerTree(RBTree& tree, FILE* f) {
    tree.clear();

    char line[256];
    if (fgets(line, 254, f) == NULL)
        return false;
    line[254] = 0;
    int len = strlen(line);
    // Remove "\r\n" at the end of line
    if (len > 0 && line[len-1] == '\n')
        --len;
    if (len > 0 && line[len-1] == '\r')
        --len;
    int i = 0;
    while (i < len && isspace(line[i]))
        ++i;
    if (i < len && (isdigit(line[i]) || line[i] == '-')) {
        int n = atoi(line + i);
        bool red = false;
        // Skip a number
        while (i < len && (isdigit(line[i]) || line[i] == '-'))
            ++i;
        if (i >= len || !isspace(line[i]))
            return false;
        // Skip space
        while (i < len && isspace(line[i]))
            ++i;
        if (i < len && line[i] == 'r')
            red = true;

        RBTree leftSubtree;
        if (!readIntegerTree(leftSubtree, f))   // recursive call
            return false;

        RBTree rightSubtree;
        if (!readIntegerTree(rightSubtree, f))  // recursive call
            return false;

        Node* rootNode = new Node();
        rootNode->red = red;
        rootNode->value = new Integer(n);
        tree.header.left = rootNode;
        rootNode->parent = &(tree.header);
        tree.numNodes = 1;

        if (leftSubtree.size() > 0) {
            // Link root node with left subtree
            rootNode->left = leftSubtree.root();
            leftSubtree.root()->parent = rootNode;
            tree.numNodes += leftSubtree.size();

            // Erase left subtree
            leftSubtree.header.left = 0;
            leftSubtree.numNodes = 0;
        }

        if (rightSubtree.size() > 0) {
            // Link root node with right subtree
            rootNode->right = rightSubtree.root();
            rightSubtree.root()->parent = rootNode;
            tree.numNodes += rightSubtree.size();

            // Erase right subtree
            rightSubtree.header.left = 0;
            rightSubtree.numNodes = 0;
        }
    }

    return true;
}

static void printHelp() {
    printf(
        "Commands:\n"
        "  gentree n\t"
        "\tgenerate a random tree with n nodes\n"
        "  add n\t"
        "\t\tadd an integer value n to a tree\n"
        "  init\t\t\tinitialize a tree\n"
        "  show\t\t\tdisplay a tree\n"
        "  help\t\t\tprint this text\n"
        "  quit\t\t\tquit\n"
    );
}
