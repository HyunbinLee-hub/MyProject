#include <iostream>
#include "list.h"
using namespace std;

void LinkedList::Append(int data) 
{

	Node *newNode = new Node;	// 새로 추가한 노드
	Node *currentNode = head;	// 현재 노드를 가리키는 노드 포인터 선언 및 초기화

	newNode->data = data;
	newNode->next = NULL;

	if (currentNode == NULL)	// 첫번째 노드 생성
	{
		head = newNode;
	}
	else      // 연결 리스트의 끝에 다음 노드 생성
	{
		while (currentNode->next != NULL) {	// 연결 리스트의 마지막 노드로 이동
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;	// 연결리스트의 끝에 새 노드 생성
	}

	return;
}

void LinkedList::Prepend(int data)		// 연결 리스트의 처음에 새 노드 생성
{
	Node *newNode = new Node;

	if (head == NULL) {			// 첫번째 노드 생성
		head = newNode;			// 노드 포인터 head는 새로 생성된 노드를 가리킨다.
		newNode->data = data;	// 새 노드의 멤버 변수 값 초기화
		newNode->next = NULL;
	}
	else {						// 연결 리스트의 첫번째 노드 앞에 새 노드 생성
		newNode->data = data;	// 새로 생성한 노드에 데이터 저장
		newNode->next = head;	// 새로 생성된 노드의 다음 노드는 연결 리스트의 첫번째 노드
		head = newNode;			// 노드 포인터 head가 새로 생성된 노드를 가리키도록 조정
	}
}

int LinkedList::Length() 
{

	Node *currentNode = head;	// 현재 노드는 head가 가리키는 노드와 동일
	int count = 0;				// 노드의 개수 저장 변수, 0으로 초기화

	while (currentNode != NULL) {
		count++;
		currentNode = currentNode->next;
	}	// 연결리스트의 처음부터 끝까지 이동하면서 현재까지의 노드 개수 저장

	return count;
}

void LinkedList::Print() {		// 연결 리스트의 데이터를 순서대로 출력

	Node *currentNode = head;

	while (currentNode != NULL) {
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}	// 연결리스트의 처음부터 끝까지 이동하면서 노드에 저장된 값을 출력
	cout << endl;

	return;
}