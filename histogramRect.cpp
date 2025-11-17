#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void printVec(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int maxArea(vector<int> heights, int size){
    vector<int> nsl(size); //next smaller left
    vector<int> nsr(size); //next smaller right
    stack<int> s;
    s.push(0);
    nsl[0]=-1;
    for(int i=1; i<size; i++){
        int curr=heights[i];
        while(!s.empty() && curr<=heights[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i]=-1;
        } else{
            nsl[i]=s.top();
        }
        s.push(i);
    }
    
    while(!s.empty()) s.pop();

    s.push(size-1); 
    nsr[size-1]=size;
    for(int i=size-2; i>=0; i--){
        int curr=heights[i];
        while(!s.empty() && curr<=heights[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=size;
        } else{
            nsr[i]=s.top();
        }
        s.push(i);;
    }
    //printVec(nsr);

    int MaxArea=0;
    for(int i=0; i<size; i++){
        int ht=heights[i];
        int width=nsr[i]-nsl[i]-1;
        int area= ht*width;
        MaxArea=max(area, MaxArea);
    }
    return MaxArea;
}
int main(){
    vector<int> heights={2,1,5,6,2,3};
    cout<<maxArea(heights, heights.size())<<endl;

    return 0;
}