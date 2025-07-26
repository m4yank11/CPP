#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int x){
        data = x;
        next = NULL;
    }
    
    node(int x, node* ptr){
        data = x;
        next = ptr;
    }
};

node* arr_to_ll(int arr[],int n){
    node* head = new node(arr[0]);
    node* prev = head;
    for(int i = 1 ; i < n ; i++){
        node* temp = new node(arr[i]);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// reverse using optimised technique without extra space
node* reverse(node* head){
    node* temp = head;
    node* front = NULL;
    node* back = NULL;
    while(temp){
        front = temp->next;
        temp->next = back;
        back = temp;
        temp = front;
    }
    return back;
}

// reverse using recursion
node* recursive_reverse(node* head){
    // base case
    if(head == NULL || head->next == NULL) return head;
    node* newhead = recursive_reverse(head->next);
    node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}

int main(){
    int arr[] = {1,5,2,8,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = arr_to_ll(arr,n);
    print(head);
    //
    
    print(recursive_reverse(head));
    return 0;
}