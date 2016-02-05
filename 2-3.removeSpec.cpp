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

bool removeSpec(Node* p)
{
	if (p == nullptr || p->next == nullptr) return false;
	Node* q = p->next;
	p->data = q->data;
	p->next = q->next;
	delete q;
	return true;
}

int main()
{
	int n = 12;
	int a1[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	
	Node* head1 = initNode(a1, n);
	printNode(head1);

	int m = 5;
	Node* p = head1;
	for (int i = 1; i < m; i++){
		p = p->next;
	}
	
	cout << p->data << endl;

	if (removeSpec(p)){
		printNode(head1);
	}
	else{
		cout << "can't remove" << endl;
	}
	
	return 0;
}
