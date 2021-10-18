/*
BOJ 3613번: Java vs C++

시간 제한: 1초
메모리 제한: 128 MB

문제
Java 예찬론자 김동규와 C++ 옹호가 김동혁은 서로 어떤 프로그래밍 언어가 최고인지 몇 시간동안 토론을 하곤 했다. 동규는 Java가 명확하고 에러가 적은 프로그램을 만든다고 주장했고, 동혁이는 Java는 프로그램이 느리고, 긴 소스 코드를 갖는 점과 제네릭 배열의 인스턴스화의 무능력을 비웃었다.
또, 김동규와 김동혁은 변수 이름을 짓는 방식도 서로 달랐다. Java에서는 변수의 이름이 여러 단어로 이루어져있을 때, 다음과 같은 방법으로 변수명을 짓는다. 
첫 단어는 소문자로 쓰고, 다음 단어부터는 첫 문자만 대문자로 쓴다. 또, 모든 단어는 붙여쓴다. 따라서 Java의 변수명은 javaIdentifier, longAndMnemonicIdentifier, name, bAEKJOON과 같은 형태이다.
반면에 C++에서는 변수명에 소문자만 사용한다. 단어와 단어를 구분하기 위해서 밑줄('_')을 이용한다. C++ 변수명은 c_identifier, long_and_mnemonic_identifier, name, b_a_e_k_j_o_o_n과 같은 형태이다.
이 둘의 싸움을 부질없다고 느낀 재원이는 C++형식의 변수명을 Java형식의 변수명으로, 또는 그 반대로 바꿔주는 프로그램을 만들려고 한다. 각 언어의 변수명 형식의 위의 설명을 따라야 한다.
재원이의 프로그램은 가장 먼저 변수명을 입력으로 받은 뒤, 이 변수명이 어떤 언어 형식인지를 알아내야 한다. 그 다음, C++형식이라면 Java형식으로, Java형식이라면 C++형식으로 바꾸면 된다. 만약 C++형식과 Java형식 둘 다 아니라면, 에러를 발생시킨다. 변수명을 변환할 때, 단어의 순서는 유지되어야 한다.
재원이는 프로그램을 만들려고 했으나, 너무 귀찮은 나머지 이를 문제를 읽는 사람의 몫으로 맡겨놨다.
재원이가 만들려고 한 프로그램을 대신 만들어보자.

입력
첫째 줄에 변수명이 주어진다. 영어 알파벳과 밑줄('_')로만 이루어져 있고, 길이는 100을 넘지 않는다.

출력
입력으로 주어진 변수명이 Java형식이면, C++형식으로 출력하고, C++형식이라면 Java형식으로 출력한다. 둘 다 아니라면 "Error!"를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s;
int cnt;
bool java, c_plus, error;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	java = true; c_plus = true; error = false;
	for(int i=0; i<s.size(); i++) {
		if(s[0] >= 'A' && s[0] <= 'Z') {
			java = false;
		}
		if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
			java = false;
		}
	}
	
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '_') {
			cnt++;
		}
		if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] == '_'))) {
			c_plus = false;
		}
		if(i > 1 && (s[i] == '_' && s[i-1] == '_')) {
			c_plus = false;
		}
	}
	
	// error check	
	if(s[0] == '_' || s[s.size()-1] == '_') error = true;
	if(!java && !c_plus) error = true;
	
	
	if(error) {
		cout << "Error!";
	}
	else {
		if(java && c_plus) {
			cout << s;
		}
		else if(java) {
			int prev_idx = 0;
			for(int i=0; i<s.size(); i++) {
				if(s[i] >= 'A' && s[i] <= 'Z') {
					string word = s.substr(prev_idx, i-prev_idx);
					
					if(prev_idx != 0)
						word[0] = word[0] - 'A' + 'a';
					
					cout << word << "_";
					prev_idx = i;
				}
			}
			string word = s.substr(prev_idx,s.size()-prev_idx);
			word[0] = word[0] - 'A' + 'a';
			cout << word;
		}
		else {
			int prev_idx = 0;
			for(int i=0; i<s.size(); i++) {
				if(s[i] == '_') {
					string word = s.substr(prev_idx, i-prev_idx);
					
					if(prev_idx != 0)
						word[0] = word[0] - 'a' + 'A';
					
					cout << word;
					prev_idx = i+1;
				}
			}
			string word = s.substr(prev_idx,s.size()-prev_idx);
			word[0] = word[0] - 'a' + 'A';
			cout << word;
		}		
	}

}

/*
string, many exceptions
*/
