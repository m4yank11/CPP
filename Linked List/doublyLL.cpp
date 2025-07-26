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

//1. deleting head of the DLL
node* delete_head(node* head){
    if(head == NULL || head->next == NULL) return NULL;
    node* temp = head;
    head = head->next;
    head -> prev = NULL;
    temp -> next = NULL;
    free(temp);
    return head;
}

//2. delete tail of the DLL
node* delete_tail(node* head){
    // if no element or 1 element is present in the DLL
    if(head == NULL || head->next == NULL) return NULL;
    // traversing till the 2nd last element of the DLL
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node* last = temp->next;
    temp->next = NULL;
    last->prev = NULL;
    free(last);
    return head;
}

//3. delete element at any k position
node* delete_kth(node* head, int k){
    if(k == 1) return delete_head(head);
    int size = 0;
    node* temp = head;
    while(temp){
        size++;
        temp = temp->next;
    }
    if(k == size) return delete_tail(head);
    else if(k < 1 || k > size) return head;
    else{
        temp = head;
        int x = 1;
        while(temp->next != NULL && x != k-1){
            x++;
            temp = temp->next;
        }
        node* chor = temp->next;
        chor->next->prev = temp;
        temp -> next = chor ->next;
        chor->prev = NULL;
        free(chor);
        
    }
    return head;
}

//4. delete k value
node* delete_val(node* head, int val) {
    // Case 1: If the head itself is the value to be deleted
    if (head->data == val) {
        node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL; // Updating the previous pointer of new head
        }
        temp->next = NULL;
        free(temp);
        return head;
    }

    // Traversing the linked list
    node* temp = head;
    while (temp->next != NULL) {
        // If last element is the value
        if (temp->next->next == NULL && temp->next->data == val) {
            node* tail = temp->next;
            temp->next = NULL;  // Unlink the last node
            tail->prev = NULL;
            free(tail);
            return head;
        }

        // Keep moving through the list
        if (temp->next->data == val) {
            node* chor = temp->next;
            temp->next = chor->next;
            if (chor->next != NULL) {
                chor->next->prev = temp;  // Update prev pointer of the next node
            }
            free(chor);
            return head;
        }
        temp = temp->next;
    }

    // If the value is not found, simply return the head
    return head;
}

int main(){
    int arr[] = {1,4,6,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = convert_arr_to_ll(arr,n);
    print(head);
    // head = delete_head(head);
    // print(head);
    // head = delete_tail(head);
    // head = delete_kth(head, 3);
    // print(head);
    head = delete_val(head,5);
    print(head);

    return 0;
}
