//
// Created by Сергей on 03.07.2024.
//
#include <iostream>
#include <string>
using namespace std;

void generateBinaryStrings(int i, int N, int counter, int K, string str = "") {
    if (i >= N) {
        if (counter == K) {
            cout << str << "\n";
        }
        return;
    }
    if (K < counter || N - i < K - counter) {
        return;
    }
    generateBinaryStrings(i + 1, N, counter, K, str + "0");
    generateBinaryStrings(i + 1, N, counter + 1, K, str + "1");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    generateBinaryStrings(0, N, 0, K);
    return 0;
}