#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
    Node *root;

    void destroyTree(const Node *node) {
        if (!node) return;
        destroyTree(node->left);                                                                                                                           
        destroyTree(node->right);
        cout << "Delete: " << node->data << endl;
        delete node;
    }

    void printTree(const vector<const Node *const> &level) const {
        int count = level.size();
        for (int i = 0; i < count; i++) {
            if (level[i])
                cout << setw(5) << level[i]->data;
            else
                cout << setw(5) << " ";
        }
        cout << endl;       
    }

public:
    BinaryTree() { root = NULL; }
    ~BinaryTree() { destroyTree(root); }

    // INSERT
    BinaryTree& insert(const int &value) {
        Node *newNode = new Node(value);

        if (!root) {
            root = newNode;
            return *this;
        }

        Node *curr = root;
        Node *parent = NULL;

        while (curr) {
            parent = curr;
            if (value < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        return *this;
    }

    // DISPLAY
    void display() const {
        if (!root) {
            cout << "Tree is empty\n";
            return;
        }

        queue<const Node *> q;
        q.push(root);

        cout << "Tree:\n";

        while (!q.empty()) {
            int size = q.size();
            vector<const Node *const> level;

            while (size--) {
                const Node *node = q.front();
                q.pop();
                level.push_back(node);

                if (node) {
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    q.push(NULL);
                    q.push(NULL);
                }
            }

            bool allNull = true;
            for (auto n : level)
                if (n) allNull = false;
            if (allNull) break;

            printTree(level);
        }
    }

    // SEARCH
    bool search(const int &value) const {
        Node *curr = root;

        while (curr) {
            if (curr->data == value) return true;
            curr = value < curr->data ? curr->left : curr->right;
        }
        return false;
    }

    // TRAVERSALS
    void preorder(const Node *node) const {
        if (!node) return;
        cout << node->data << " -> ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(const Node *node) const {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " -> ";
        inorder(node->right);
    }

    void postorder(const Node *node) const {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " -> ";
    }

    void preorder() const { preorder(root); }
    void inorder() const { inorder(root); }
    void postorder() const { postorder(root); }

    // LEVEL ORDER
    void levelorder() const {
        if (!root) return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                Node *n = q.front(); q.pop();
                cout << n->data << " ";
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            cout << endl;
        }
    }

    // DELETE NODE
    void deleteNode(const int &value) {
        Node *parent = NULL;
        Node *curr = root;

        while (curr && curr->data != value) {
            parent = curr;
            curr = value < curr->data ? curr->left : curr->right;
        }

        if (!curr) return;

        // Case 1: Leaf
        if (!curr->left && !curr->right) {
            if (!parent) root = NULL;
            else if (parent->left == curr) parent->left = NULL;
            else parent->right = NULL;
            cout << "Leaf Node: " << curr->data << endl;
            delete curr;
            return;
        }

        // Case 2: One child
        if (!curr->left || !curr->right) {
            Node *child = curr->left ? curr->left : curr->right;
            if (!parent) root = child;
            else if (parent->left == curr) parent->left = child;
            else parent->right = child;
            delete curr;
            return;
        }

        // Case 3: Two children
        Node *succParent = curr;
        Node *succ = curr->right;
        while (succ->left) {
            succParent = succ;
            succ = succ->left;
        }
        curr->data = succ->data;
        if (succParent->left == succ) succParent->left = succ->right;
        else succParent->right = succ->right;

        delete succ;
    }
};


int main() {
    BinaryTree tree;

    tree.insert(50).insert(25).insert(75).insert(12)
        .insert(30).insert(60).insert(85)
        .insert(52).insert(70);

    tree.display();
    cout << "\nInorder: "; tree.inorder();
    cout << "\nSearch 13: " << (tree.search(13) ? "found" : "not found") << endl;

    tree.deleteNode(52);
    tree.deleteNode(70);

    cout << "\nAfter deletion:\n";
    tree.display();

    cout << "\nPreorder: "; tree.preorder();
    cout << "\nPostorder: "; tree.postorder();
    cout << "\n\nDestructor runs at end...\n";
}
#include <iostream>
#include <iomanip>
#include <math.h>
 
using namespace std;

/*
    1. Preorder, Inorder, Postorder traversals using numbers
    2. Tree common operations (insert, search, traverse, delete node)
    3. Tree traversals (preorder, inorder, postorder, level order)
    4. Identify mistakes in using recursion where it can be avoided (no need for insertion, no need for node deletion).
    5. Tree Complexity
    6. Applications
    7. What about Heap Data Structure (DSA)?

    Tree Traversal Source:    https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
    Insert Node Source:       https://www.javatpoint.com/insertion-in-binary-search-tree
    Delete Node Source:       https://www.interviewbit.com/blog/delete-node-from-binary-search-tree/
    Binary Tree Applications: https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-binary-tree/
*/


struct Node {
    int data;
    Node *left;
    Node *right;
};


class BinaryTree {
    private:
        int height;
        Node *root;

        // method utilities
        void printTree(const vector<const Node *const> &) const;
        void destroyTree(const Node *const);

    public:
        BinaryTree();
        ~BinaryTree();

        BinaryTree& insert(const int &);

        void display() const;

        void preorder(const Node *) const;    // Root -> Left -> Right 
        void inorder(const Node *) const;     // Left -> Root -> Right
        void postorder(const Node *) const;   // Left -> Right -> Root

        void levelorder() const;

        bool search(const int &) const;
        void deleteNode(const int &);
};

/* Your Solution */



int main() {

    BinaryTree tree = BinaryTree();

    cout << endl;
    tree.display();  

    // Ex-1: tree.insert(5).insert(3).insert(8).insert(6).insert(2).insert(4).insert(9).insert(7);
    // Ex-2: https://www.javatpoint.com/insertion-in-binary-search-tree
    tree.insert(50).insert(25).insert(75).insert(12).insert(30).insert(60).insert(85).insert(52).insert(70);
    // Ex-3: tree.insert(2).insert(1).insert(33).insert(0).insert(25).insert(40).insert(11).insert(34).insert(7).insert(12).insert(36).insert(13);

    cout << endl;
    tree.display();  
    cout << endl;

    cout << (tree.search(13) ? "[13 found]" : "[13 not found]") << endl << endl;

    tree.deleteNode(52);
    tree.deleteNode(70);

    cout << endl;
    tree.display();  
    cout << endl;

    // Tree traversals (preorder, inorder, postorder, levelorder)
    cout << "Preorder:   ";
    tree.preorder();
    cout << endl;

    cout << "Inorder:    ";
    tree.inorder();
    cout << endl;

    cout << "Postorder:  ";
    tree.postorder();
    cout << endl;

    cout << "Levelorder: " << endl;
    tree.levelorder();
    cout << endl;
  
  
  	/*
    	------------------------ Output	------------------------
        
        Tree is empty

        Tree height: 3

                            50

                     25             75

               12       30       60       85

                               52   70          

        [13 not found]

        Leaf Node: 52
        Leaf Node: 70

        Tree height: 2

                       50

                 25         75

             12     30     60     85

        Preorder:   50 -> 25 -> 12 -> 30 -> 75 -> 60 -> 85
        Inorder:    12 -> 25 -> 30 -> 50 -> 60 -> 75 -> 85
        Postorder:  12 -> 30 -> 25 -> 60 -> 85 -> 75 -> 50
        Levelorder: 
        Tree height: 2

                       50

                 25         75

             12     30     60     85

        [call of destructor]
         Delete: 12
         Delete: 30
         Delete: 25
         Delete: 60
         Delete: 85
         Delete: 75
         Delete: 50
    */

    return 0;
}