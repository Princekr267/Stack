#include<iostream>
#include<list>
using namespace std;
template <class T>
class Liststack{
    list<T> ls;
public:
    void push(T val){
        ls.push_front(val);
    }
    void pop(){
        ls.pop_front();
    };
    T top(){
        return ls.front();
    }
    bool isEmpty(){
        return ls.size()==0;
    }
};
int main(){
    Liststack<int> ls;
    ls.push(3);
    ls.push(2);
    ls.push(1);
    while(!ls.isEmpty()){
        cout<<ls.top()<<" ";
        ls.pop();
    }
    return 0;
}