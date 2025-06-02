#include <iostream>
#include <vector>

#define printNoSpaceEnd(x, n) std::cout << x << " \n"[n - 1 == i];

typedef long long ll;

bool isPrime(ll number){

    if(number < 2) 
        return false;
    if(number == 2)
        return true;
    if(number % 2 == 0)
        return false;

    for(int i=3; (i*i) <= number; i+=2)
        if(number % i == 0 )
            return false;

    return true;
}

void SieveOfEratosthenes(std::vector<bool> &isPrime, long long n)
{
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= n; j += i)
				isPrime[j] = false;
		}
	}
}

int main()
{

    return 0;
}
