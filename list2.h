#pragma once

class LinkedList
{
public:
	LinkedList() {
		head = NULL;	// ��� ������ head�� �� �ʱ�ȭ 
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
	int Length();			// List�� �ִ� Node�� ���� return
	void Print();			// List�� �ִ� ��� Node�� head���� ������� ���


private:
	class Node
	{
		int data;		// Node�� ����� data
		Node *next;		// ���� Node�� ���� pointer

		friend class LinkedList;
	};
	Node *head;		// List�� ���� ù Node�� ����Ű�� pointer
};