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
    }
 
    cout << endl << "Error" << endl;
    exit(1);
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

int rom_to_dec_opt(const string& str)
{
    int res = 0;
    int s1 = 0;
    int s2 = 0;
    int i = 0;
    int j = 0;
   
    for (i = 0, j = i + 1; i < str.length(); ++i, j = i + 1) {
        s1 = value(str[i]);
        if (j < str.length()) {
            s2 = value(str[j]);
            if (s1 < s2) {
                res += (s2 - s1);
                ++i;
                continue;
            }
        }
        res += s1;
    }
   
    return res;
}


int main()
{
    //string str = "CIX";
    string str = "MCMIV";
    cout << "(0) Rom is " << str << " | " << "Dec is " << rom_to_dec(str) << endl;
    
    string str_tmp = "IIX";
    cout << "(1) Rom is " << str_tmp << " | " << "Dec is " << rom_to_dec_opt(str_tmp) << endl;
    str_tmp = "MCMIV";
    cout << "(2) Rom is " << str_tmp << " | " << "Dec is " << rom_to_dec_opt(str_tmp) << endl;
    str_tmp = "IX";
    cout << "(3) Rom is " << str_tmp << " | " << "Dec is " << rom_to_dec_opt(str_tmp) << endl;

    return 0;
}
