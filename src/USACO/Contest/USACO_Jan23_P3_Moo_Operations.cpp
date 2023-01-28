#include "CommonHeader.h"

#ifdef USACO_JAN23_P3_MOO_OPERATIONS
READ_INPUT(USACO_JAN23_P3_MOO_OPERATIONS)

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string s;
        cin >> s;

        if (s.length() < 3)
        {
            cout << -1 << endl;
            continue;
        }

        bool MOO = 0, OOO = 0, MOM = 0, OOM = 0;
        for (int i = 0; i <= (s.length() - 3); ++i)
        {
            if (s[i] == 'M' && s[i + 1] == 'O' && s[i + 2] == 'O')
                MOO = 1;
            else if (s[i] == 'M' && s[i + 1] == 'O' && s[i + 2] == 'M')
                MOM = 1;
            else if (s[i] == 'O' && s[i + 1] == 'O' && s[i + 2] == 'M')
                OOM = 1;
            else if (s[i] == 'O' && s[i + 1] == 'O' && s[i + 2] == 'O')
                OOO = 1;
        }

        if (MOO)
            cout << (s.length() - 3) << endl;
        else if (MOM || OOO)
            cout << (s.length() - 2) << endl;
        else if (OOM)
            cout << (s.length() - 1) << endl;
        else
            cout << -1 << endl;
    }
}
#endif
