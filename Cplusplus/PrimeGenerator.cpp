#include<iostream>
#include<stdio.h>
using namespace std;

void fastscan(long int &number)
{
	//variable to indicate sign of input number
	bool negative = false;
	register int c;

	number = 0;

	// extract current character from buffer
	c = getchar();
	if (c=='-')
	{
		// number is negative
		negative = true;

		// extract the next character from the buffer
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

int main() {

	long int t;
//	cin >> t;
	fastscan(t);
    while(t--)
    {
        long int m,n;
//        cin>>m>>n;
        fastscan(m);
        fastscan(n);
        if(m==1)
        m=2;
        int i,j,flag;
        for(i=m;i<=n;i++)
        {flag=0;
            for(j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                cout << i << endl;
            }
        }
        cout<<endl;
    }
}
