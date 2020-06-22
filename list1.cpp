#include <iostream>
#include "list.h"
using namespace std;

void LinkedList::Append(int data) {

	Node *newNode = new Node;	// 새로 추가한 노드
	Node *currentNode = head;	// 현재 노드를 가리키는 노드 포인터 선언 및 초기화
	
	newNode->data = data;		// 새로 생성된 노드의 멤버 변수의 값 초기화
	newNode->next = NULL;

	if (currentNode == NULL)	// 첫번째 노드 생성
	{
		head = newNode;			// 노드 포인터 head가 가리키는 노드 = 새로 생성된 노드
	}
	else     // 연결 리스트의 마지막에 새로 생성한 노드 추가
	{
		while (currentNode->next != NULL) {		// 연결 리스트의 끝으로 이동
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;			// 연결 리스트의 끝에 새 노드 추가
	}

	return;
}

int LinkedList::Length(void) {		// 연결리스트의 노드 개수를 구하는 함수
	
	Node *currentNode = head;		// 현재 노드는 head가 가리키는 노드
	int count = 0;					// 현재까지의 노드 개수를 저장하며, 0으로 초기화 

	while (currentNode != NULL) {
		count++;
		currentNode = currentNode->next;	// 다음 노드로 이동
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