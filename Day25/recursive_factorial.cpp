

#include <iostream>
using namespace std;

int factorial(int n)
{
    //base condition
    if(n==0)
    {
        return 1;
    }
    //recursive condition
    else
    {
        return (n*factorial(n-1));
    }
}

int main()
{
    int p = factorial(5);
    cout<<p;

    return 0;
}
