#pragma once

class LinkedList
{
public:
	LinkedList() {
		head = NULL;	// 노드 포인터 head의 값 초기화 
	}
	~LinkedList() {		// 각 노드에 할당된 메모리 해제
		Node *temp = head;
		Node *next_temp;

		while (temp != NULL) {
			next_temp = temp->next;
			delete temp;
			temp = next_temp;
		}
	}

	void Append(int data);	// List의 마지막에 새로운 data에 대한 Node 추가
	void Prepend(int data);
	int Length();			// List에 있는 Node의 수를 return
	void Print();			// List에 있는 모든 Node를 head부터 순서대로 출력


private:
	class Node
	{
		int data;		// Node에 저장될 data
		Node *next;		// 다음 Node에 대한 pointer

		friend class LinkedList;
	};
	Node *head;		// List의 가장 첫 Node를 가리키는 pointer
};