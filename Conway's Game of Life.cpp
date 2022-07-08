#include <iostream>

using namespace std;
int check_alive(int n) {
    if (n == 2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 10;
    int k;
    cout << "Input k: " << endl;
    cin >> k;
    int Arr[N][N];
    int alive = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Arr[i][j] = rand() % 2 + 1;
            if (Arr[i][j] == 1) {
                alive++;
            }
        }
    }
    for (int l = 0; l < k; l++) {
        int change = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int alive_neighbours = 0;
                if (i == 0 && j == 0) {
                    alive_neighbours += check_alive(Arr[i][N - 1]);
                    alive_neighbours += check_alive(Arr[i + 1][N - 1]);
                    alive_neighbours += check_alive(Arr[N - 1][N - 1]);
                    alive_neighbours += check_alive(Arr[i + 1][j]);
                    alive_neighbours += check_alive(Arr[N - 1][0]);
                    alive_neighbours += check_alive(Arr[i][j + 1]);
                    alive_neighbours += check_alive(Arr[i + 1][j + 1]);
                    alive_neighbours += check_alive(Arr[N - 1][j + 1]);
                }

                else if (i == (N - 1) && j == (N - 1)) {
                    alive_neighbours += check_alive(Arr[i - 1][j]);
                    alive_neighbours += check_alive(Arr[i - 1][j + 1]);
                    alive_neighbours += check_alive(Arr[i][j + 1]);
                    alive_neighbours += check_alive(Arr[i][0]);
                    alive_neighbours += check_alive(Arr[i - 1][0]);
                    alive_neighbours += check_alive(Arr[0][0]);
                    alive_neighbours += check_alive(Arr[0][N - 1]);
                    alive_neighbours += check_alive(Arr[0][j - 1]);
                }
                else if (i == (N - 1) && j == 0) {
                    alive_neighbours += check_alive(Arr[i - 1][j]);
                    alive_neighbours += check_alive(Arr[i - 1][j + 1]);
                    alive_neighbours += check_alive(Arr[i][j + 1]);
                    alive_neighbours += check_alive(Arr[0][j]);
                    alive_neighbours += check_alive(Arr[0][j + 1]);
                    alive_neighbours += check_alive(Arr[i][N - 1]);
                    alive_neighbours += check_alive(Arr[i - 1][N - 1]);
                    alive_neighbours += check_alive(Arr[0][N - 1]);
                }
                else if (i == 0 && j == (N - 1)) {
                    alive_neighbours += check_alive(Arr[i + 1][j]);
                    alive_neighbours += check_alive(Arr[i + 1][j - 1]);
                    alive_neighbours += check_alive(Arr[i][j - 1]);
                    alive_neighbours += check_alive(Arr[0][0]);
                    alive_neighbours += check_alive(Arr[1][0]);
                    alive_neighbours += check_alive(Arr[N - 1][j]);
                    alive_neighbours += check_alive(Arr[N - 1][j - 1]);
                    alive_neighbours += check_alive(Arr[N - 1][0]);
                }
                else if (i == 0) {
                    alive_neighbours += check_alive(Arr[i][j + 1]);
                    alive_neighbours += check_alive(Arr[i][j - 1]);
                    alive_neighbours += check_alive(Arr[N - 1][j + 1]);
                    alive_neighbours += check_alive(Arr[N - 1][j]);
                    alive_neighbours += check_alive(Arr[N - 1][j - 1]);
                    alive_neighbours += check_alive(Arr[i + 1][j - 1]);
                    alive_neighbours += check_alive(Arr[i + 1][j]);
                    alive_neighbours += check_alive(Arr[i + 1][j + 1]);
                }
                else if (j == 0) {
                    alive_neighbours += check_alive(Arr[i - 1][j]);
                    alive_neighbours += check_alive(Arr[i + 1][j]);
                    alive_neighbours += check_alive(Arr[i - 1][j + 1]);
                    alive_neighbours += check_alive(Arr[i][j + 1]);
                    alive_neighbours += check_alive(Arr[i + 1][j + 1]);
                    alive_neighbours += check_alive(Arr[i - 1][N - 1]);
                    alive_neighbours += check_alive(Arr[i][N - 1]);
                    alive_neighbours += check_alive(Arr[i + 1][N - 1]);
                }
                else if (i == (N - 1)) {
                    alive_neighbours += check_alive(Arr[i][j + 1]);
                    alive_neighbours += check_alive(Arr[i][j - 1]);
                    alive_neighbours += check_alive(Arr[i - 1][j - 1]);
                    alive_neighbours += check_alive(Arr[i - 1][j]);
                    alive_neighbours += check_alive(Arr[i - 1][j + 1]);
                    alive_neighbours += check_alive(Arr[0][j - 1]);
                    alive_neighbours += check_alive(Arr[0][j]);
                    alive_neighbours += check_alive(Arr[0][j + 1]);
                }
                else if (j == (N - 1)) {
                    alive_neighbours += check_alive(Arr[i - 1][j]);
                    alive_neighbours += check_alive(Arr[i + 1][j]);
                    alive_neighbours += check_alive(Arr[i - 1][j - 1]);
                    alive_neighbours += check_alive(Arr[i][j - 1]);
                    alive_neighbours += check_alive(Arr[i + 1][j - 1]);
                    alive_neighbours += check_alive(Arr[i - 1][0]);
                    alive_neighbours += check_alive(Arr[i][0]);
                    alive_neighbours += check_alive(Arr[i + 1][0]);
                }
                else {
                    alive_neighbours += check_alive(Arr[i - 1][j]);
                    alive_neighbours += check_alive(Arr[i - 1][j - 1]);
                    alive_neighbours += check_alive(Arr[i][j - 1]);
                    alive_neighbours += check_alive(Arr[i][j + 1]);
                    alive_neighbours += check_alive(Arr[i - 1][j + 1]);
                    alive_neighbours += check_alive(Arr[i + 1][j - 1]);
                    alive_neighbours += check_alive(Arr[i + 1][j]);
                    alive_neighbours += check_alive(Arr[i + 1][j + 1]);
                }
                if (Arr[i][j] == 2) {
                    if (!(alive_neighbours == 2 || alive_neighbours == 3)) {
                        Arr[i][j] = 1;
                        alive--;
                        change++;
                    }
                }
                else {
                    if (alive_neighbours == 3) {
                        Arr[i][j] = 2;
                        alive++;
                        change++;
                    }
                }
            }
        }
        if (change == 0) {
            break;
        }
        if (alive == 0) {
            break;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << Arr[i][j] << " ";
            }
            cout << "" << endl;
        }
        cout << " " << endl;
    }
}