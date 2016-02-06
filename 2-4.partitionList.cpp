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

Node* partitionTricky(Node* head, int x)
{
	if (head == nullptr) return nullptr;
	Node* smallListStart = nullptr;
	Node* bigListStart = nullptr;
	while (head != nullptr){
		Node* next = head->next;         // old list iterator
		if (head->data < x){
			head->next = smallListStart; // disconnect from oldlist
			smallListStart = head;
		}
		else {
			head->next = bigListStart;
			bigListStart = head;
		}
		head = next;
	}

	if (smallListStart == nullptr){
		return bigListStart;
	}
	Node* newhead = smallListStart;
	// find smallList's end
	while (smallListStart->next != nullptr){
		smallListStart = smallListStart->next;
	}
	smallListStart->next = bigListStart;

	return newhead;
}

Node* partition1(Node* head, int x)
{
	if (head == nullptr) return nullptr;
	Node* smallListStart = nullptr;
	Node* bigListStart = nullptr;
	Node* smallListEnd = nullptr;
	Node* bigListStartEnd = nullptr;

	while (head != nullptr){
		Node* next = head->next; // list iterator always point to oldlist
		head->next = nullptr;    // disconnect from oldlist
		if (head->data < x){
			if (smallListStart == nullptr){
				smallListStart = head;
				smallListEnd = smallListStart;   // list iterator
			}
			else{
				smallListEnd->next = head;
				smallListEnd = head;
			}
		}
		else{
			if (bigListStart == nullptr){
				bigListStart = head;
				bigListStartEnd = bigListStart;   // list iterator
			}
			else{
				bigListStartEnd->next = head;
				bigListStartEnd = head;
			}
		}
		head = next;           // back to oldlist
	}

	// if small one is empty
	if (smallListStart == nullptr){
		return bigListStart;
	}
	// merge two list
	smallListEnd->next = bigListStart;
	return smallListStart;
}

int main()
{
	int n = 12;
	int a1[] = { 18, 23,44,59,92,12,8,0,67,83,25,17 };
	
	Node* head1 = initList(a1, n);
	printList(head1);

	int x = 50;
	cout << "x: " << x << endl;
	
	Node* head2 = partitionTricky(head1, x);
	printList(head2);
	return 0;
}
