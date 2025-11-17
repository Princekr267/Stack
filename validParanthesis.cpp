#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool isValid(string paranthesis){
    stack<char> bracket;
    for(int i=0; i<paranthesis.size(); i++){
        char ch=paranthesis[i];
        if(paranthesis[i]=='[' || paranthesis[i]=='{' || paranthesis[i]=='('){
            bracket.push(ch);
        } else{
           if(bracket.empty()) return false;
            int top=bracket.top();
            if(top=='(' && ch==')' || top=='{' && ch=='}' || top=='[' && ch==']'){
                bracket.pop();
            } else return false;

        }
    }
    return bracket.empty();
}
bool isDuplicate(string expression){
    stack<char> s;
    for(int i=0; i<expression.size(); i++){
        char ch=expression[i];
        if(ch==')'){
            if(s.top()=='('){
                return true;
            }
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
    
        } else{
            s.push(ch);
        }
    }
    return false;
}
int main(){
    string paranthesis="()[]{}";
    cout<<isValid(paranthesis)<<endl;
    string express="((2+3))";
    cout<<isDuplicate(express)<<endl;
    return 0;
}