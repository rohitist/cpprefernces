//reverse a linked list
//Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list. Input list [1,2,3,4,5] and left = 2, right = 4 Output should be [1,4,3,2,5]

#include <bits/stdc++.h>


class single_list{
//Inner class
class Node{
public:
    int data;
    Node *next;
    Node() : next(NULL) {}
    Node(int val) : data(val), next(NULL) {}
};

Node *head;
public:
    single_list() : head(NULL) {}
    void push_back(int val){
        if(head){
            Node *tmp = head;
            while(tmp->next){
                tmp = tmp->next;
            }
            tmp->next = new Node(val);
        }
        else{
            head = new Node(val);
        }
    }

    void traverse(){
        if(head){
            Node *tmp = head;
            while(tmp->next){
                std::cout << " " << tmp->data;
                tmp = tmp->next;
            }
            std::cout << " " << tmp->data;
        }
        std::cout << std::endl;
    }

    void reverse(){
        Node *next = NULL;
        Node *prev = NULL;
        Node *curr = head;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    //TODO: not working
    void reverse_between_nodes(int left, int right){
        Node *next = NULL;
        Node *prev = NULL;
        Node *curr = head;

        Node *lhs = NULL;
        Node *rhs = NULL;

        //go to left
        while(curr){
            if(curr->data == left)
                break;
            curr = curr->next;
        }
        lhs = curr;
        //reset curr
        curr = head;

        //go to right
        while(curr){
            if(curr->data == right)
                break;
            curr = curr->next;
        }
        rhs = curr;

        prev = lhs;//we have to keep lhs as it was
        lhs = lhs->next;

        while(lhs){
            next = lhs->next;
            lhs->next = prev;
            prev = lhs;
            lhs = next;

            //prev is new current node here. so, check if rhs is detected
            if(prev->data == right)
                break;
        }
        //head = prev;
    }
};

int main(){
    single_list *slist = new single_list();
    slist->push_back(1);
    slist->push_back(2);
    slist->push_back(3);
    slist->push_back(4);
    slist->push_back(5);
    slist->push_back(6);
    slist->push_back(7);
    slist->push_back(8);
    slist->push_back(9);

    slist->traverse();

    slist->reverse();
   
    slist->traverse();

    //slist->reverse_between_nodes(2, 7);
    //slist->traverse();

    return 0;
}

