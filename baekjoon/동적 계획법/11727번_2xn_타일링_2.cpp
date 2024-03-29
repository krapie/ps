/*
baekjoon 11727��: 2xn Ÿ�ϸ� 2

�ð� ����: 1��
�޸� ����: 256 MB 

����
2��n ���簢���� 1��2, 2��1�� 2��2 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Ʒ� �׸��� 2��17 ���簢���� ä�� �Ѱ��� ���̴�.

�Է�
ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)

���
ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n];
}

/*
����� ��, ������ȹ��
bottom-up

dp[n]: 2xn ���簢���� Ÿ�Ϸ� ä��� ����� ��

��ȭ��
	i���� Ÿ���� ����� �� = i-1���� Ÿ�Ͽ��� 1*2 Ÿ�� �ϳ� ���̱� + i-2��° Ÿ�Ͽ��� 2*1 Ÿ�� �ϳ� OR 2*2 Ÿ�� 2�� ���̴� ���
	dp[i] = dp[i-1] + dp[i-2] * 2
*/
