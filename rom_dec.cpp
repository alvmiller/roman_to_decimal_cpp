#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/roman-number-to-integer/
// https://www.geeksforgeeks.org/cpp-program-for-converting-roman-numerals-to-decimal-lying-between-1-to-3999/

int value(char r)
{
    switch(r) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return -1;
    }
 
    return -1;
}

int rom_to_dec(const string& str)
{
    int res = 0;
   
    for (int i = 0; i < str.length(); ++i) {
        int s1 = value(str[i]);
        if (i + 1 < str.length()) {
            int s2 = value(str[i + 1]);
            if (s1 >= s2) {
                res += s1;
            }
            else {
                res += (s2 - s1);
                ++i;
            }
        }
        else {
            res += s1;
        }
    }
   
    return res;
}

int main()
{
    //string str = "CIX";
    string str = "MCMIV";
    cout << "(0) Rom is " << str << " | " << "Dec is " << rom_to_dec(str) << endl;

    return 0;
}
