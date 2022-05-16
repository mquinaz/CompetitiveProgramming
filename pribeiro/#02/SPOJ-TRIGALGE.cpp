#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        double A,B,C;
        cin >> A >> B >> C;
        
        double x=C/A;
        for(int i=1;i<=100;i++)
        {
            x = x - (A*x+B*sin(x) - C) / (A+B*cos(x));
        }
        printf("%lf\n",x);
    }

    return 0;
}
