#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



bool check_relationship(long int* tree_arr, long int parent,long int child) {
    
    if (tree_arr[child] == -1) {
        if (child == parent) {
            return true;
        }
        return false;
    }
    else {
        if (tree_arr[child] < parent) {
            return false;
        }
        if(tree_arr[child] == parent){
            return true;
        }
        else {
            return check_relationship(tree_arr, parent, tree_arr[child]);
        }
    }

    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long int N = 0, Q = 0;
    cin >> N;

    long int* tree_arr = new long int [1000001];
   
    
    long int parent = 0, child = 0;

    for (long int i = 0; i < N - 1; i++) {
        cin >> parent >> child;

        if (i == 0) {
            tree_arr[parent] = -1;
            tree_arr[child] = parent;
        }
        
        tree_arr[child] = parent;
    }


    cin >> Q;
    long int x = 0, y = 0;
    vector<string> check_arr;

    for (long int i = 0; i < Q; i++) {
        cin >> x >> y;
        
        if (parent == child) {
            check_arr.push_back("YES");
        }
        if (check_relationship(tree_arr, x, y)) {
            check_arr.push_back("YES");
        }
        else{
            check_arr.push_back("NO");
        }

    }

    for (long int i = 0; i < check_arr.size(); i++) {
        cout << check_arr[i]<<"\n";
    }


    delete[] tree_arr;

    return 0;
}