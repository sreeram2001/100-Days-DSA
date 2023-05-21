

#include <iostream>

using namespace std;

int sumrecursive(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return (n + sumrecursive(n-1));
    }
}

int main()
{
    int p = sumrecursive(5);
    cout<<p;

    return 0;
}
