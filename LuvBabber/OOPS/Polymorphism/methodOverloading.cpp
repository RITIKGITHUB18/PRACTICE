#include <bits/stdc++.h>
using namespace std;

/*Imagine Swiggy system allowing users to make payment via different methods- credit card, upi, or wallet.
Each payment option can be represented using method overloading
*/

class Payment
{
public:
    void processPayment(int amt)
    {
        cout << "Processing amout of Rs: " << amt << " using cash on delivery method." << endl;
    }

    void processPayment(int amt, string cardNum)
    {
        cout << "Proccessing amount of Rs: " << amt << " using Card Method." << endl;
    }
    void processPayment(int amt, string upiId, bool isUPI)
    {
        if (isUPI)
            cout << "Proccessing amount of Rs: " << amt << " using UPI:" << upiId << endl;
        else
            cout << "Invalid UPI" << endl;
    }
};

int main()
{
    Payment person1;
    person1.processPayment(120, "9064801614@paytm", true);
    return 0;
}
