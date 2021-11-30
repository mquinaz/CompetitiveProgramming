#include <iostream>
using namespace std;

int main()
{
    int L,D,X;
    cin >> L;
    cin >> D;
    cin >> X;
    
    //First number 
    for(int i=L;i<=D;i++){
        string num = to_string(i);
        int digitSum = 0;
        for(int j=0;j<num.size();j++)
            digitSum += num[j] - '0';
        
        if(digitSum == X){
            cout << i << "\n";
            break;
        }
    }
 
    //Last number 
    for(int i=D;i>=L;i--){
        string num = to_string(i);
        int digitSum = 0;
        for(int j=0;j<num.size();j++)
            digitSum += num[j] - '0';
        
        if(digitSum == X){
            cout << i;
            break;
        }
    }       
    return 0;
}
