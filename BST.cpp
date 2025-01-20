#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T value;
    Node<T> *left, *right;
    Node(T v = T(), Node<T> *l = NULL, Node<T> *r = NULL) : value(v), left(l), right(r) {};
};

template <class T>
class BST
{
    Node<T> *root;
    public:
    // ham cau tu 
    BST(){ root = NULL;}
    // ham add 
    void add( T val ){
        // neu chua co root
        if(root == NULL){
            root = new Node<T>(val);
            return;
        }
        Node<T> * cur = root;
        while(true){
            // dkien dung 
            if(cur -> value < val && cur -> right == NULL){
                cur -> right = new Node<T>(val);
                return;
            }else if (cur  -> value > val && cur -> left == NULL){
                cur -> left = new Node<T>(val);
                return;
            }
            // bien chay 
            if( cur -> value > val){
                cur = cur -> left;
            }else{
                cur = cur -> right;
            }
        }
    }
    // in theo trung tu 
    void print( Node<T>* cur ){
        if(cur == NULL){
            return;
        }
        print( cur -> left );
        cout << cur -> value << " ";
        print(cur -> right);
    }
    void print(){
        print(root);
        cout<<endl;
    }
    // search
    Node<T>* searchNode(Node<T>* cur ,T val){
        
        if( cur == NULL){
            return NULL;
        }
        if(cur -> value == val){
            return cur;
        }
        Node<T>* res = searchNode(cur -> left,val);
        if( res != NULL ) return res;
        return searchNode(cur -> right,val);
    }
    Node<T>* searchNode(T val){
        searchNode(root,val);
    }
    //delete 
    // 1 con moi ben 
    // node max not exist in left 
    Node<T> * deleteNode(Node<T>* cur ,T val){
        if (cur == 0) return 0;
        if (cur->value == val){
            if(cur->left == 0){
                Node<T> * res = cur->right;
                delete cur;
                return res;
            }
             if(cur->right == 0){
                Node<T> * res = cur->left;
                delete cur;
                return res;
            }
            Node<T> * child = cur->left, *par = cur;
            while(child->right){
                par = child;
                child = child->right;
            }
            cur->value = child->value;
            if(par == cur) par->left = child->left;
            else par->right =child->left;
            delete child;
            return cur;
        }

        if(val<cur->value) cur->left = deleteNode(cur->left,val);
        else cur->right = deleteNode (cur->right,val);
        return cur;
    }
    void deleteNode(T val){
        root = deleteNode(root,val);
    }
};
int main(){
    BST<int> t;
    t.add(14);
    t.add(16);
    t.add(1);
    t.add(15);
    t.add(19);
    t.add(7);
    t.add(6);
    t.print();
    t.deleteNode(14);
    t.print();
    // cout << endl << t.searchNode(6) -> value;
    
    
} 