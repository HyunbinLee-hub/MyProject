#pragma once

class LinkedList
{
public:
	LinkedList() {		// 노드 포인터 head, tail의 값 초기화
		head = NULL;
		tail = NULL;
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
	int Length(void);			// List에 있는 Node의 수를 return
	void Print(void);			// List에 있는 모든 Node를 head부터 순서대로 출력
	void PrintReverse(void);

private:
	class Node
	{
		int data;		// Node에 저장될 data
		Node *next;		// 다음 Node에 대한 pointer
		Node *prev;

		Node() {		// 노드 포인터 next, prev 초기화
			prev = NULL;
			next = NULL;
		}
		friend class LinkedList; 
	};
	Node *head;		// List의 가장 첫 Node를 가리키는 pointer
	Node *tail;
};