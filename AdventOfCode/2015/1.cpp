#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("in1.txt");
    std::string str; 
    int32_t floor = 0;
    while (std::getline(file, str))
    {
        for(auto it : str)
        {
            if(it == ')')
                floor--;
            else if(it == '(')
                floor++;
        }
    }
    std::cout << floor << std::endl;
    return 0;
}
