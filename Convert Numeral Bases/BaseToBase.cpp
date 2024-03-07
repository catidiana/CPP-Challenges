#include <iostream>
#include <math.h>

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
        cout << "Enter you source number numeral system and you targeted numeral system:";
        int source, target;
        cin >> source >> target;
        if(source < 2 || target < 2 || source > 36 || target > 36)
        {
            cout << "Invalid number systems. Pick between 2 and 36";
            continue;
        }
        int dec = source == 10 ? stoi(num) : BaseToDec(num, source);
        if(dec == -1)
        {
            cout << "Invalid number. You number format does not correspond your source number system" << endl;
            continue;
        }
        cout << source << "-base " << num << " in " << target << "-base numeral system is ";
        if(target == 10)
            cout << dec << endl;
        else
            cout << DecToBase(dec, target) << endl;

    }

    return 0;
}
