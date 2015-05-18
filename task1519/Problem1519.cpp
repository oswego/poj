#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[2000];
    while(cin >> str && str[0] != '0')
    {
        int i;
        int sum = 0;
        int len = strlen(str);
        for (i = 0; i < len; ++i) {
            sum += str[i] - '0';
        }
        sum %= 9;

        cout << (sum == 0 ? 9 : sum) << endl;
    }

    return 0;
}