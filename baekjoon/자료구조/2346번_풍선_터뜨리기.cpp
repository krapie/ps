/*
baekjoon 2346��: ǳ�� �Ͷ߸���

�ð� ����: 2��
�޸� ����: 4 MB 

����
N���� ǳ���� �ִ�. �� ǳ�� �ȿ��� -N���� N������ ���� �����ִ� ���̰� ��� �ִ�. �� ǳ������ ������ ���� ��Ģ���� �Ͷ߸���.
�켱, ���� ó������ 1�� ǳ���� �Ͷ߸���. �������� ǳ�� �ȿ� �ִ� ���̸� ������ �� ���̿� �����ִ� ����ŭ �̵��Ͽ� ���� ǳ���� �Ͷ߸���. ����� ���� ���� ��쿡�� ����������, ������ ���� ���� ���� �������� �̵��Ѵ�. ǳ���� �������� ���� �ִٰ� �����Ѵ�. ��, 1�� ǳ���� ���ʿ� N�� ǳ���� �ְ�, N�� ǳ���� �����ʿ� 1�� ǳ���� �ִ� ���̴�. �̵��� ������ �̹� ���� ǳ���� ���� �����Ѵ�.
���� ��� �ټ� ���� ǳ�� �ȿ� ���ʷ� 3, 2, 1, -3, -1�� ���� �־��ٰ� ����. �� ��� 3�� ���� �ִ� 1�� ǳ��, -3�� ���� �ִ� 4�� ǳ��, -1�� ���� �ִ� 5�� ǳ��, 1�� ���� �ִ� 3�� ǳ��, 2�� ���� �ִ� 2�� ǳ���� ������� ������ �ȴ�.

�Է�
ù° �ٿ� �ڿ��� N(1��N��1,000)�� �־�����. ���� �ٿ��� ���ʷ� �� ǳ�� ���� ���̿� ���� �ִ� ���� �־�����. ���ǻ� 0�� �������� �ʴٰ� ��������.

���
ù° �ٿ� ���� ǳ���� ��ȣ�� ���ʷ� �����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<pair<int,int>> v;
int n;
int num;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> num;
		
		v.push_back(make_pair(num,i+1));
	}
	
	
	int idx = 0;
	int move = 0;
	int N = n;
	
	for(int i=0; i<N; i++) {
		cout << v[idx].second << " ";
		
		move = v[idx].first;
		if(move > 0)
			move--;
		
		v.erase(v.begin() + idx);
		
		idx += move;
		if(--n == 0) // n = 0�̸� ������ ���� �Ұ� 
			break;
		
		idx = (idx >= 0) ? (idx) : (n + idx % n);
		idx %= n;
	}
} 

// ���� ����Ʈ
// vector, list ��� erase �������̽�  ��� ���� 
