//
// Created by Сергей on 03.07.2024.
//
#include <iostream>
#include <string>
using namespace std;

void generateBinaryStrings(int N, string str = "") {
    if (N == 0) {
        cout << str << "\n";
        return;
    }
    generateBinaryStrings(N - 1, str + "0");
    generateBinaryStrings(N - 1, str + "1");
}

int main() {
    int N;
    cin >> N;
    generateBinaryStrings(N);
    return 0;
}