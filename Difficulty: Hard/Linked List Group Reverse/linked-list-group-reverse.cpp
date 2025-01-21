//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node* reverse(Node* head,Node* prev){
        if(head->next == NULL){
            head->next = prev;
            return head;
        } 
        Node* temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
        return reverse(head,prev);
    }
    Node* solve(Node* head , int k){
        if(head==NULL) return NULL;
        
        int cnt = 1;
        Node*temp = head;
        while(temp->next!=NULL && cnt++ < k-1){
             temp = temp->next;
        }
        Node* forw = NULL;
        if(temp->next!=NULL) {
            forw = temp->next->next;
            temp->next->next=NULL;
        }
        Node* chota_head = solve(forw,k);
        temp = head;
        Node* ansHead = reverse(head,NULL);
        temp->next = chota_head;
        return ansHead;
    }
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(k==1) return head;
        return solve(head,k); 
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends