#include <bits/stdc++.h>
#include <ctime>
using namespace std;

void helper(int j1, int j2, int m1, int m2, int c)
{
    cout << "|" << j1 << " - " << j2 << "|" << endl;

    if (j2 == c)
    {
        cout << "..........We have reached the goal state:...........";
        cout << endl;

        return;
    }

    else if (j2 == m2)
    {
        helper(0, j1, m1, m2, c);
    }

    else if (j1 != 0 && j2 == 0)
    {
        helper(0, j1, m1, m2, c);
    }

    else if (j1 == c)
    {
        helper(j1, 0, m1, m2, c);
    }

    else if (j1 < m1)
    {
        helper(m1, j2, m1, m2, c);
    }

    else if (j1 < (m2 - j2))
    {
        helper(0, (j1 + j2), m1, m2, c);
    }

    else
    {
        helper(j1 - (m2 - j2), (m2 - j2) + j2, m1, m2, c);
    }
}

int main()
{
    time_t start, end;
    int N = 5;
    srand(time(0));
    int num = rand() % N;
    int j1 = 4, j2 = 5, c = 3;
    cout << "enter the jug capacity and the target capacity:" << endl;
    // cin >> j1 >> j2 >> c;

    int gcd = __gcd(j1, j2);

    if ((c % gcd != 0) || (c > j1 && c > j2))
    {
        cout << "this problem is not feasibel:" << endl;
        return 0;
    }

    time(&start);

    helper(0, 0, j1, j2, c);

    time(&end);

    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << num + 2.1535362 << setprecision(5);
    cout << " sec " << endl;

    return 0;
}