#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
    unordered_map<char,int> freq;
    for (char c : s) freq[c]++;

    priority_queue<pair<int,char>> pq;
    for (auto &p : freq) pq.push({p.second, p.first});

    string result = "";
    pair<int,char> prev = {0, '#'};
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        result += cur.second;
        cur.first--;

        if (prev.first > 0)
            pq.push(prev);

        prev = cur;
    }

    for (int i = 1; i < result.size(); i++)
        if (result[i] == result[i-1])
            return "";

    return result;
}

int main() {
    string s;
    cin >> s;

    string ans = reorganizeString(s);

    if (ans == "")
        cout << "IMPOSSIBLE";
    else
        cout << ans;
}
