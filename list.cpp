#include <iostream>
#include "list.h"
using namespace std;

void LinkedList::Append(int data) 
{

	Node *newNode = new Node;	// ���� �߰��� ���
	Node *currentNode = head;	// ���� ��带 ����Ű�� ��� ������ ���� �� �ʱ�ȭ

	newNode->data = data;
	newNode->next = NULL;

	if (currentNode == NULL)	// ù��° ��� ����
	{
		head = newNode;
	}
	else      // ���� ����Ʈ�� ���� ���� ��� ����
	{
		while (currentNode->next != NULL) {	// ���� ����Ʈ�� ������ ���� �̵�
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;	// ���Ḯ��Ʈ�� ���� �� ��� ����
	}

	return;
}

void LinkedList::Prepend(int data)		// ���� ����Ʈ�� ó���� �� ��� ����
{
	Node *newNode = new Node;

	if (head == NULL) {			// ù��° ��� ����
		head = newNode;			// ��� ������ head�� ���� ������ ��带 ����Ų��.
		newNode->data = data;	// �� ����� ��� ���� �� �ʱ�ȭ
		newNode->next = NULL;
	}
	else {						// ���� ����Ʈ�� ù��° ��� �տ� �� ��� ����
		newNode->data = data;	// ���� ������ ��忡 ������ ����
		newNode->next = head;	// ���� ������ ����� ���� ���� ���� ����Ʈ�� ù��° ���
		head = newNode;			// ��� ������ head�� ���� ������ ��带 ����Ű���� ����
	}
}

int LinkedList::Length() 
{

	Node *currentNode = head;	// ���� ���� head�� ����Ű�� ���� ����
	int count = 0;				// ����� ���� ���� ����, 0���� �ʱ�ȭ

	while (currentNode != NULL) {
		count++;
		currentNode = currentNode->next;
	}	// ���Ḯ��Ʈ�� ó������ ������ �̵��ϸ鼭 ��������� ��� ���� ����

	return count;
}

void LinkedList::Print() {		// ���� ����Ʈ�� �����͸� ������� ���

	Node *currentNode = head;

	while (currentNode != NULL) {
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}	// ���Ḯ��Ʈ�� ó������ ������ �̵��ϸ鼭 ��忡 ����� ���� ���
	cout << endl;

	return;
}