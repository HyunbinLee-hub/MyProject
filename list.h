#pragma once

class LinkedList
{
public:
	LinkedList() {		// ��� ������ head, tail�� �� �ʱ�ȭ
		head = NULL;
		tail = NULL;
	}
	~LinkedList() {		// �� ��忡 �Ҵ�� �޸� ����
		Node *temp = head;
		Node *next_temp;

		while (temp != NULL) {
			next_temp = temp->next;
			delete temp;
			temp = next_temp;
		}
	}

	void Append(int data);	// List�� �������� ���ο� data�� ���� Node �߰�
	void Prepend(int data);
	int Length(void);			// List�� �ִ� Node�� ���� return
	void Print(void);			// List�� �ִ� ��� Node�� head���� ������� ���
	void PrintReverse(void);

private:
	class Node
	{
		int data;		// Node�� ����� data
		Node *next;		// ���� Node�� ���� pointer
		Node *prev;

		Node() {		// ��� ������ next, prev �ʱ�ȭ
			prev = NULL;
			next = NULL;
		}
		friend class LinkedList; 
	};
	Node *head;		// List�� ���� ù Node�� ����Ű�� pointer
	Node *tail;
};