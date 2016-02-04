#include <iostream>
#include <functional>
#include <string>

using namespace std;

typedef struct Node{
	int data;
	Node* next;
} Node;

Node* initNode(int a[], int n)
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


void printNode(Node* head)
{
	while (head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* nthToLast(Node* head, int n)
{
	if (n <= 0) return nullptr;
	Node* p1 = head;
	Node* p2 = head;

	for (int i = 0; i < n - 1; i++){
		if (p2 == nullptr) return nullptr;
		p2 = p2->next;
	}
	while (p2->next != nullptr){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

int main()
{
	int n = 12;
	int a1[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	

	Node* head1 = initNode(a1, n);
	printNode(head1);

	Node* p = nthToLast(head1, 3);
	cout << p->data << endl;

	return 0;
}
