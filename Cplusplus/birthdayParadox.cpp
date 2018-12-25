#include <bits/stdc++.h>

using namespace std;

int main() {

    // Compute the number of ppl such that

    float num = 365;
    float denom = 365;

    // p denotes the prob of some ppl having bday on same day
    float p = 1;

    // n denotes the number of people needed
    int n = 0;

    while(p > 0.5) { // p becomes less than 0.5 beacause we are starting from 1
        p *= num/denom;
        num--;
        n++;
        cout << "Probability is " << p << " and " << "no of people are " << n << endl;
    }
    return 0;
}

