#include <bits/stdc++.h>
using namespace std;
 
template <class T>
struct Node
{
    T value;
    Node<T> *next;
    Node(T val = T(), Node<T> *n = NULL) : value(val), next(n) {}
};
 
template <class T>
class Slist
{
private:
    Node<T> *head;
    int size;
 
public:
    Slist()
    {
        head = NULL;
        size = 0;
    }
    void addF(T val)
    {
        if (size == 0)
        {
            head = new Node<T>(val);
        }
        else
        {
            head = new Node<T>(val, head);
        }
        size++;
    }
 
    void print()
    {
        Node<T> *cur = head;
        while (cur != NULL)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }
 
    void printf()
    {
        Node<T> *cur = head;
        for (int i = 0; i < size; i++)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
    }
    int getsize(){
        return size;
    }
 
    void deleteF()
    {
        if (size == 0)
            return;
        else
        {
            Node<T> *tmp = head;
            head = head->next;
            delete tmp;
            size--;
        }
    }
 
    Node<T> *getlink(int index)
    {
        if (index < 0 || index >= size)
            return NULL;
        else
        {
            Node<T> *cur = head;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            return cur;
        }
    }
 
    void deletee(int index)
    {
        if (index < 0 || index >= size)
            return;
        if (index == 0)
            deleteF();
        else
        {
            Node<T> *pre = getlink(index - 1);
            Node<T> *tmp = pre->next;
            pre->next = tmp->next;
            delete tmp;
            size--;
        }
    }
    ~Slist()
    {
        while (head != NULL)
        {
            deleteF();
        }
    }
    void insert(T val, int index)
    {
        if (index < 0 || index > size)
            return;
        else
        {
            Node<T> *tmp = new Node<T>(val);
            if (index == 0)
            {
                addF(val);
            }
            else
            {
                Node<T> *tmp = new Node<T>(val);
                Node<T> *pre = getlink(index - 1);
                tmp->next = pre->next;
                pre->next = tmp;
                size++;
            }
        }
    }
};
template<class T>
void BubbleSort(Slist<T>arr){
    Node<T>*i_node = arr.getlink(0);
    for(int i = 0;i < arr.getsize() - 1;i++){
        Node<T>*min_node = i_node;
        Node<T>*j_node = i_node->next;
        for(int j = i + 1;j < arr.getsize();j++){
            if(min_node ->value > j_node->value){
                min_node = j_node;
            }
            j_node = j_node->next;
        }
        T tmp = i_node -> value;
        i_node -> value = min_node -> value;
        tmp = min_node -> value;
        i_node = i_node ->value;
    }
}
int main()
{
    Slist<int> a;
    a.addF(23);
    a.addF(12);
    a.addF(34);
    a.addF(5);
    a.print();
}
 
 