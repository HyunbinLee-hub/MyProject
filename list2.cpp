#include <iostream>
#include "list.h"
using namespace std;

void LinkedList::Append(int data)
{

	Node *newNode = new Node;	// ���� �߰��� ���

	newNode->data = data;

	if (head == NULL) {			// ù��° ��� ����
		head = newNode;			// ��� ������ head�� ù��°�� ������ ��带 ����Ų��.
	}
	else {						// ���� ����Ʈ�� ���� ���� ��� ����
		newNode->prev = tail;	// ���� ������ ����� ���� ��� = ���Ḯ��Ʈ�� �� ���
		tail->next = newNode;	// ���Ḯ��Ʈ�� �� ����� ���� ���� �� ��� �߰�
	}
	tail = newNode;				// ��� ������ tail�� �׻� ���� ������ ��带 ����Ų��.

	return;
}

void LinkedList::Prepend(int data)		// ���� ����Ʈ�� ó���� �� ��� ����
{
	Node *newNode = new Node;

	newNode->data = data;		// ���� ������ ��忡 ������ ����

	if (head == NULL) {			// ù��° ��� ����
		tail = newNode;			// ��� ������ tail�� ù��°�� ������ ��带 ����Ų��.
	}
	else {						// ���� ����Ʈ�� ù��° ��� �տ� �� ��� ����
		newNode->next = head;	// ���� ������ ����� ���� ��� = ���Ḯ��Ʈ�� ù ���
		head->prev = newNode;	// ���Ḯ��Ʈ�� ù ����� ���� ���� �� ��� �߰�
	}
	head = newNode;				// ��� ������ head�� �׻� ���� ������ ��带 ����Ų��.
}

int LinkedList::Length(void) {

	Node *currentNode = head;	// ���� ���� head�� ����Ű�� ���� ����
	int count = 0;				// ����� ���� ���� ����, 0���� �ʱ�ȭ

	while (currentNode != NULL) {
		count++;
		currentNode = currentNode->next;
	}	// ���Ḯ��Ʈ���� ���� ��忡 ���� �����͸� ������� �̵���Ű�鼭 ��� ������ count�� ����

	return count;
}

void LinkedList::Print(void) {				// ���� ����Ʈ�� �����͸� ������� ���

	Node *currentNode = head;				// ���Ḯ��Ʈ�� ó������ ����

	while (currentNode != NULL) {
		cout << currentNode->data << " ";	// ���� ��忡 ����� �� ���
		currentNode = currentNode->next;	// ���� ����� ���� ���� �̵�
	}	// ���Ḯ��Ʈ�� �� ��忡 ����� ���� ������� ���
	cout << endl;

	return;
}

void LinkedList::PrintReverse(void) {

	Node *currentNode = tail;				// ���Ḯ��Ʈ�� ���������� ����

	while (currentNode != NULL) {
		cout << currentNode->data << " ";	// ���� ��忡 ����� �� ���
		currentNode = currentNode->prev;	// ���� ����� ���� ���� �̵�	
	}	// ���Ḯ��Ʈ�� �� ��忡 ����� ���� �������� ���
	cout << endl;
}