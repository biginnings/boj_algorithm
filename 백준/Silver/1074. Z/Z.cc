#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int r, c, N;
long long result;



void solve() {
    cin >> N >> r >> c;

    result = 0;
    int i = 1;

    while (1) {
        while (1) {
            long long stand = pow(2, i);
            if (stand <= r || stand <= c) {
                i++;
                continue;
            }
            else {
                i--;
                break;
            }
        }

        long long stand = pow(2, i);
        if (stand <= r && stand <= c) {
            result += (stand * stand) * 3;
            r -= stand;
            c -= stand;
            i = 1;
        }
        else if (stand <= c) {
            result += stand * stand;
            c -= stand;
        }
        else if (stand <= r) {
            result += (stand * stand) * 2;
            r -= stand;
        }

        if (r < 2 && c < 2) {
            for (int z = 0; z < 2; z++) {
                for (int j = 0; j < 2; j++) {
                    result++;
                    if (z == r && c == j) {
                        cout << result - 1 << "\n";
                        return;
                    }
                }
            }
            
            break;
        }
    }
}

int main() {
    solve();


    return 0;
}