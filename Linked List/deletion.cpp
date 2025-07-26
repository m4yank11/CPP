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

// 1. deleting head
node* delete_head(node* head){
    if(head == NULL) return head;
    node* temp = head;
    head = head->next;
    free(temp); 
    return head;
}
// 2. deleting tail
node* delete_tail(node* head){
    if(head == NULL || head -> next == NULL) return NULL;
    node* temp = head;
    while(temp->next->next != NULL) temp = temp->next;
    //now we are standing on the second last element
    node* last = temp->next;
    free(last);
    temp->next = NULL;
    return head;
}

// 3. deleting node from k-th position
node* delete_kth(node* head, int k, int n){
    if(k==1) head = delete_head(head);
    else if(k == n) head = delete_tail(head);
    else{
        if(k > n || k < 1) return NULL;
        node* temp = head;
        int count = 1;
        while(count != k-1 && temp->next != NULL){
            temp = temp->next;
            count++;
        }
        node* kth = temp->next;
        temp->next = temp->next->next;
        free(kth);
    }
    return head;
}
// 4. deleting a particular element
node* delete_k(node* head, int val){
    if(head == NULL) return head;
    if(head->data == val){
        node* temp = head;
        head = head->next;
        free(temp);
    }
    else{
        node* temp = head;
        while(temp->next != NULL && temp->next->data != val){
            temp = temp->next;
        }
        if(temp->next != NULL && temp->next->data == val){
            node* kth = temp->next;
            temp->next = temp->next->next;
            free(kth);
        }    
    }
    return head;
}

int main(){
    int arr[] = {1,4,3,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = convert_arr_2_LL(arr,n);
    print(head);
    head = delete_head(head);
    print(head);
    head = delete_tail(head);
    print(head);
    head = delete_kth(head, 3, n);
    print(head);
    head = delete_k(head, 4);
    print(head);
    return 0;
}