#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    long long int a,b,k,divider,result;
    for(int i=0;i<num;i++){
        cin >> a >> b >> k;
        divider = k / 2;
        result = a * divider - b * divider;
        if( k % 2 != 0)
            result += a;
        cout << result << "\n";
    }
    return 0;
}
