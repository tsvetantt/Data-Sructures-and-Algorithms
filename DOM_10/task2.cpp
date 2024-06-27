#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

unordered_map<char, bool> visited;
stack<char> ans;

void answer(map<char, queue<char>>& graph, char node) {
	if (visited[node] == true) return;

	visited[node] = true;
	char temp;
	while (!graph[node].empty()) {
		temp = graph[node].front();
		graph[node].pop();
		answer(graph, temp);
	}
	ans.push(node);
}

int main() {
	int n = 0;
	string temp_word, prev_word;
	map<char, queue<char>> graph;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp_word;
		for (char c : temp_word) {
			graph[c];
			visited[c] = false;
		}
		if (i == 0) {
			prev_word = temp_word;
			continue;
		}
		for (int j = 0; j < min(temp_word.size(), prev_word.size()); j++) {
			if (temp_word[j] != prev_word[j]) {
				graph[prev_word[j]].push(temp_word[j]);
				break;
			}
		}
		prev_word = temp_word;
	}

	for (auto letter : graph) {
		if (!visited[letter.first]) {
			answer(graph, letter.first);
		}
	}

	while(!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}
