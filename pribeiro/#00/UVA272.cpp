#include <iostream>
using namespace std;

int main()
{
    string text;
    int cont=0;
    while(getline(cin,text)){
        for(int i = 0; text[i]; i ++) {
            if(text[i] == '"'){
                cont++;
                if(cont % 2 != 0)
                    printf("``");
                if(cont % 2 == 0)
                   printf("''"); 
            }
            else
                printf("%c",text[i]);
            }
        printf("\n");
    }
    return 0;
}
