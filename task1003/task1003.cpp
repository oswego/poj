#include <iostream>
using namespace std;

float opdata(int data)
{
    if (data == 0)
        return 1.0;
    float result = 1.0 / data;
    return result;
}

int main()
{
    float input;
    while(cin >> input && input >= 0.01 && input <= 5.20)
    {
        float sum = 0.0;
        int i = 2;
        while(sum <= input)
        {
            sum += opdata(i++);
        }

        cout << i - 2 << " card(s)" << endl;
    }

    return 0;
}
