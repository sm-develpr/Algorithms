//
// Created by Сергей on 03.07.2024.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateBinaryStrings(int N, int K, string str = "") {
    if (N == 0) {
        cout << str << "\n";
        return;
    }
    for (int i = 0; i < K; ++i) {
        generateBinaryStrings(N - 1, K, str + to_string(i));
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    generateBinaryStrings(N, K);
    return 0;
}