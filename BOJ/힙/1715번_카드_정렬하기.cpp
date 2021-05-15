/*
BOJ 1715번: 카드 정렬하기

시간 제한: 2초
메모리 제한: 128 MB

문제
정렬된 두 묶음의 숫자 카드가 있다고 하자. 각 묶음의 카드의 수를 A, B라 하면 보통 두 묶음을 합쳐서 하나로 만드는 데에는 A+B 번의 비교를 해야 한다. 이를테면, 20장의 숫자 카드 묶음과 30장의 숫자 카드 묶음을 합치려면 50번의 비교가 필요하다.
매우 많은 숫자 카드 묶음이 책상 위에 놓여 있다. 이들을 두 묶음씩 골라 서로 합쳐나간다면, 고르는 순서에 따라서 비교 횟수가 매우 달라진다. 예를 들어 10장, 20장, 40장의 묶음이 있다면 10장과 20장을 합친 뒤, 합친 30장 묶음과 40장을 합친다면 (10 + 20) + (30 + 40) = 100번의 비교가 필요하다. 그러나 10장과 40장을 합친 뒤, 합친 50장 묶음과 20장을 합친다면 (10 + 40) + (50 + 20) = 120 번의 비교가 필요하므로 덜 효율적인 방법이다.
N개의 숫자 카드 묶음의 각각의 크기가 주어질 때, 최소한 몇 번의 비교가 필요한지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100,000) 이어서 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다. 숫자 카드 묶음의 크기는 1,000보다 작거나 같은 양의 정수이다.

출력
첫째 줄에 최소 비교 횟수를 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int a, b, n;
int num;
priority_queue<int, vector<int>,greater<int>> pq;
int result, ans;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		pq.push(num);
	}

	while (pq.size() != 1)
	{
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		result = a + b;
		
		ans += result;
		pq.push(result);
	}

	cout << ans;
}

/*
최소 => 항상 가장 작은 카드 묶음 2개를 뽑아서 합쳐야 함
ex) 4,5,6,7,8의 경우, 4,5 먼저 뽑고 합치면 9가 되는데, 이 때 단순히 9와 6을 합치는 것(15)보다 6과 7을 합칠때(13) 결과적으로 더 작은 비교횟수가 나오고, 결과적으로 less로 정렬해서 앞에 2개씩 합쳐서 계산한 값: 9+15+22+30보다 항상 순열에서 가장 작은 2개의 수를 뽑은 뒤 합쳐서 계산한 값: 9+13+17+30이 더 작음

순열에서 항상 가장 작은 카드 묶음 2개를 뽑기 => 최소 힙 (단순히 벡터에 넣고 매 연산마다 시간복잡도 O(nlogn)인 sort를 하면 총 시간복잡도: O((nlogn)!)으로 시간초과, 매 연산마다 힙을 삭제하고 추가할때의 시간복잡도는 O((logn)!)으로 벡터 sort보다 훨씬 빠름

cin n
for n
	cin num
	priority_queue greater<int>, push num

//힙에서 루트 노드(가장 작은 카드 묶음) 2개 뽑기
//뽑아서 더한 값 result를 ans += 한 후, 다시 힙에 넣기
//힙이 빌때까지 연산

while  pq size != 1 //큐에 하나만 남음 = 모두 연산함
	a = pq front pop
	b = pq front pop

	result = a +b
	ans += result

	pq push result

cout result
*/
