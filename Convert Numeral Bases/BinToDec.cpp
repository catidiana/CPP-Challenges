#include <iostream>
#include <math.h>

using namespace std;

int BinToDec(string bin)
{
    int dec = 0;
    int len = bin.size();
    for(int i = len - 1; i >= 0 ; i--)
    {
        if (bin[i] == '1')
            dec += pow(2, len - i - 1);
        else if(bin[i] != '0')
            return -1;
    }
        return dec;
}

int main() {

    while(true)
    {
        cout << "Enter binary number: ";
        string num;
        cin >> num;
        int result = BinToDec(num);
        if(result == -1)
        {
            cout << "Invalid number" << endl;
            continue;
        }
        cout << "Decimal representation " << result << endl;
    }

    return 0;
}
