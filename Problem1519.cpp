#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int addDigits(int i)
{
    int sum = 0;
    while (i)
    {
        int remainder = i % 10;
        sum += remainder;
        i = i / 10;
    }
    if (sum >= 10)
        addDigits(sum);
    else
        return sum;
}

int main(int argc, char* argv[])
{
    vector<int> data;

    ifstream infile(argv[1]);
    int a;
    while(infile >> a)
    {
        if (a == 0) {
            break;
        }
        data.push_back(a);
    }

    for (int i = 0; i < data.size(); ++i)
    {
        int root = addDigits(data[i]);

        cout << root << endl;
    }

    return 0;
}