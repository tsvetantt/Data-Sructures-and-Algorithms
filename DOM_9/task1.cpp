#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

string last_dir(string dir) {
    int counter = 0;
    int index_of_seclast = 0;

    string temp;
    for (int i = 0; i < dir.size()-1; i++) {
        if (dir[i] == '/') {
            index_of_seclast = i;
            counter++;
        }
    }
    temp = dir.substr(0, index_of_seclast + 1);

    return temp;
}



int main() {
    int n = 0;
    string temp;
    std::cin >> n;
    cin.ignore();
    vector<string> commands;


    while(n > 0) { 
        getline(cin, temp);
        commands.push_back(temp);
        n--;
    }
    
    unordered_map<string,set<string>> files;
    string current_dir = "/";

    for (int i = 0; i < commands.size();i++) {
        temp = commands[i];
        if (commands[i].find("mkdir", 0) != string::npos) {
            commands[i].erase(0, 6);
            if (files[current_dir].find(commands[i]) == files[current_dir].end()) {
                
                files[current_dir].insert(commands[i]);
            }
            else {
                cout << "Directory already exists\n";
            }
            continue;
        }

        if (commands[i].find("cd", 0) != string::npos) {
            commands[i].erase(0, 3);

            if (commands[i] == "..") {
                if (current_dir == "/") {
                    cout << "No such directory\n";
                }
                else {
                    current_dir = last_dir(current_dir);
                }
                continue;
            }

            if (files[current_dir].find(commands[i]) != files[current_dir].end()) {
                current_dir = current_dir + commands[i] + "/";
                continue;
            }
            else {
                cout << "No such directory\n";
            }
            continue;
        }

        if (commands[i] == "ls") {
            for (auto it = files[current_dir].begin(); it != files[current_dir].end(); ++it) {
                cout << *it << " ";
            }
            cout << "\n";
            continue;
        }

        if (commands[i] == "pwd") {
            cout << current_dir << "\n";
            continue;
        }
    }
    
    return 0;
}
       