#include<iostream>
#include<queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};
int huffman_coding(char c[],int f[],int n){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(new Node(c[i],f[i]));
    }

}
int main(){
    int n;
    cout<<"Enter no of characters: ";
    cin>>n;
    char ch[n];
    cout<<"Enter characters: ";
    for(int i=0;i<n;i++ ){  
        cin>>ch[i];
    }
    int freq[n];
    cout<<"Enter frequency of each character: ";
    for(int i=0;i<n;i++){
        cin>>freq[i];
    }
    huffman_coding(ch,freq,n);
    return 0;
}