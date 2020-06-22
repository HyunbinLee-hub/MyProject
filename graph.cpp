#include <iostream>
#include <fstream>
#include "graph.h"

void Graph::LoadMatrix(string &filename) {
	ifstream fileload;				// 입력된 파일명에 해당하는 파일을 읽기 전용으로 오픈

	int count = 0;					// 입력한 텍스트 파일에서의 행 번호
	int index = 0;					// weight[]의 인덱스 번호(0부터 시작)
	int res = 0;					// 가중치를 문자형에서 정수로 변환 후 저장하게 되는 변수

	fileload.open(filename);
	if (fileload.is_open()) {			// 입력한 파일명에 해당하는 파일 오픈

		char line[sizeof(fileload)];

		while (!fileload.eof()) {

			fileload.getline(line, sizeof(fileload));

			// 읽을 파일의 첫째 줄 = vertex의 개수
			if (count == 0) {
				num = atoi(line);	// 파일의 첫째 출의 숫자를 추출하여 vertex의 개수로 사용
			}
			else if (count > 0 && count <= num) {	// 파일의 둘째 행 이후 = 각 vertex 간 가중치
				for (int i = 0; count <= num && line[i]; i++) {

					if (line[i] != ' ' && line[i] != '\n') {
						res = res * 10 + line[i] - '0';		// 문자형을 정수형으로 변환
					}
					else {
						if (res >= 0 && res <= 999) {
							weight[index++] = res;
							res = 0;
						}
					}
				}

				if (res >= 0 && res <= 999) {	// 한 행의 마지막에 들어갈 값
					weight[index++] = res;
					res = 0;
				}
			}
			count++;				// 파일의 다음 행으로 이동

		}
	}

	fileload.close();				// 오픈한 원본 파일을 닫음
	return;
}

int Graph::GetSize() {				// 멤버 변수 num에 저장된 정점의 개수 반환
	return num;
}

void Graph::PrintMatrix() {
	for (int i = 0; i < num*num; i++) {
		cout << weight[i];
		if ((i + 1) % num == 0)		// 가중치가 num개 추가될 때마다 행을 변경(1차원 행렬 사용, 출력은 2차원 배열처럼)
			cout << endl;
		else
			cout << ' ';			// 각 가중치는 공백으로 구분
	}

	return;
}

// 다익스트라 알고리즘의 구현은 강의자료 Graph (part 3) 28페이지의 코드를 참조
// 시작 정점 s로부터 다른 정점까지의 최단 경로의 길이 탐색(다익스트라 알고리즘)
void Graph::PrintShortestPathWeight(int s) {

	// 출발점 s에서 도착점 i까지의 경로에 대해 shortestPath[], dist[] 값을 초기화
	for (int i = 0; i < num; i++) {
		shortestPath[i] = false;
		dist[i] = weight[i + (num * s)];	// 처음의 배열 weight[]과 동일
	}

	shortestPath[s] = true;		// 출발점 s에서 도착점 s까지의 경로는 최단경로
	dist[s] = 0;				// 도착점이 출발점과 같을 때 최단경로 길이는 0

	// 출발점과 도착점이 서로 다른 경우
	for (int i = 0; i < num - 2; i++) {
		int min = 999;		// min값의 초기깂은 999로 설정
		int u = 0;			// 최단경로가 되는 도착점 u 탐색

		// 최단경로일 때의 도착점 u값 갱신
		for (int w = 0; w < num; w++) {
			if (dist[w] < min && !shortestPath[w]) {
				min = dist[w];
				u = w;
			}
		}

		shortestPath[u] = true;				// 출발점 s에서 도착점 u까지의 최단경로 탐색
		for (int w = 0; w < num; w++) {
			if (!shortestPath[w] && (dist[u] + weight[w + (num * u)] < dist[w])) {
				dist[w] = dist[u] + weight[w + (num * u)];
				// dist[]에 주어진 가중치 행렬의 u행 w열의 값을 더하여 도착점 u까지의 최단경로 값 갱신
			}
		}
	}	//  for (int i = 0; i < n-2; i++)의 끝

	// 시작 정점 s로부터 나머지 정점까지의 최단경로 출력
	for (int w = 0; w < num; w++)
		cout << dist[w] << endl;

	return;
}

// 인자의 시작점에서 나머지 각 정점까지의 최단경로 출력
void Graph::PrintShortestPath(int s) {
	
	int i, j, k;		// 반복자
	int start, end;		// 시작점, 도착점

	// visit[], dist[]의 값 초기화
	for (int i = 0; i < num * num; i++) {
		for (int j = 0; j < num; j++) {
			visit[j + (i * num)] = -1;						// -1 = 경로 없음
			dist[j + (i * num)] = weight[j + (i * num)];	// 처음의 배열 weight[]의 값으로 dist[] 초기화
		}
	}

	// 플로이드 알고리즘을 이용하여 최단거리를 갖는 중간 정점 탐색
	for (k = 0; k < num; k++) {		// 중간 경로가 0개, 1개, 2개.. 일 경우에 대해 탐색
		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++) {
				if (dist[j + (i * num)] > dist[k + (i * num)] + dist[j + (k * num)]) {
					dist[j + (i * num)] = dist[k + (i * num)] + dist[j + (k * num)];
					visit[j + (i * num)] = k;
				}
			}
		}
	}

	start = s;		// 시작 정점은 이 함수의 인자

	// 최단 경로 출력
	for (end = 1; end < num; end++) {
		cout << start << ' ';	// 시작점 출력
		printPath(start, end);	// 중간에 거쳐가는 정점이 있으면 출력
		cout << end << endl;	// 도착점 출력
	}

	return;
}

// 최단경로에서 중간에 거쳐가는 정점을 탐색(시작점, 도착점 제외) 
void Graph::printPath(int start, int end) {

	if (visit[end + (start * num)] != -1) {
		printPath(start, visit[end + (start * num)]);	// 시작점 ~ 중간 지점까지의 최단경로 출력(재귀호출)
		cout << visit[end + (start * num)] << ' ';		// 중간 지점의 번호 출력
		printPath(visit[end + (start * num)], end);		// 중간 지점 ~ 도착점까지의 최단경로 출력(재귀)
	}
}