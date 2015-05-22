#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    double sum = 0.0;
    while(i < 12)
    {
        double n;
        cin >> n;
        sum += n;
        i++;
    }
    cout << "$" << sum / 12.0 << endl;

    return 0;
}
