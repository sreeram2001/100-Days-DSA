
#include<string.h>
#include <iostream>

using namespace std;

void recurse(string ss, int ind, string op)
{
    if(ind == ss.size())
    {
        return;
    }
    op = ss[ind];
    recurse(ss, ind+1, op);
    std::cout<<op;
}

int main()
{
    string ss = "abc";
    recurse(ss, 0, " ");

    return 0;
}
