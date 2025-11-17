#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void stockSpanProb(vector<int> stock, vector<int> span){
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=1; i<stock.size(); i++){
        int currPrice=stock[i];
        while(!s.empty() && currPrice>=stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i]=i+1;
        } else{
            int prevHigh=s.top();
            span[i]=i-prevHigh;
        }
        s.push(i);
        //cout<<endl;
    }
    for(int i=0; i<span.size(); i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
}
void nextGreater(vector<int> arr, vector<int> &ans){
    stack<int> a;
    int size=(arr.size()-1);
    // a.push(arr[size]);
    // ans[size]=-1;
    for(int i=size; i>=0; i--){
        int currEle=arr[i];
        while(!a.empty() && currEle>=arr[a.top()]){
            a.pop();
        }
        if(a.empty()){
            ans[i]=-1;
        } else{
            int nextHigh=arr[a.top()];
            ans[i]=nextHigh ;
        }
        a.push(i);
    }
    
    for(int i=0; i<size+1; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> stock={100, 80, 60, 70, 60, 85, 100};
    vector<int> span={0, 0, 0, 0, 0, 0, 0};
    stockSpanProb(stock, span);
    vector<int> arr={4, 5, 2, 25};
    vector<int> ans={0, 0, 0, 0};
    nextGreater(arr, ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}