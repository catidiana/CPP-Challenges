#include <iostream>

using namespace std;

void ReverseString(string& s)
{
    int size = s.size();
    for(int i = 0; i < size/2; i ++)
    {
        swap(s[i], s[size - 1 - i]);
    }
}

string DecToBase(int dec, int base)
{
    if(dec == 0)
        return "0";

    string res = "";
    while(dec != 0)
    {
        int digit = dec % base;
        char c;
        if(digit < 10)
            c = '0' + digit;
        else
            c = 'A' + digit - 10;
        res += c;
        dec /= base;
    }
    ReverseString(res);
    return res;
}

int main() {
    while(true)
    {
        cout << "Enter decimal number: ";
        int num;
        cin >> num;
        cout << "Enter targeted base of numeral system: ";
        int base;
        cin >> base;
        if( base > 36 || base < 2)
        {
            cout << "Select a base between 2 and 36" << endl;
            continue;
        }
        cout << num << " in numeral system with base " << base << " is " << DecToBase(num, base) << endl;

    }

    return 0;
}
