/*
baekjoon 2869��

�ð� ����: 0.15��
�޸� ����: 128 MB

����
�� ���� �����̰� �ִ�. �� �����̴� ���̰� V������ ���� ���븦 �ö� ���̴�.
�����̴� ���� A���� �ö� �� �ִ�. ������, �㿡 ���� �ڴ� ���� B���� �̲�������. ��, ���� �ö� �Ŀ��� �̲������� �ʴ´�.
�����̰� ���� ���븦 ��� �ö󰡷���, ��ĥ�� �ɸ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� A, B, V�� �������� ���еǾ �־�����. (1 �� B < A �� V �� 1,000,000,000)

���
ù° �ٿ� �����̰� ���� ���븦 ��� �ö󰡴µ� ��ĥ�� �ɸ����� ����Ѵ�. 
*/

#include <iostream>

using namespace std;

int main(void)
{

	int V, A, B;
	cin >> A >> B >> V;

	int cnt = 0;

	//V-A ���� ���� ������ ���� ����
	if ((V - A) % (A - B) == 0) //���� �������� �� �°� �����Ѵٸ�
		cnt = (V - A) / (A - B);
	else //���� �������� ���� ����� �����Ѵٸ� (�Ϸ� �� ���� ������ �̵��ϸ� ������ ����)
		cnt = (V - A) / (A - B) + 1;
		

	cnt++; //������ �̵�
	
	cout << cnt << endl;
}
