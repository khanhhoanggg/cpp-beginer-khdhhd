#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Node
{
    T value;
    Node<T> *left, *right;
    int height;
    Node(T v = T(), Node<T> *l = 0, Node<T> *r = 0, int h = 0) : value(v), left(l), right(r), height(h) {};
};

template <class T>
class AVL
{
    Node<T> *root;
    int getHeight(Node<T> *cur)
    {
        if (cur == 0)
            return -1;
        return cur->height;
    }
    int maxHeight(Node<T> *left, Node<T> *right)
    {
        if (getHeight(left) > getHeight(right))
            return getHeight(left);
        return getHeight(right);
    }

public:
    AVL() { root = 0; }
    ~AVL()
    {
        clear(root);
    }
    void clear(Node<T> *cur)
    {
        if (cur == 0)
            return;
        clear(cur->left);
        clear(cur->right);
        delete cur;
    }

    void add(Node<T> *&cur, T val)
    {
        if (cur->value > val)
        {
            if (cur->left == 0)
                cur->left = new Node<T>(val);
            else
                add(cur->left, val);
        }
        else
        {
            if (cur->right == 0)
                cur->right = new Node<T>(val);
            else
                add(cur->right, val);
        }
        balance(cur);
        cur->height = maxHeight(cur->left, cur->right) + 1;
    }
    void add(T val)
    {
        if (root == 0)
            root = new Node<T>(val);
        else
        {
            add(root, val);
        }
    }
    void print(Node<T> *cur, T par)
    {
        if (cur == 0)
            return;
        print(cur->left, cur->value);
        cout << par << " " << cur->value << " " << cur->height << endl;
        print(cur->right, cur->value);
    }
    void print(T par)
    {
        print(root, par);
        cout << "----------\n";
    }
    void rotateL(Node<T> *&cur)
    {
        Node<T> *tmp = cur->left;
        cur->left = tmp->right;
        tmp->right = cur;
        cur->height = maxHeight(cur->left, cur->right) + 1;
        tmp->height = maxHeight(tmp->left, tmp->right) + 1;
        cur = tmp;
    }
    void rotateR(Node<T> *&cur)
    {
        Node<T> *tmp = cur->right;
        cur->right = tmp->left;
        tmp->left = cur;
        cur->height = maxHeight(cur->left, cur->right) + 1;
        tmp->height = maxHeight(tmp->left, tmp->right) + 1;
        cur = tmp;
    }
    void rotateLR(Node<T> *&cur)
    {
        rotateR(cur->left);
        rotateL(cur);
    }

    void rotateRL(Node<T> *&cur)
    {
        rotateL(cur->right);
        rotateR(cur);
    }
    void balance(Node<T> *&cur)
    {
        if (getHeight(cur->left) - getHeight(cur->right) > 1)
        {
            if (getHeight(cur->left->left) >= getHeight(cur->left->right))
                rotateL(cur);
            else
                rotateLR(cur);
        }
        else if (getHeight(cur->right) - getHeight(cur->left) > 1)
        {
            if (getHeight(cur->right->right) >= getHeight(cur->right->left))
                rotateR(cur);
            else
                rotateRL(cur);
        }
    }
    void balance()
    {
        balance(root);
    }
    Node<T> *deleteNode(Node<T> *cur, T val)
    {
        if (cur == 0)
            return 0;
        if (cur->value == val)
        {
            // if (cur->left == 0 && cur->right == 0){
            //     delete cur;
            //     return 0;
            // }
            if (cur->left == 0)
            {
                Node<T> *res = cur->right;
                delete cur;
                return res;
            }
            if (cur->right == 0)
            {
                Node<T> *res = cur->left;
                delete cur;
                return res;
            }
            Node<T> *child = cur->left, *par = cur;
            while (child->right)
            {
                par = child;
                child = child->right;
            }
            cur->value = child->value;
            if (par == cur)
                par->left = child->left;
            else
                par->right = child->left;
            delete child;
            par->height = maxHeight(par->left, par->right) + 1;
            balance(cur);
            cur->height = maxHeight(cur->left, cur->right) + 1;
            return cur;
        }

        if (val < cur->value)
            cur->left = deleteNode(cur->left, val);
        else
            cur->right = deleteNode(cur->right, val);
        balance(cur);
        cur->height = maxHeight(cur->left, cur->right) + 1;
        return cur;
    }
    void deleteNode(T val)
    {
        root = deleteNode(root, val);
    }
};

int main()
{
    AVL<int> t;
    t.add(6);
    t.add(8);
    t.add(7);
    t.add(1);
    t.add(3);
    t.add(9);
    t.add(2);
    t.add(10);
    t.deleteNode(3);
    t.print(-1);
    return 0;
}