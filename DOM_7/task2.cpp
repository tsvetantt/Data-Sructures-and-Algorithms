#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;



int main() {
    
    long int N = 0, Q = 0;
    long int temp = 0;

    long int max_total = 0;

    long int first_index_of_subarr = 0;
    long int index_of_repeating_num = 0;

    vector<int> res;
    
    cin >> Q;
    for (long int j = 0; j < Q; j++) {
        cin >> N;
        map<long int, long int> table;

        first_index_of_subarr = 0;
        max_total = 0;

        for (long int i = 0; i < N; i++) {
            cin >> temp;
           
            
            if (table.count(temp)) {  
                index_of_repeating_num = table.find(temp)->second;
                if (first_index_of_subarr <= index_of_repeating_num) {
                    first_index_of_subarr = ++index_of_repeating_num;
                    auto itr = table.find(temp);
                    itr->second = i;
                }
                else {
                    table.erase(temp);
                    table.insert({ temp, i });
                }
            }
            else{
                table.insert({ temp, i });
            }

            max_total = max(max_total, (i - first_index_of_subarr + 1));
        }

        res.push_back(max_total);
       
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }

    return 0;
}
