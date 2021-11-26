#include <iostream>

using namespace std;

main()
{
    string final = "";
    string text;
    while(getline(cin, text)){
        final.append(text);
    }
    
    cout << final;
    int n = text.size();
    int cont = 0;
    for(int i=0;i<n;i++){
        if(final[i] == '"')
            cont++;
        if(cont % 2 != 0)
            final[i] = '``';
        if(cont % 2 == 0)
            final[i] = '''';\   
    }
    cout<<final;
}
