/*
baekjoon 20117��: ȣ�ݿ� ������ �̻��� ǰ�� ����

�ð� ����: 1��
�޸� ����: 256 MB

����
��ϴ� Ư��ǰ ȣ�ݿ�� ǰ���� ���� ����� ���ڷ� �Ű�����. ȣ�ݿ� ���ε��� N���� ȣ�ݿ츦 �ķ��� �Ѵ�. ȣ�ݿ�� ���������� �� ���� ������ �������� �� ���� �ִ�. �� �� �����̶� ���� ȣ�ݿ���� � �κ������� ���Ѵ�.
�ϳ��� ȣ�ݿ츦 �� �� ������ �������δ� ǰ����ŭ�� �������� �ȸ��� �ȴ�.
���� �����ĳ� ���������� �ĳ� ������ �� �� �ִ� �� �ݾ��� ���̰� ������.
������ ȣ�ݿ� ���ε��� ������̿��� ���� �� ���� ���� ����� ���� ȸ�Ǹ� ���� �ȴ�. �׷��� ���� ȣ�ݿ� ���ε��� ���ο� ǰ�� ������ �����س´�!
ȣ�ݿ츦 �������� �� ���� ��� ȣ�ݿ��� ǰ���� ������ '�߾Ӱ�'���� �����ϰ� �ȴ�. �� �� ������ ¦���� ��� ���� �ȿ� �ִ� ȣ�ݿ츦 ǰ���� �������� �������� �� (���� ����/2+1)��° ȣ�ݿ츦 �߾Ӱ����� �����ϰ� Ȧ���� ��� ((���� ����+1)/2)��° ȣ�ݿ츦 �߰������� �����Ѵ�.
������ ���� ����� ���� ���������� ȣ�ݿ찡 �ʹ� ���� ��� ����� �� �� ȥ���� ���� ������ ȣ�ݿ� ���ε��� ��翡�� �ִ��� ������ ���� �� �ϰ� �־���. ȣ�ݿ� ���ε��� ���� ȣ�ݿ���� �ȾƼ� ���� �� �ִ� �ִ� ������ ����ϴ� ���α׷��� ���������!

�Է�
ù ��° �ٿ� ȣ�ݿ��� ���� N (1 �� N �� 100,000)�� �־����ϴ�.
�� ��° �ٿ� �������� ���е� N���� ���� a1, a2, ..., an (1 �� ai �� 1,000)�� �־����µ� �� ���ڴ� �� ȣ�ݿ��� ǰ���� ��Ÿ���ϴ�.

���
��� ȣ�ݿ츦 �Ⱦ��� �� ���� �� �ִ� �ִ� ������ ����մϴ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[100000];
int mid;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	sort(arr+0, arr+n);
	
	for(int i=n-1; i>=n/2; i--) {
		ans += arr[i] * 2;
	}
	
	if(n % 2 != 0) {
		ans -= arr[n/2];
	}
	
	cout << ans;
}

/*
greedy

���� ������ 2�� ��� ǰ���� ������ �ִ��� �ǹǷ�,
��� ȣ�ݿ츦 �������� ���� �� ������� ���� ���� ���� ���� ���� ������ ���� ���´�, 
�׷��� ������ �׻� �ִ��� �ǹǷ�, �׸����ϰ� �ִ��� ���� �� �ִ�.
ȣ�ݿ찡 Ȧ������ ��� �߾Ӱ��� �ϳ� �� �ָ� ��. 
*/
