#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
template <class T>
class Stack{
    vector<T> stack;
public:
    void push(T val){
        stack.push_back(val);
    }
    void pop(){
        stack.pop_back();
    }
    T top(){
        int lastEleIdx=stack.size()-1;
        return stack[lastEleIdx];
    }
    bool isEmpty(){
        if (stack.size()==0){
            return true;
        }
        return false;
    }
};
int main(){
    
    Stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    // st.pop();
    while(!st.isEmpty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    Stack<char> sc;
    sc.push('c');
    sc.push('b');
    sc.push('a');
    // st.pop();
    while(!sc.isEmpty()){
        cout<<sc.top()<<" ";
        sc.pop();
    }
    cout<<endl;
    Stack<string> ss;
    ss.push("\nJust change class type...");
    ss.push("stack");
    ss.push("string");
    // st.pop();
    while(!ss.isEmpty()){
        cout<<ss.top()<<" ";
        ss.pop();
    }
    return 0;
}