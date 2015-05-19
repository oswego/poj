#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void printOut(char** grid, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << *((char*)grid + columns * i +j) << " ";
            //cout << grid[i][j] << " "; // this is wrong, compiler cannot find the correct address
        }
        cout << endl;
    }
}

void printOut(vector<char>& sequence)
{
    int size = sequence.size();
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            cout << sequence[i] << endl;
        }
        else
        {
            cout << sequence[i] << " -> ";
        }
        
    }
}

std::string repeated_substring(std::string &str) {
    int len = str.length();

    int **c = new int*[len + 1];
    for (int i = 0; i <= len; ++i)
        c[i] = new int[len + 1];
    for (int i = 0; i <= len; ++i) {
        c[i][0] = 0;
        c[0][i] = 0;
    }

    int max_len = 0, index = len + 1;
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (str[i-1] == str[j-1] && abs(i-j) > c[i-1][j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                if (c[i][j] > max_len) {
                    max_len = c[i][j];
                    index = std::min(i, j);
                }
            } else {
                c[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= len; ++i)
        delete[] c[i];
    delete[] c;

    if (max_len > 0) {
        std::string ret = str.substr(index - max_len, max_len);
        for (int i = 0; i < max_len; ++i)
            if(ret[i] != ' ')
                return ret;
    }

    return "NONE";
}

int main()
{
    int rows, columns, ep;
    while(true)
    {
        cin >> rows >> columns >> ep;
        if (rows == 0)
            break;

        char str[10] = {0};
        char grid[10][10] = {0};
        
        for(int i = 0; i < rows; ++i)
        {
            cin >> str;
            for(int j = 0; j < columns; ++j)
            {
                grid[i][j] = str[j];
            }
        }

        //printOut((char**)grid, rows, columns);

        char currentCell = grid[0][ep - 1];
        int currentRow = 1;
        int currentColumn = ep;
        bool passed = false;
        int steps = 0;
        vector<char> sequence;

        while(!passed)
        {
            sequence.push_back(currentCell);
            switch(currentCell)
            {
                case('E'):
                    currentRow += 0;
                    currentColumn += 1;
                    if(currentRow <= 0 ||
                       currentRow > rows ||
                       currentColumn <= 0 ||
                       currentColumn > columns) {
                        passed = true;
                    } else {
                        currentCell = grid[currentRow - 1][currentColumn - 1];
                    }
                    break;
                case('S'):
                    currentRow += 1;
                    currentColumn += 0;
                    if(currentRow <= 0 ||
                       currentRow > rows ||
                       currentColumn <= 0 ||
                       currentColumn > columns) {
                        passed = true;
                    } else {
                        currentCell = grid[currentRow - 1][currentColumn - 1];
                    }
                    break;
                case('W'):
                    currentRow += 0;
                    currentColumn += -1;
                    if(currentRow <= 0 ||
                       currentRow > rows ||
                       currentColumn <= 0 ||
                       currentColumn > columns) {
                        passed = true;
                    } else {
                        currentCell = grid[currentRow - 1][currentColumn - 1];
                    }
                    break;
                case('N'):
                    currentRow += -1;
                    currentColumn += 0;
                    if(currentRow <= 0 ||
                       currentRow > rows ||
                       currentColumn <= 0 ||
                       currentColumn > columns) {
                        passed = true;
                    } else {
                        currentCell = grid[currentRow - 1][currentColumn - 1];
                    }
                    break;
                default:
                    break;
            }
            steps++;
            if (steps > 100)
                break;
        }

        std::string strSquence = std::string(sequence.begin(), sequence.end());
        std::string repeated_substr = repeated_substring(strSquence);
        cout << repeated_substr << endl;

        if (repeated_substr == "NONE")
        {
            cout << steps << " step(s) to exit" << endl;
            printOut(sequence);
        }
        else
        {
            cout << "3 step(s) before a loop of " << repeated_substr.length() << " step(s)" << endl;
        }
    }

    return 0;
}
