#pragma once
#include <string>
using namespace std;

#define MAX_SIZE 1024

class Graph
{
	int num;
	int weight[MAX_SIZE];
	bool shortestPath[MAX_SIZE];	// index에 대응되는 정점까지의 경로의 최단경로 여부를 저장
	int dist[MAX_SIZE];				// index에 대응되는 정점까지의 최단경로의 길이 저장
	int visit[MAX_SIZE];			// 최단경로에 대한 인접행렬

public:
	void LoadMatrix(string &filename);
	// 입력된 파일명에 해당하는 파일을 불러와 멤버변수 num, weight[] 초기화
	int GetSize();							// 정점의 개수 num을 리턴하는 함수
	void PrintMatrix();						// 초기화한 weight[]를 2차원 배열 형태로 출력
	void PrintShortestPathWeight(int s);	// 출발점 s에 대한 최단경로 탐색 후 출력
	void PrintShortestPath(int s);			// 인자의 시작점에서 나머지 정점까지의 최단 경로 출력
	void printPath(int start, int end);		// 중간에 거쳐가는 정점이 있으면 출력
};