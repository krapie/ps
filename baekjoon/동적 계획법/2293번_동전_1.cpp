/*
baekjoon 2293��: ���� 1

�ð� ����: 0.5��
�޸� ����: 4 MB

����
n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���. �� ������ ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �� ����� ���� ���Ͻÿ�. ������ ������ �� ���� ����� �� �ִ�.
����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է�
ù° �ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����. ������ ��ġ�� 100,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ����� ���� ����Ѵ�. ����� ���� 231���� �۴�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[10001];
int coin[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	dp[0] = 1; //�������� ��ġ 0�� ����� ����� ��: �ƹ� ������ ���� ���ϴ� ��� 1����


	for (int i = 1; i <= n; i++) //����
	{
		for (int j = coin[i]; j <= k; j++) //��ġ�� ��, coin[i] �̸��� ���������� �߰��� ����� ���� �����Ƿ�, j=coin[i]���� ���� 
		{
			dp[j] += dp[j - coin[i]]; //2���� ��ȭ���� ������
		}
	}

	cout << dp[k];
}

/*
������ȹ��, Bottom-Up, �޸� ���� 4 MB
dp[i][k]: i��°������ ������ �̿��� ��ġ�� ���� k���� ����� ��

��ȭ��
if i��° ���� > k, ���� ��� �Ұ����Ҷ�)
	dp[i][k] = dp[i-1][k]
else (i���� ���� <= k, ���� ��� �����Ҷ�)
	dp[i][k] = dp[i-1][k] (���� ��� ���� ���) + dp[i][k-a[i]] (���� ����� ���)


...�޸� �ʰ�...
cin n k
for n
	cin coin[i]

for n
	dp[i][0] = 1 //i�������� �������� ��ġ 0�� ����� ����� ��: �ƹ� ������ ���� ���ϴ� ��� 1����

for n
	for k
		if coin[i] <= j //i���� ���� <= k, ���� ��� �����Ҷ�
			dp[i][j] = dp[i-1][j] + dp[i][j - coin[i]]
		else //i��° ���� > k, ���� ��� �Ұ����Ҷ�
			dp[i][j] = dp[i - 1][j]

cout dp[n][k]

�޸� ���� -> 2���� �迭�� 1��������

��ȭ��
dp[j]: �������� ���� �� �ִ� ��ġ j�� ����� ��

dp[i][j] = dp[i-1][j] (���� ��� ���� ���) + dp[i][j-a[i]] (���� ����� ���)��
dp[i][] = A, dp[i-1][] = B��� �ϸ�,
A[j] = B[j] + A[j-a[i]] �̰�, B[j] �迭�� �ϼ��� �� A[j] �迭�� �����ϴ� ���·� ����ǹǷ�,
dp[j] += dp[j-coin[i]]

cin n k
for n
	cin coin[i]

for n
	dp[0] = 1 //�������� ��ġ 0�� ����� ����� ��: �ƹ� ������ ���� ���ϴ� ��� 1����

for i 1 to n
	for j coin[i] to k //coin[i] �̸��� ���������� �߰��� ����� ���� �����Ƿ�, j=coin[i]���� ����
		dp[j] += dp[j-coin[i]]

cout dp[k]
*/
