#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int freq;
    char data;
     node* left;
     node* right;
    node(int fre,char dat){
        freq=fre;data=dat;
        left=right=NULL;
    }
};
class compare{
    public:
    bool operator()(const node* x,const node* y){
        return x->freq>y->freq;
    }
};
void dfs(node parent,int level){
    cout<<level<<" : "<<parent.data<<" : "<<parent.freq<<endl;
    if(parent.left!=NULL)dfs(*parent.left,level+1);
    if(parent.right!=NULL)dfs(*parent.right,level+1);
}

void recurs(node parent,string path,map<char,string> &dict){
    if(parent.left!=NULL)recurs(*parent.left,path+'0',dict);
    if(parent.right!=NULL)recurs(*parent.right,path+'1',dict);
    if(parent.right==NULL&&parent.left==NULL)dict[parent.data]=path;
}
int main(){
    string str="aabbbbcccccccddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    map<char,int >freq;
    for(char c:str)freq[c]+=1;
    vector<node> arr;
    priority_queue<node* ,vector<node*>,compare> pendingNodes;
    for(auto t:freq){
        pendingNodes.push(new node(t.second,t.first));
    }while(pendingNodes.size()>=2){    
        node* child1=pendingNodes.top();    pendingNodes.pop();
        node* child2=pendingNodes.top();    pendingNodes.pop();
        node* parent=new node(child1->freq+child2->freq,'$');
        parent->left=child1;
        parent->right=child2;
        pendingNodes.push(parent);
    }
    map<char,string> dict;
    recurs(*pendingNodes.top(),"",dict);
    for(auto index:dict){
        cout<<index.first<<" "<<index.second<<endl;
    }
}
