#include <bits/stdc++.h>

using namespace std;

void add(int A[], int &Aend, int B[], int &Bend, int L1, int L2) {
    int i, d, c = 0;
    for(i = L1; i < L2; i++) {
        A[i] = 0;
    }
    for(i = L2; i < L1; i++) {
        B[i] = 0;
    }
    for(i = 0; i < L1 || i < L2; i++) {
        d = A[i] + B[i] + c;
        c = d / 10;
        d %= 10;
        A[i] = d;
    }
    while(c) {
        A[i] = c % 10;
        c /= 10;
        i++;
    }
    A[i]=-1;
    B[L2]=-1;
    Aend = i;
    Bend = L2;
}

void subs(int *A, int &Aend, int *B, int &Bend, int L1, int L2) {
     int i, d, c=0;
     for(i = L2; i < L1; i++) {
        B[i] = 0;
     }
     for(i = 0; i < L1; i++) {
          d = A[i] - c - B[i];
          if(d < 0) {
               d += 10;
               c = 1;
          } else {
              c=0;
          }
          A[i] = d;
     }
     B[L2] = -1;
     Bend = L2;
     i = L2-1;
     while(i > 0 && A[i] == 0) {
        i--;
     }
     A[i+1] = -1;
     Aend = i+1;
}

int divide(int A[], int q, int L, int &Aend) {
     int i;
     int c = 0, d;
     for(i = L - 1; i >= 0; i--) {
          d = c * 10 + A[i];
          c = d % q;
          d /= q;
          A[i] = d;
     }
     i=L-1;
     while(i > 0 && A[i] == 0 ) {
        i--;
     }
     A[i+1] = -1;
     Aend = i + 1;
     return c;
}

void makeArray(string a, int *arr) {
    for(int i = 0; i < a.size(); i++) {
        arr[i] = a[i] - '0';
    }
}

int main() {
    int *A = new int[102] {0};
    int *B = new int[102] {0};
    string a, b;
    int t = 10, Aend = 0, Bend = 0;
    while(t--) {

        /*Inputing numbers as strings*/

        getline(cin, a);
        getline(cin, b);

        int L1 = a.size();
        int L2 = b.size();

        /*Make integer array*/
        makeArray(a, A);
        makeArray(b, B);

        /*We can apply the above functions only if the numbers are represented in reverse manner*/
        reverse(A, A + L1);
        reverse(B, B + L2);

        /*Adding both numbers*/
        add(A, Aend, B, Bend, L1, L2);

        L1 = Aend;
        L2 = Bend;
//        for(int i = Aend - 1; i > -1; i--) {
//            cout << A[i];
//        }
//        cout << endl;

        /*we divide to get one answer*/
        divide(A, 2, L1, Aend);
        for(int i = Aend - 1; i > -1; i--) {
            cout << A[i];
        }
        cout << endl;

        /*To calculate further, we need to again reverse the number*/

        makeArray(a, B);
        L1 = a.size();
        reverse(B, B + L1);
//        cout << "another" << endl;
//        for(int i = L1 - 1; i > -1; i--) {
//            cout << B[i];
//        }
//        cout << endl;
//        for(int i = Aend - 1; i > -1; i--) {
//            cout << A[i];
//        }
//        cout << endl;
        L2 = Aend;
        Aend = 0, Bend = 0;
        subs(B, Bend, A, Aend, L1, L2);
        for(int i = Bend - 1; i > -1; i--) {
            cout << B[i];
        }
        cout << endl;
     }
     return 0;
}
