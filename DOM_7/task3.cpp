#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int get_ships_that_fit(set<int>& game, int ship_size) {
    int total_ships = 0;
    int start= 1;

    auto start_interval = game.find(0);
    auto end_interval = game.upper_bound(start);

    total_ships += (* end_interval - *start_interval - 1)/ship_size;

    while (end_interval != game.end()) {

        start_interval = end_interval;
        end_interval = game.upper_bound(*start_interval);
        if (end_interval == game.end()) {
            break;
        }
        total_ships += (*end_interval - * start_interval - 1) / ship_size;
       
    }

    return total_ships;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int amount_of_spaces = 0, amount_of_ships = 0, size_of_ship = 0;
    long int amount_of_hits = 0;

    long int temp_hit = 0;

    cin >> amount_of_spaces >> amount_of_ships >> size_of_ship;

    cin >> amount_of_hits;


    set<int> game;
    
    game.insert(0);
    game.insert(amount_of_spaces + 1);

    for (int i = 1; i <= amount_of_hits; i++) {
        cin >> temp_hit;
        game.insert(temp_hit);
        if (get_ships_that_fit(game, size_of_ship) < amount_of_ships) {
            cout << i;
            return 0;
        }
    }

    


    cout << -1;
    return 0;
}
