/*
baekjoon 16928��: ��� ��ٸ� ����

�ð� ����: 1 ��
�޸� ����: 512 MB

����
��� ��ٸ� ������ ��� �ϴ� ť�귯���� ��� �� �ñ��� ���� �����.
�ֻ����� ������ ���� ���ϴ� ���� ������ ���� �� �ִٸ�, �ּ� �� ������ �������� ������ �� ������?
������ ������ü �ֻ����� ����ϸ�, �ֻ����� �� �鿡�� 1���� 6���� ���� �ϳ��� �����ִ�. ������ ũ�Ⱑ 10��10�̰�, �� 100���� ĭ���� �������� �ִ� �����ǿ��� ����ȴ�. �����ǿ��� 1���� 100���� ���� �ϳ��� ������� ������ �ִ�.
�÷��̾�� �ֻ����� ���� ���� ����ŭ �̵��ؾ� �Ѵ�. ���� ���, �÷��̾ i�� ĭ�� �ְ�, �ֻ����� ���� ���� ���� 4���, i+4�� ĭ���� �̵��ؾ� �Ѵ�. ���� �ֻ����� ���� ����� 100�� ĭ�� �Ѿ�ٸ� �̵��� �� ����. ������ ĭ�� ��ٸ���, ��ٸ��� Ÿ�� ���� �ö󰣴�. ���� �ִ� ĭ�� �����ϸ�, ���� ���� �������� �ȴ�. ��, ��ٸ��� �̿��� �̵��� ĭ�� ��ȣ�� ���� �ִ� ĭ�� ��ȣ���� ũ��, ���� �̿��� �̵��� ĭ�� ��ȣ�� ���� �ִ� ĭ�� ��ȣ���� �۾�����.
������ ��ǥ�� 1�� ĭ���� �����ؼ� 100�� ĭ�� �����ϴ� ���̴�.
�������� ���°� �־����� ��, 100�� ĭ�� �����ϱ� ���� �ֻ����� ������ �ϴ� Ƚ���� �ּڰ��� ���غ���.

�Է�
ù° �ٿ� �����ǿ� �ִ� ��ٸ��� �� N(1 �� N �� 15)�� ���� �� M(1 �� M �� 15)�� �־�����.
��° �ٺ��� N���� �ٿ��� ��ٸ��� ������ �ǹ��ϴ� x, y (x < y)�� �־�����. x�� ĭ�� �����ϸ�, y�� ĭ���� �̵��Ѵٴ� �ǹ��̴�.
���� M���� �ٿ��� ���� ������ �ǹ��ϴ� u, v (u > v)�� �־�����. u�� ĭ�� �����ϸ�, v�� ĭ���� �̵��Ѵٴ� �ǹ��̴�.
1�� ĭ�� 100�� ĭ�� ��� ��ٸ��� ���� �Ǵ� ���� �ƴϴ�. ��� ĭ�� �ִ� �ϳ��� ��ٸ� �Ǵ� ���� ������ ������, ���ÿ� �� ������ ��� ������ �ִ� ���� ����. �׻� 100�� ĭ�� ������ �� �ִ� �Է¸� �־�����.

���
100�� ĭ�� �����ϱ� ���� �ֻ����� �ּ� �� �� ������ �ϴ��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
int x, y;
int arr[101];
bool visited[101];

int bfs(int start) {
	queue<pair<int,int> > q; // idx, cnt
	visited[start] = true;
	q.push(make_pair(start, 0));
	
	while(!q.empty()) {
		int idx = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(idx == 100) {
			return cnt;
		}
		
		for(int i=1; i<=6; i++) {
			if(idx+i > 100 || visited[idx+i] || arr[idx+i] > 100 || visited[arr[idx+i]]) {
				continue;
			}
			else {
				if(arr[idx+i] != 0) {
					visited[arr[idx+i]] = true;
					q.push(make_pair(arr[idx+i], cnt+1));
				}
				else {
					visited[idx+i] = true;
					q.push(make_pair(idx+i, cnt+1));
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n+m; i++) {
		cin >> x >> y;
		arr[x] = y;
	}

	cout << bfs(1);
	return 0;
}

/* 
BFS: �ִܰŸ��� ����
!! �ּ� �̵�(�ֻ��� Ƚ��) -> �ִܰŸ� -> BFS  
*/ 
