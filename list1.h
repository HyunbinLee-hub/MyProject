#pragma once

class LinkedList 
{
public:
	LinkedList() {
		head = NULL;		// ��� ������ head�� NULL�� �ʱ�ȭ
	}
	~LinkedList() {
		Node *temp = head;
		Node *next_temp;

		while (temp != NULL) {	// ��忡 �Ҵ�� �޸� ����
			next_temp = temp->next;
			delete temp;
			temp = next_temp;
		}
	}

	void Append(int data);		// List�� �������� ���ο� data�� ���� Node �߰�
	int Length(void);			// List�� �ִ� Node�� ���� return
	void Print(void);			// List�� �ִ� ��� Node�� head���� ������� ���
	

private:
	class Node
	{
		int data;		// Node�� ����� data
		Node *next;		// ���� Node�� ���� pointer

		friend class LinkedList;
	};
	Node *head;		// List�� ���� ù Node�� ����Ű�� pointer
};