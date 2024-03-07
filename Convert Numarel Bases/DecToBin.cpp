#include <iostream>

using namespace std;

void ReverseString(string& s)
{
    int size = s.size();
    for(int i = 0; i < size/2; i++)
        swap(s[i], s[size - 1 - i]);
}

string DecToBin(int dec)
{
    if (dec == 0)
        return "0";

    string bin = "";
    while(dec != 0)
    {
        char digit = dec % 2 == 0 ? '0' : '1';
        bin += digit;

        dec /= 2;
    }
    ReverseString(bin);
    return bin;
}

int main() {

    while(true)
    {
        cout << "Enter decimal number: ";
        int num;
        cin >> num;
        cout << "Binary representation is " << DecToBin(num) << endl;
    }

    return 0;
}
