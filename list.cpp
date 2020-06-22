#include <iostream>
#include "list.h"
using namespace std;

void LinkedList::Append(int data)
{

	Node *newNode = new Node;	// 새로 추가한 노드

	newNode->data = data;

	if (head == NULL) {			// 첫번째 노드 생성
		head = newNode;			// 노드 포인터 head는 첫번째로 생성된 노드를 가리킨다.
	}
	else {						// 연결 리스트의 끝에 다음 노드 생성
		newNode->prev = tail;	// 새로 생성된 노드의 이전 노드 = 연결리스트의 끝 노드
		tail->next = newNode;	// 연결리스트의 끝 노드의 다음 노드로 새 노드 추가
	}
	tail = newNode;				// 노드 포인터 tail은 항상 새로 생성된 노드를 가리킨다.

	return;
}

void LinkedList::Prepend(int data)		// 연결 리스트의 처음에 새 노드 생성
{
	Node *newNode = new Node;

	newNode->data = data;		// 새로 생성한 노드에 데이터 저장

	if (head == NULL) {			// 첫번째 노드 생성
		tail = newNode;			// 노드 포인터 tail은 첫번째로 생성된 노드를 가리킨다.
	}
	else {						// 연결 리스트의 첫번째 노드 앞에 새 노드 생성
		newNode->next = head;	// 새로 생성한 노드의 다음 노드 = 연결리스트의 첫 노드
		head->prev = newNode;	// 연결리스트의 첫 노드의 이전 노드로 새 노드 추가
	}
	head = newNode;				// 노드 포인터 head는 항상 새로 생성된 노드를 가리킨다.
}

int LinkedList::Length(void) {

	Node *currentNode = head;	// 현재 노드는 head가 가리키는 노드와 동일
	int count = 0;				// 노드의 개수 저장 변수, 0으로 초기화

	while (currentNode != NULL) {
		count++;
		currentNode = currentNode->next;
	}	// 연결리스트에서 현재 노드에 대한 포인터를 순서대로 이동시키면서 노드 개수를 count에 저장

	return count;
}

void LinkedList::Print(void) {				// 연결 리스트의 데이터를 순서대로 출력

	Node *currentNode = head;				// 연결리스트의 처음부터 시작

	while (currentNode != NULL) {
		cout << currentNode->data << " ";	// 현재 노드에 저장된 값 출력
		currentNode = currentNode->next;	// 현재 노드의 다음 노드로 이동
	}	// 연결리스트의 각 노드에 저장된 값을 순서대로 출력
	cout << endl;

	return;
}

void LinkedList::PrintReverse(void) {

	Node *currentNode = tail;				// 연결리스트의 마지막부터 시작

	while (currentNode != NULL) {
		cout << currentNode->data << " ";	// 현재 노드에 저장된 값 출력
		currentNode = currentNode->prev;	// 현재 노드의 이전 노드로 이동	
	}	// 연결리스트의 각 노드에 저장된 값을 역순으로 출력
	cout << endl;
}