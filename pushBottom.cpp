#include<iostream>
using namespace std;
#include<stack>
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
int main(){
    stack<int> st1;
    st1.push(3);
    st1.push(2);
    st1.push(1);
    st1.push(5);
    pushAtBot(st1, 4);
    while (!st1.empty()){
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<endl;
    return 0;
}