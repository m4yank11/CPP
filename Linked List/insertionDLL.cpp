#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    public:
    node(int x, node* n, node* p){
        data = x;
        next = n;
        prev = p;
    }
    public:
    node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

node* convert_arr_to_ll(int arr[],int n){
    node* head = new node(arr[0]);
    node* last = head;
    for(int i = 1; i < n ; i++){
        node* temp = new node(arr[i],NULL,last);
        last->next = temp;
        last = temp;
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

//1. inserting at head
node* insert_head(node* head, int val){
    node* newnode = new node(val,head,NULL);
    if(head == NULL) return newnode;
    head->prev = newnode;
    head = newnode;
    return head;
}

//2. inserting at tail
node* insert_tail(node* head, int val){
    node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    node* newnode = new node(val,NULL,tail);
    tail->next = newnode;
    return head;
}

//3. inserting at any given k
node* insert_at_k(node* head, int k, int val){
    if(k==1) return insert_head(head,val);
    int pos = 0;
    node* temp = head;
    while(temp!=NULL){
        pos++;
        if(pos == k) break;
        temp = temp->next;
    }
    node* pre = temp->prev;
    node* newnode = new node(val,temp,pre);
    temp->prev = newnode;
    pre->next = newnode;
    return head;
}

//4. inserting before a given node
void insert_before_node(node* node, int val){
    node* pre = node->prev;
    node* newnode = new node(val,node,pre);
    pre->next = newnode;
    node->prev = newnode;
    return;
}

int main(){
    int arr[] = {1,4,6,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = convert_arr_to_ll(arr,n);
    print(head);
    print(insert_head(head,15));
    print(insert_tail(head,12));
    print(insert_at_k(head,5,0));
    insert_before_node(head->next->next, 100);
    print(head);
    return 0;
}
