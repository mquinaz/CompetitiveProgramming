#include <iostream>

using namespace std;

int cycleLength(int n){
    int count = 0;
    while(n != 1){
        //cout << n << " ";
        count++;
        if( n % 2 != 0)
            n = 3*n+1;
        else
            n /= 2;
    }
    return count+1;
}
int main()
{
    int i,j;
    while(cin>>i>>j)
    {
        int maxResult = 0;
        for(int k=min(i,j);k<=max(i,j);k++){
            int result = cycleLength(k);
            if(maxResult < result)
                maxResult = result;
        }
        //cout << "\n" << i << " " << j << " "<< maxResult;
        printf("%d %d %d\n",i,j,maxResult);
    }
    return 0;
}
