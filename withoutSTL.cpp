#include<iostream>
using namespace std;
template <class T>
class Node{
public:
    T data;
    Node* next;
    Node(T val){
        data=val;
        next=NULL;
    }
};
template <class T>
class ListStack{
    Node<T>* head;
public:
    ListStack(){
        head=NULL;
    }
    void push(T val){
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=newNode;
        } else{
            newNode->next=head;
            head=newNode;
        }
    }

    void pop(){
        Node<T>* temp=head;
        head=head->next;
        temp=NULL;
        delete temp;
    }
    T top(){
        return head->data;
    }
    bool isEmpty(){
        return head==NULL;
    }
};
int main(){
    ListStack<int> ls;
    ls.push(3);
    ls.push(2);
    ls.push(1);
    while(!ls.isEmpty()){
        cout<<ls.top()<<" ";
        ls.pop();
    }
    return 0;
}