#include <iostream>
using namespace std;

int main()
{
    long long a,b;
    while(cin>>a>>b)
    {
        long long res = max(a,b) - min(a,b);
        cout << res << "\n";
        
    }
    return 0;
}
