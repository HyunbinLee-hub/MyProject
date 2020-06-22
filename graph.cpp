#include <iostream>
#include <fstream>
#include "graph.h"

void Graph::LoadMatrix(string &filename) {
	ifstream fileload;				// �Էµ� ���ϸ� �ش��ϴ� ������ �б� �������� ����

	int count = 0;					// �Է��� �ؽ�Ʈ ���Ͽ����� �� ��ȣ
	int index = 0;					// weight[]�� �ε��� ��ȣ(0���� ����)
	int res = 0;					// ����ġ�� ���������� ������ ��ȯ �� �����ϰ� �Ǵ� ����

	fileload.open(filename);
	if (fileload.is_open()) {			// �Է��� ���ϸ� �ش��ϴ� ���� ����

		char line[sizeof(fileload)];

		while (!fileload.eof()) {

			fileload.getline(line, sizeof(fileload));

			// ���� ������ ù° �� = vertex�� ����
			if (count == 0) {
				num = atoi(line);	// ������ ù° ���� ���ڸ� �����Ͽ� vertex�� ������ ���
			}
			else if (count > 0 && count <= num) {	// ������ ��° �� ���� = �� vertex �� ����ġ
				for (int i = 0; count <= num && line[i]; i++) {

					if (line[i] != ' ' && line[i] != '\n') {
						res = res * 10 + line[i] - '0';		// �������� ���������� ��ȯ
					}
					else {
						if (res >= 0 && res <= 999) {
							weight[index++] = res;
							res = 0;
						}
					}
				}

				if (res >= 0 && res <= 999) {	// �� ���� �������� �� ��
					weight[index++] = res;
					res = 0;
				}
			}
			count++;				// ������ ���� ������ �̵�

		}
	}

	fileload.close();				// ������ ���� ������ ����
	return;
}

int Graph::GetSize() {				// ��� ���� num�� ����� ������ ���� ��ȯ
	return num;
}

void Graph::PrintMatrix() {
	for (int i = 0; i < num*num; i++) {
		cout << weight[i];
		if ((i + 1) % num == 0)		// ����ġ�� num�� �߰��� ������ ���� ����(1���� ��� ���, ����� 2���� �迭ó��)
			cout << endl;
		else
			cout << ' ';			// �� ����ġ�� �������� ����
	}

	return;
}

// ���ͽ�Ʈ�� �˰����� ������ �����ڷ� Graph (part 3) 28�������� �ڵ带 ����
// ���� ���� s�κ��� �ٸ� ���������� �ִ� ����� ���� Ž��(���ͽ�Ʈ�� �˰���)
void Graph::PrintShortestPathWeight(int s) {

	// ����� s���� ������ i������ ��ο� ���� shortestPath[], dist[] ���� �ʱ�ȭ
	for (int i = 0; i < num; i++) {
		shortestPath[i] = false;
		dist[i] = weight[i + (num * s)];	// ó���� �迭 weight[]�� ����
	}

	shortestPath[s] = true;		// ����� s���� ������ s������ ��δ� �ִܰ��
	dist[s] = 0;				// �������� ������� ���� �� �ִܰ�� ���̴� 0

	// ������� �������� ���� �ٸ� ���
	for (int i = 0; i < num - 2; i++) {
		int min = 999;		// min���� �ʱ⃄�� 999�� ����
		int u = 0;			// �ִܰ�ΰ� �Ǵ� ������ u Ž��

		// �ִܰ���� ���� ������ u�� ����
		for (int w = 0; w < num; w++) {
			if (dist[w] < min && !shortestPath[w]) {
				min = dist[w];
				u = w;
			}
		}

		shortestPath[u] = true;				// ����� s���� ������ u������ �ִܰ�� Ž��
		for (int w = 0; w < num; w++) {
			if (!shortestPath[w] && (dist[u] + weight[w + (num * u)] < dist[w])) {
				dist[w] = dist[u] + weight[w + (num * u)];
				// dist[]�� �־��� ����ġ ����� u�� w���� ���� ���Ͽ� ������ u������ �ִܰ�� �� ����
			}
		}
	}	//  for (int i = 0; i < n-2; i++)�� ��

	// ���� ���� s�κ��� ������ ���������� �ִܰ�� ���
	for (int w = 0; w < num; w++)
		cout << dist[w] << endl;

	return;
}

// ������ ���������� ������ �� ���������� �ִܰ�� ���
void Graph::PrintShortestPath(int s) {
	
	int i, j, k;		// �ݺ���
	int start, end;		// ������, ������

	// visit[], dist[]�� �� �ʱ�ȭ
	for (int i = 0; i < num * num; i++) {
		for (int j = 0; j < num; j++) {
			visit[j + (i * num)] = -1;						// -1 = ��� ����
			dist[j + (i * num)] = weight[j + (i * num)];	// ó���� �迭 weight[]�� ������ dist[] �ʱ�ȭ
		}
	}

	// �÷��̵� �˰����� �̿��Ͽ� �ִܰŸ��� ���� �߰� ���� Ž��
	for (k = 0; k < num; k++) {		// �߰� ��ΰ� 0��, 1��, 2��.. �� ��쿡 ���� Ž��
		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++) {
				if (dist[j + (i * num)] > dist[k + (i * num)] + dist[j + (k * num)]) {
					dist[j + (i * num)] = dist[k + (i * num)] + dist[j + (k * num)];
					visit[j + (i * num)] = k;
				}
			}
		}
	}

	start = s;		// ���� ������ �� �Լ��� ����

	// �ִ� ��� ���
	for (end = 1; end < num; end++) {
		cout << start << ' ';	// ������ ���
		printPath(start, end);	// �߰��� ���İ��� ������ ������ ���
		cout << end << endl;	// ������ ���
	}

	return;
}

// �ִܰ�ο��� �߰��� ���İ��� ������ Ž��(������, ������ ����) 
void Graph::printPath(int start, int end) {

	if (visit[end + (start * num)] != -1) {
		printPath(start, visit[end + (start * num)]);	// ������ ~ �߰� ���������� �ִܰ�� ���(���ȣ��)
		cout << visit[end + (start * num)] << ' ';		// �߰� ������ ��ȣ ���
		printPath(visit[end + (start * num)], end);		// �߰� ���� ~ ������������ �ִܰ�� ���(���)
	}
}