#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926

int main()
{
    int lines;
    int index = 0;
    cin >> lines;

    while (lines)
    {
        double X;
        double Y;
        double distance;

        cin >> X >> Y;
        if(X == 0.0)
            distance = Y;
        else if (Y == 0.0)
            distance = X;
        else
            distance = sqrt(X * X + Y * Y);

        int i = 1;
        double radius = sqrt(100.0 / PI);
        while (radius < distance)
        {
            ++i;
            radius = sqrt(i * 100.0 / PI);
        }

        index++;
        lines--;

        cout << "Property " << index << ": This property will begin eroding in year " << i << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;

    return 0;
}
