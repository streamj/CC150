#include <iostream>
#include <functional>
#include <string>

using namespace std;

typedef struct Node{
    int data;
    Node* next;
} Node;

Node* initList(int a[], int n)
{
    Node* head = nullptr;
    Node* p = nullptr;
    for (int i = 0; i < n; i++){
        Node* nd = new Node();
        nd->data = a[i];
        if (i == 0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

void printList(Node* head)
{
    while (head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* linkAdder(Node* p, Node* q)
{
    if (p == nullptr) return q;
    if (q == nullptr) return p;
    if (p == nullptr && q == nullptr) return nullptr;

    Node* ret = nullptr;    // the result list head
    Node* iter = nullptr;   // the result list iterator
    int carry = 0;
    while (p && q){
        int value = p->data + q->data + carry;
        Node* r = new Node();
        r->data = value % 10; // store the digit in ones
        if (iter){
            iter->next = r; // connect node
            iter = r;       // point to next node
        }
        else{
            ret = iter = r; // first time two pointer point to result list head
        }
        carry = value / 10; // store the carry number, and will be add by next loop
        p = p->next;
        q = q->next;
    }
    // while p ends or q ends
    while (p){
        int value = p->data + carry;
        Node* r = new Node();
        r->data = value % 10;
        iter->next = r;
        iter = r;
        carry = value / 10;
        p = p->next;
    }
    while (q){
        int value = q->data + carry;
        Node* r = new Node();
        r->data = value % 10;
        iter->next = r;
        iter = r;
        carry = value / 10;
        q = q->next;
    }
    // while p q has same length
    if (carry > 0){
        Node* r = new Node();
        r->data = carry;
        iter->next = r;
    }

    return ret;
}


Node* revlinkAdder(Node* p, Node* q)
{
    if (p == nullptr) return q;
    if (q == nullptr) return p;
    if (p == nullptr && q == nullptr) return nullptr;


}

int main()
{
    int a1[] = { 5, 6, 8 };
    int a2[] = { 3, 4, 1 };
    int a3[] = { 4, 5, 7, 8, 2 };
    
    Node* head1 = initList(a1, 3);
    printList(head1);

    Node* head2 = initList(a2, 3);
    printList(head2);

    Node* head3 = initList(a3, 5);
    printList(head3);

    cout << endl;
    Node* res1 = linkAdder(head1, head2);
    printList(res1);
    
    Node* res2 = linkAdder(head1, head3);
    printList(res2);

    return 0;
}
