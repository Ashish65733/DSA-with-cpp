#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

// Leetcode problem 127: Word Ladder

using namespace std;

bool isOneLetterDiff(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return 0;

    // Add beginWord to wordList for graph building
    wordList.push_back(beginWord);

    // Step 1: Build the graph (adjacency list)
    unordered_map<string, vector<string>> adj;
    for (int i = 0; i < wordList.size(); i++) {
        for (int j = i + 1; j < wordList.size(); j++) {
            if (isOneLetterDiff(wordList[i], wordList[j])) {
                adj[wordList[i]].push_back(wordList[j]);
                adj[wordList[j]].push_back(wordList[i]);
            }
        }
    }

    // Step 2: BFS from beginWord
    queue<pair<string, int>> q;
    unordered_set<string> vis;

    q.push({beginWord, 1});
    vis.insert(beginWord);

    while (!q.empty()) {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        if (word == endWord) return level;

        for (const string& nei : adj[word]) {
            if (!vis.count(nei)) {
                vis.insert(nei);
                q.push({nei, level + 1});
            }
        }
    }
    return 0;  // If no path found
}

int main() {
    string beginWord = "aws";
    string endWord = "aaa";
    vector<string> wordList = {"awg", "dws", "dwt", "aag", "dag", "dat", "aaa"};

    int result = ladderLength(beginWord, endWord, wordList);
    cout << "Minimum steps = " << result << endl;
    return 0;
}
