#include <iostream>
#include "list.h"
using namespace std;

void LinkedList::Append(int data) {

	Node *newNode = new Node;	// ���� �߰��� ���
	Node *currentNode = head;	// ���� ��带 ����Ű�� ��� ������ ���� �� �ʱ�ȭ
	
	newNode->data = data;		// ���� ������ ����� ��� ������ �� �ʱ�ȭ
	newNode->next = NULL;

	if (currentNode == NULL)	// ù��° ��� ����
	{
		head = newNode;			// ��� ������ head�� ����Ű�� ��� = ���� ������ ���
	}
	else     // ���� ����Ʈ�� �������� ���� ������ ��� �߰�
	{
		while (currentNode->next != NULL) {		// ���� ����Ʈ�� ������ �̵�
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;			// ���� ����Ʈ�� ���� �� ��� �߰�
	}

	return;
}

int LinkedList::Length(void) {		// ���Ḯ��Ʈ�� ��� ������ ���ϴ� �Լ�
	
	Node *currentNode = head;		// ���� ���� head�� ����Ű�� ���
	int count = 0;					// ��������� ��� ������ �����ϸ�, 0���� �ʱ�ȭ 

	while (currentNode != NULL) {
		count++;
		currentNode = currentNode->next;	// ���� ���� �̵�
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