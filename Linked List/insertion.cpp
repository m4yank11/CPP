#include<iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* next;
    // constructor to store values
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
void print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}

// 1. insertion at head
node* insert_head(node* head, int val){
    node* new_node = new node(val);
    if(head == NULL) return new_node;
    new_node->next = head;
    head = new_node;
    return head;
}

// 2. insertion at tail
node* insert_tail(node* head, int val){
    node* new_node = new node(val);
    if(head == NULL) return new_node;
    node* temp = head;
    while(temp-> next != NULL) temp = temp->next;
    temp->next = new_node;
    return head;
}

// 3. insertion at k-th position
node* insert_kth(node* head, int k, int val, int n){
    node* new_node = new node(val);
    if(k < 1 || k > n+1) return NULL;
    node* temp = head;
    int count = 1;
    while(count != k-1 && temp->next != NULL){
        temp = temp->next;
        count++;
    }
    new_node->next = temp ->next;
    temp -> next = new_node;
    return head;
}

// 4. insertion before k where k is a value in linked list
node* insert_before_k(node* head, int k, int val){
    // edge cases
    if(head == NULL) return NULL;
    else if( head-> data == k){
        node* temp = new node(val);
        temp -> next = head;
        return temp;
    }
    node* temp = head;
    while(temp->next != NULL && temp->next->data != k){
        temp = temp -> next;
    }
    if(temp -> next == NULL) return head;
    node* new_node = new node(val);
    new_node-> next = temp -> next;
    temp -> next = new_node;
    return head;
}

int main(){
    int arr[] = {1,4,3,6,2};
    // int arr[] = {};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = convert_arr_2_LL(arr,n);
    print(head);
    // head = insert_head(head, 9);
    // print(head);
    // head = insert_tail(head, 15);
    // print(head);
    // head = insert_kth(head, 3, 21, n);
    // print(head);
    head = insert_before_k(head, 5, 15);
    print(head);
    return 0;
}