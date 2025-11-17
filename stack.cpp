#include<iostream>
#include<vector>
using namespace std;
class Stack{
    vector<int> stack;
public:
    void push(int val){
        stack.push_back(val);
    }
    bool isEmpty(){
        if(stack.size()==0) return true;
        return false;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return;
        }
        stack.pop_back();
    }
   
    int top(){
        if(isEmpty()==true){
            cout<<"Stack is Empty\n";
            return -1;
        }
        int lastEle=stack.size()-1;
        return stack[lastEle];
    }
};
int main(){
    Stack s1;
    // s1.push(3);
    // s1.push(2);
    // s1.push(1);
    // s1.pop();
    // s1.top();
    while(!s1.isEmpty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    return 0;
}