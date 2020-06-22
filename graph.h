#pragma once
#include <string>
using namespace std;

#define MAX_SIZE 1024

class Graph
{
	int num;
	int weight[MAX_SIZE];
	bool shortestPath[MAX_SIZE];	// index�� �����Ǵ� ���������� ����� �ִܰ�� ���θ� ����
	int dist[MAX_SIZE];				// index�� �����Ǵ� ���������� �ִܰ���� ���� ����
	int visit[MAX_SIZE];			// �ִܰ�ο� ���� �������

public:
	void LoadMatrix(string &filename);
	// �Էµ� ���ϸ� �ش��ϴ� ������ �ҷ��� ������� num, weight[] �ʱ�ȭ
	int GetSize();							// ������ ���� num�� �����ϴ� �Լ�
	void PrintMatrix();						// �ʱ�ȭ�� weight[]�� 2���� �迭 ���·� ���
	void PrintShortestPathWeight(int s);	// ����� s�� ���� �ִܰ�� Ž�� �� ���
	void PrintShortestPath(int s);			// ������ ���������� ������ ���������� �ִ� ��� ���
	void printPath(int start, int end);		// �߰��� ���İ��� ������ ������ ���
};