#include <iostream>

using namespace std;

const int max_n = 300000;

int n;
int b[max_n];
int c[max_n];
int a[max_n];
int d[max_n];
int b1[max_n];
int c1[max_n];
int bits[31][max_n];
int kbit[31];

int main()
{
	// input
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++) d[i] = b[i] + c[i];

	// searching for answer
	long long sum = 0;
	for (int i = 0; i < n; i++) sum += d[i];
	sum /= (2 * n);

	for (int i = 0; i < n; i++) a[i] = (d[i] - sum) / n;

	// checking the answer
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
        {
            cout << -1 << endl;
            return 0;
        }
	
	for (int i = 0; i < 31; i++)
		for (int j = 0; j < n; j++)
			if ((a[j] & (1LL << i)) == 0)
				bits[i][j] = 0;
			else
				bits[i][j] = 1;
	for (int i = 0; i < 31; i++)
	{
		kbit[i] = 0;
		for (int j = 0; j < n; j++)
			kbit[i] += bits[i][j];
	}

	for (int i = 0; i < n; i++) b1[i] = 0;
	for (int i = 0; i < n; i++) c1[i] = 0;

	for (int i = 0; i < 31; i++)
		for (int j = 0; j < n; j++)
		{
			int bbase = bits[i][j] ? kbit[i] : 0;
			int cbase = bits[i][j] ? n : kbit[i];
			b1[j] += bbase << i;
			c1[j] += cbase << i;
		} 

	for (int i = 0; i < n; i++)
		if (b1[i] != b[i] || c1[i] != c[i])
		{
			cout << -1 << endl;
			return 0;
		}	

	// output
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}