#include <iostream>
#include <thread>
#include <chrono> 

/*
leave for comer
*/

using std::cout;
using std::endl;
using std::cin;

int main()
{
    cout<<endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
    return 0;
}

