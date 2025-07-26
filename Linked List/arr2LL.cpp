#include<iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

};

node* convert_arr_2_LL(int arr[],int n){
    node* head = new node(arr[0]);
    node* temp = head;
    for(int i = 1 ; i < n ; i++){
        node* new_node = new node(arr[i]);
        temp->next = new_node;
        temp = new_node;
    }
    return head;
}
// searching an element

bool search(node* head, int val){
    node* temp = head;
    while(temp){
        if(temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    int arr[] = {1,4,3,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = convert_arr_2_LL(arr,n);
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    int val = 4;
    if(search(head,val)) cout<<"Element found"<<endl;
    else cout<<"Element not found"<<endl; 
}