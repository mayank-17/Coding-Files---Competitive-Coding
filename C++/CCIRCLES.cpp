#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define FORI(s,n) for(int i = s; i < n; i++)
#define FORJ(s,n) for(int j = s; j < n; j++)

using vi = vector<int>;
using vvi = vector<vi>;

void fastscan(int &number)
{
	bool negative = false;
	register int c;

	number = 0;

	c = getchar();
	if (c=='-')
	{
		negative = true;
		c = getchar();
	}

	// Keep on extracting characters if they are integers
	// i.e ASCII Value lies from '0'(48) to '9' (57)
	for (; (c>47 && c<58); c=getchar())
		number = number *10 + c - 48;

	// if scanned input has a negative sign, negate the
	// value of the input number
	if (negative)
		number *= -1;
}

double dist(int a, int b, int c, int d) {
   return sqrt(pow(a - c, 2) + pow(b - d, 2));
}

void calculate_circle_distances(int n, vvi&v, vector<double>& beg, std::vector<double> &end) {
   int idx = 0;
   FORI(0, n) {
      FORJ(i + 1, n) {
         int x1 = v[i][0], y1 = v[i][1], r1 = v[i][2];
         int x2 = v[j][0], y2 = v[j][1], r2 = v[j][2];
         auto d = dist(x1, y1, x2, y2);
         double a, b;
         if (d > r1 + r2) {
            a = d - r1 - r2;
            b = d + r1 + r2;
         } else if (d < abs(r1 - r2)) {
            if (r1 < r2) a = r2 - d - r1, b = 2 * r2 - a;
            else         a = r1 - d - r2, b = 2 * r1 - a;
         } else {
            a = 0;
            b = r1 + r2 + d;
         }
         beg[idx] = a;
         end[idx] = b;
         idx++;
      }
   }

   sort(beg.begin(), beg.end());
   sort(end.begin(), end.end());
}

int main() {
      int n, q;
//      cin >> n >> q;
      fastscan(n);
      fastscan(q);
      vvi v(n, vi(3));
      FORI(0, n) {
         fastscan(v[i][0]);
         fastscan(v[i][1]);
         fastscan(v[i][2]);
      }
//      cin >> v[i][0] >> v[i][1] >> v[i][2];

      vector<double> beg((n*(n - 1)) / 2), end((n*(n - 1)) / 2);

      calculate_circle_distances(n, v, beg, end);

      while (q--) {
         int k;
//         cin >> k;
         fastscan(k);
         int started  = distance(beg.begin(), upper_bound(beg.begin(), beg.end(), k));
         int finished = distance(end.begin(), lower_bound(end.begin(), end.end(), k));
         cout << started - finished << endl;
      }

      return 0;
   }
