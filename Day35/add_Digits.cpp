class Solution {
public:

    int recurs(int numi, int sumi)
    {
        if(numi == 0)
        {
            return sumi;
        }
        return recurs(numi/10, sumi+numi%10);
    }

    int addDigits(int num) {
        
        int sumi = 0;
        while(num > 9)
        {
            sumi = 0;
            num = recurs(num, sumi);
        }
        return recurs(num, sumi);
    }
};
