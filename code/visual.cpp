#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
using namespace std;

#pragma GCC optimize("O2")

#define _9trash no bug
#define ll long long
#define pb push_back

void io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// -------------------------------------------------------------

#define MAXN 100000
#define MAXDEPTH 100

vector<int> g[MAXN], depth[MAXDEPTH];
wstring dir, shape;

void readSetting() {
    wcin >> dir >> shape;
}

void readTree() {
    vector<int> cur(MAXDEPTH);
    int id = 0;
    wstring str;
    while (getline(wcin, str)) {
        if (str.size() == 0)
            continue;

        int cnt = 0, index = 0;
        bool fill = 0;
        wstring color;
        while (1) {
            // cout << index << ":" << (int)(str[index]) << " ";
            // index++;
            if (index >= str.size() || (str[index] != 32 && str[index] != 226 && str[index] != 194 && str[index] != '-'))
                break;
            if (str[index] == 226)
                index += 3;
            else if (str[index] == 194)
                index += 2;
            else if (str[index] == 32)
                index += 1;
            else if (str[index] == '-') {
                fill = 1;
                int tempCnt = 1;
                while (str[index + tempCnt] != 32)
                    tempCnt++;
                color = str.substr(index + 1, tempCnt - 1);
                index += tempCnt;
                break;
            }
            cnt++;
        }
        // wcout << str << "\n";

        wcout << L"        " << id << L" [label=\"" << str.substr(index) << L"\"";
        if (fill)
            wcout << L" fillcolor=\"" << color << L"\" style=filled";
        wcout << L"]\n";

        cur[cnt / 4] = id;
        if (cnt / 4 != 0)
            g[cur[cnt / 4 - 1]].pb(cur[cnt / 4]);
        depth[cnt / 4].pb(id);
        id++;
    }
}

void printEdge() {
    for (int i = 0; i < MAXN; i++)
        if (g[i].size() != 0) {
            wcout << L"    " << i << L" -> {";
            for (int j = 0; j < g[i].size(); j++) {
                wcout << g[i][j];
                if (j < g[i].size() - 1)
                    wcout << L", ";
            }
            wcout << L"}\n";
        }
}

void printDepth() {
    for (int i = 0; i < MAXDEPTH; i++)
        if (depth[i].size() != 0) {
            wcout << L"    {rank=same;";
            for (int j = 0; j < depth[i].size(); j++)
                wcout << L" " << depth[i][j] << L";";
            wcout << L"}\n";
        }
}

void printCode() {
    readSetting();
    wcout << L"digraph G {\n"
          << L"    graph [rankdir=" << dir << L"];\n"
          << L"    node [height=1.0 width=1.0 shape=" << shape << L"];\n"
          << L"    {\n";
    readTree();
    wcout << L"    }\n";
    printEdge();
    printDepth();
    wcout << L"}\n";
}

signed main() {
    // io();
    printCode();

    return 0;
}