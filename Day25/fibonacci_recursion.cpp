

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    //base condition
    if(n==0)
    {
        return 0;
    }
    
    if(n==1 || n==2)
    {
        return 1;
    }
    
    //recursive condition
    else
    {
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

int main()
{
    for(int i=0;i<5;i++)
    {
        cout<<fibonacci(i)<<" ";
    }

    return 0;
}
