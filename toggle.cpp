#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    while (1)
    {

        int m, n, temp, ans = 0, l, i, j, k;

        cin >> n >> k;

        int a[n][n];
        l = pow(2, n + 1);
        cout << l << endl;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        int b[n + 5];

        for (i = 0; i < l; i++)
        {

            int noOfBits = 0;
            for (j = 0; j < n; j++)
                b[j] = 0;
            j = 0;

            temp = i;

            while (temp > 0)
            {
                b[j++] = temp & 1;
                temp = temp >> 1;
            }

            cout << " bits :";
            for (j = 0; j < n; j++)
            {
                cout << b[j];
                noOfBits += b[j];
            }
            cout << "   -> " << noOfBits << " ";
            if ((noOfBits - k) % 2 != 0)
                continue;

            cout << endl;

            for (j = 0; j < n; j++)
            {
                if (b[j] == 1)
                {
                    for (int k1 = 0; k1 < n; k1++)
                    {
                        a[k1][j] = a[k1][j] ^ 1;
                    }
                }
            }

            for (j = 0; j < n; j++)
            {
                cout << endl;
                for (int k1 = 0; k1 < n; k1++)
                {
                    cout << a[j][k1];
                }
            }
            cout << endl;

            int co = 0, f = 0;

            for (j = 0; j < n; j++)
            {
                f = 1;
                for (int k1 = 0; k1 < n; k1++)
                {
                    if (a[j][k1] == 0)
                    {
                        f = 0;
                        break;
                    }
                }
                co += f;
            }
            if (co > ans)
                ans = co;

            for (j = 0; j < n; j++)
            {
                if (b[j] == 1)
                {
                    for (int k1 = 0; k1 < n; k1++)
                    {
                        a[k1][j] = a[k1][j] ^ 1;
                    }
                }
            }

            cout << endl;
        }

        cout << "ans----------->" << ans;
    }
    return 0;
}

/*
3
20
1 0 0
1 0 1
1 0 0

3
1 0 0
0 1 1
1 0 0

*/