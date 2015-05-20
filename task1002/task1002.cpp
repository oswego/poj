#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string, int> OccMap;

int main()
{
    int lines;
    cin >> lines;

    OccMap occs;

    int lineno = 0;
    while (lineno < lines)
    {
        string str;
        cin >> str;

        int strLength = str.length();
        string strStandard = "";
        for (int i = 0; i < strLength; i++)
        {
            string s = str.substr(i, 1);
            if (s == "A" || s == "B" || s == "C") {
                strStandard += "2";
            } else if (s == "D" || s == "E" || s == "F") {
                strStandard += "3";
            } else if (s == "G" || s == "H" || s == "I") {
                strStandard += "4";
            } else if (s == "J" || s == "K" || s == "L") {
                strStandard += "5";
            } else if (s == "M" || s == "N" || s == "O") {
                strStandard += "6";
            } else if (s == "P" || s == "R" || s == "S") {
                strStandard += "7";
            } else if (s == "T" || s == "U" || s == "V") {
                strStandard += "8";
            } else if (s == "W" || s == "X" || s == "Y") {
                strStandard += "9";
            } else if (s == "-") {
                strStandard += "";
            } else {
                strStandard += s;
            }

            if (strStandard.length() == 3) {
                strStandard += "-";
            }
        }
        OccMap::iterator it;
        it = occs.find(strStandard);
        if (it == occs.end()) {
            occs.insert(std::make_pair(strStandard, 1));
        } else {
            occs[strStandard]++;
        }
        lineno++;
    }
    size_t occSize = occs.size();

    if (occSize == lines) {
        cout << "No duplicates." << endl;
    } else {
        for (OccMap::iterator it = occs.begin(); it != occs.end(); it++)
        {
            if (it->second == 1)
                continue;
            cout << it->first << " " << it->second << endl;
        }
    }

    return 0;
}
