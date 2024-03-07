#include <iostream>
#include <math.h>

using namespace std;

int BaseToDec(string num, int base)
{
    int dec = 0;
    int len = num.size();
    for(int i = len - 1; i >= 0; i--)
    {
        int digit;
        if(num[i] >= '0' && num[i] <= '9')
            digit = num[i] - '0';
        else if(num[i] >= 'a' && num[i] <= 'z')
            digit = num[i] - 'a' + 10;
        else if(num[i] >= 'A' && num[i] <= 'Z')
            digit = num[i] - 'A' + 10;
        else
            return -1;
        if(digit >= base)
            return -1;
        dec += digit * pow(base, len - i - 1);
    }
    return dec;
}

int main() {
    while(true)
    {
        cout << "Enter number: ";
        string num;
        cin >> num;
        cout << "Enter you numeral system base: ";
        int base;
        cin >> base;
        int result = BaseToDec(num, base);
        if(result == -1)
        {
            cout << "Invalid number" << endl;
            continue;
        }
        cout << "Decimal representation " << result << endl;
    }
    return 0;
}
