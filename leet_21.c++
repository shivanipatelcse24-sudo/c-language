#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* merge(Node* a, Node* b) {
    Node dummy(0);
    Node* temp = &dummy;

    while(a && b) {
        if(a->data < b->data) {
            temp->next = a;
            a = a->next;
        } else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }

    temp->next = a ? a : b;
    return dummy.next;
}

void print(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* a = new Node(1);
    a->next = new Node(2);
    a->next->next = new Node(4);

    Node* b = new Node(1);
    b->next = new Node(3);
    b->next->next = new Node(4);

    print(merge(a, b));
}