#include <iostream>

using namespace std;

void fun(int x, int A, int B, int C)
{
    return A*x+B*sin(x) = C;
    
}

void derivateFun(int x, int A, int B, int C)
{
    return A*x+B*cos(x) = 0;
    
}

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int A,B,C;
        cin >> A >> B >> C;
        int x = 0;
        double h = fun(x,A,B,C) / derivateFun(x,A,B);
        while(h > 0.001)
        {
            h = fun(x,A,B,C) / derivateFun(x,A,B);
            x -= h;
        }
    }
    cout<<"Hello World";

    return 0;
}
