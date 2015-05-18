#include <iostream>
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

int main()
{
    int rows, columns, ep;
    while(true)
    {
        cin >> rows >> columns >> ep;
        if (rows == 0)
            break;

        char str[columns];
        char grid[rows][columns];
        
        for(int i = 0; i < rows; ++i)
        {
            cin >> str;
            for(int j = 0; j < columns; ++j)
            {
                grid[i][j] = str[j];
            }
        }

        printOut((char**)grid, rows, columns);

        char currentCell = grid[0][ep - 1];
        int currentRow = 1;
        int currentColumn = ep;
        bool passed = false;
        int steps = 0;

        //#define if (currentRow < 0 || currentRow >= rows || currentColumn < 0 || currentColumn >= columns) { passed = true; } PASS_CHECK

        while(!passed)
        {
            switch(currentCell)
            {
                case('E'):
                    currentRow += 0;
                    currentColumn += 1;
                    if(currentRow <= 0 ||
                       currentRow >= rows ||
                       currentColumn <= 0 ||
                       currentColumn >= columns) {
                        passed = true;
                    } else {
                        currentCell = grid[currentRow - 1][currentColumn - 1];
                    }
                    break;
                case('S'):
                    currentRow += 1;
                    currentColumn += 0;
                    if(currentRow <= 0 ||
                       currentRow >= rows ||
                       currentColumn <= 0 ||
                       currentColumn >= columns) {
                        passed = true;
                    } else {
                        currentCell = grid[currentRow - 1][currentColumn - 1];
                    }
                    break;
                case('W'):
                    currentRow += 0;
                    currentColumn += -1;
                    if(currentRow <= 0 ||
                       currentRow >= rows ||
                       currentColumn <= 0 ||
                       currentColumn >= columns) {
                        passed = true;
                    } else {
                        currentCell = grid[currentRow - 1][currentColumn - 1];
                    }
                    break;
                case('N'):
                    currentRow += -1;
                    currentColumn += 0;
                    if(currentRow <= 0 ||
                       currentRow >= rows ||
                       currentColumn <= 0 ||
                       currentColumn >= columns) {
                        passed = true;
                    } else {
                        currentCell = grid[currentRow - 1][currentColumn - 1];
                    }
                    break;
                default:

                steps++;
            }
        }

        cout << steps << " step(s) to exit" << endl;
    }

    return 0;
}
