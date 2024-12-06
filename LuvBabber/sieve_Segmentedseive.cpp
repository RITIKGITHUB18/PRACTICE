#include <bits/stdc++.h>
using namespace std;

// optimised sieve of eratosthense
vector<bool> Sieve(int n)
{
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (sieve[i] == true)
        {
            int j = i * i;
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

vector<bool> segSieve(int L, int R)
{
    // get me the prime array, i will use it to mark seg sieve.
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }

    // ! just priniting the base primes
    cout << "Base-Primes are: ";
    for (int i = 0; i < basePrimes.size(); i++)
    {
        cout << basePrimes[i] << " ";
    }
    cout << endl;

    // ! main part of segmented sieve

    vector<bool> segsieve(R - L + 1, true);

    if (L == 0 || L == 1)
    {
        segsieve[L] = false;
    }
    for (auto prime : basePrimes)
    {
        int first_mul = (L / prime) * prime;
        if (first_mul < L)
        {
            first_mul = first_mul + prime;
        }

        int j = max(first_mul, prime * prime);
        // int j = first_mul;
        while (j <= R)
        {
            segsieve[j - L] = false;
            j += prime;
        }
    }
    return segsieve;
}

int main()
{

    // ! optimised sieve
    // vector<bool> s = Sieve(25);

    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == true)
    //     {
    //         cout << i << " ";
    //     }
    // }

    // return 0;

    // ! Segmented sieve

    int L = 1;
    int R = 1;
    // int L = 197546824;
    // int R = 197832907;
    vector<bool> ss = segSieve(L, R);
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == true)
        {
            cout << i + L << " ";
        }
    }

    return 0;
}