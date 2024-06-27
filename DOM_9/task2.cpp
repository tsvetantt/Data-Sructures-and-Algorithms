#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

void printChildDirs(string& s, unordered_map<string, set<string>>& fs) {
    for (auto& dir : fs[s]) {
        cout << dir << " ";
    }
    if (fs[s].size() != 0) {
        cout << endl;
    }
}


bool isDirChild(string& s, string& c, unordered_map<string, set<string>>& fs) {
    for (auto& dir : fs[s]) {
        if (!dir.compare(c)) {
            return true;
        }
    }
    return false;
}

string getParent(string s, long size) {
    string a = "";
    for (long i = s.size() - (3 + size); i >= 0; --i) {
        if (s[i] == '/') {
            return a;
        }
        a.push_back(s[i]);
    }
    return "/";
}


int main() {
    unordered_map<string, set<string>> filesystem;
    unordered_map<string, string> pwds;
    filesystem["/"] = set<string>();
    pwds["/"] = "/";
    string cmd, dir, currentDir;
    currentDir = "/";
    int N = 0;
    cin >> N;
    while (N--) {
        cin >> cmd;
        if (!cmd.compare("mkdir")) {
            cin >> dir;
            if (filesystem[currentDir].find(dir) != filesystem[currentDir].end()) {
                cout << "Directory already exists\n";
            }
            else {
                filesystem[currentDir].insert(dir);
                pwds[dir] = pwds[currentDir] + dir + "/";
            }
        }
        else if (!cmd.compare("ls")) {
            printChildDirs(currentDir, filesystem);
        }
        else if (!cmd.compare("pwd")) {
            cout << pwds[currentDir] << endl;
        }
        else if (!cmd.compare("cd")) {
            cin >> dir;
            if (!dir.compare("..")) {
                if (!currentDir.compare("/")) {
                    cout << "No such directory\n";
                }
                currentDir = getParent(pwds[currentDir], currentDir.size());
            }
            else if (isDirChild(currentDir, dir, filesystem)) {
                currentDir = dir;
            }
            else {
                cout << "No such directory\n";
            }
        }
        else {
            return 1;
        }
    }
}