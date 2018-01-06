#include <iostream>

using std::cin;

int main()
{
    int* men;
    int amount_of_men,result;
    
    cin>>amount_of_men;
    men = new int[amount_of_men];
    for(int i = 0;i < amount_of_men;++i)
    {
        cin>>men[i];
    }
    
    std::cout<<result<<std::endl;
    
    return 0;
}