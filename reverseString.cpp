#include<iostream>
#include<stack>
#include<string>
using namespace std;
string reverseString( string str){
    string ans;
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        char top=s.top();
        ans+=top;
        s.pop();
    }
    return ans; 
}
void pushAtBot(stack<int> &st, int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int temp=st.top();
    st.pop();
    pushAtBot(st, val);
    st.push(temp);
}  
void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s);
    pushAtBot(s, temp);
}
void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    string str="abcd";
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"Reversed string = "<<reverseString(str)<<endl;
    cout<<"Normal stack: ";
    printStack(st);
    reverseStack(st);
    cout<<"Reversed Stack = ";
    printStack(st);
    return 0;
}