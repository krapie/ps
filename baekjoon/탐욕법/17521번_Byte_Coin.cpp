/*
baekjoon 17521��: Byte Coin

�ð� ����: 0.5 ��
�޸� ����: 512 MB

����
�����ں��ε���ȸ��(ICPC)�� ����Ʈ ����(Byte Coin)�� �ڱ��� �����ϰ� �ִ�. ����Ʈ ������ ��ڻ簡 ���� ���� ȭ���̴�. �����δ� ����Ʈ ���� ������ ������ �� ������ �� ���������� ����Ʈ ���� ���� ����� �̸� ��Ȯ�� ������ �� �ִٰ� ��������.
�츮�� 1�Ϻ��� n�ϱ��� n�� ���� �׸� 1�� ���� ����Ʈ ������ ����� �̸� �� �� ������ �츮���Դ� �ʱ� ���� W�� �־��� �ִ�. �׸� 1�� ������ �׸�� �ش� ������ ����Ʈ ���� ������ ��Ÿ����. ���� ����Ʈ ������ �ż��ϰų� �ŵ��� �� �ִٰ� ����. �ٸ� ����Ʈ ���� �ϳ��� ������ �ŵ��ϰų� �ż��� ���� ����. �츮�� n�� �� �����ϰ� �ִ� ��� ������ �ŵ��� �� ������ �ִ� ������ �ִ�ȭ�ϰ� �ʹ�. 
���� ���, �׸� 1�� ���� ����Ʈ ���� ��� �׷����� ù�� �̸� �� �� �ִٰ� �ϰ� �츮���� �־��� �ʱ� ������ 24��� ����. ������ �ִ��� ���̷��� ������ ���� ����Ʈ ������ �ż�, �ŵ��� �� �ִ�. ù �� ���� 20�� �Ἥ 4���� ������ ���. ��° �� ��� ������ �ŵ��ؼ� ���� 28�� ��� ��� 32�� ������ ���� �ȴ�. 5��° �Ǵ� �� ���� 32�� �Ἥ 16���� ������ �ż��Ѵ�. 7��° �Ǵ� �� ��� ������ �ŵ��ؼ� ��� 128�� ������ ���� �ȴ�. 9��° �Ǵ� �� ���� 126�� �Ἥ 42���� ������ ��� 10�� �� ��� ������ �ŵ��Ѵ�. �׷��� 10�� �� ������ 170�� �ǰ� �̰��� �ִ��̴�.
���� �� n, �ʱ� ���� W, 1�Ϻ��� n�ϱ��� �� ������ ����Ʈ ���� ������ �־��� ��, n�� �� �����ϰ� �ִ� ��� ������ �ŵ��� �� �����ϰ� �� ���� ������ �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ǥ���Է��� ����Ѵ�. ù ��° �ٿ� ���� ���� ��Ÿ���� ���� ���� n�� �ʱ� ���� W(1 �� n �� 15, 1 �� W �� 100,000)�� �־�����. ���� n ���� �ٿ���, i��° ���� i���� ����Ʈ ���� ������ ��Ÿ���� ���� si�� �־�����(1 �� si �� 50).

���
����� ǥ������� ����Ѵ�. n�� �� �����ϰ� �ִ� ��� ������ �ŵ��� �� ������ �ִ� ������ �ִ��� �� �࿡ ����Ѵ�. ��� �ʱ� ���� W�� �׷��� ũ�� ������ ���� ������ �ſ� Ŀ�� �� ������ ��������.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
ull w; 
ull coins; // ���ε� �ſ� Ŀ�� �� �����Ƿ� ull�̿��� ��. 
int s[15];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> w;
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}
	
	for(int i=0; i<n-1; i++) {
		if(s[i+1] > s[i]) {
			coins += w / s[i];
			w = w % s[i];
		}
		else if(s[i+1] < s[i]) {
			w += coins * s[i];
			coins = 0;
		}
		else {
			continue;
		}
	}
	w += coins * s[n-1];
	
	cout << w;
}

// greedy
