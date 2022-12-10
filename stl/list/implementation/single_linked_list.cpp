#include <bits/stdc++.h>

using namespace std;

class List{
private:
    class Node{
    public:
        Node *next;
        int data;

        Node(int val):next(nullptr), data(val){}
    };
    Node *head;
public:
    List(): head(nullptr){}

    void push_back(int value){
        cout << "Pushing " << value << " at the end of list\n";
        if(head == nullptr){
            //first element in the list
            head = new Node(value);
        }
        else{
            //if at least one element is in the list
            //traverse to the end and insert the node
            Node *tmp = head;
            while(tmp->next){
                tmp = tmp->next;
            }

            tmp->next = new Node(value);
        }
    }

    void push_front(int value){
        cout << "Pushing " << value << " at the head of list\n";
        if(head == nullptr){
            head = new Node(value);
        }
        else{
            Node *tmp = head;
            Node *node = new Node(value);
            head = node;
            node->next = tmp;
        }
    }

    void dump_list(){
        cout << "dumping the list\n";
        if(head != nullptr){
            Node *tmp = head;
            while(tmp){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }
        cout << endl;
    }
};

int main(){
    List list;
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.push_front(8);

    list.dump_list();

    
    return 0;
}