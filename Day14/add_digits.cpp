class Solution {
public:
    int addDigits(int num) {

        if((to_string(num)).size() < 2)
        {
            return num;
        }

        while(num > 9)
        {
            int sumi = 0;
            while(num > 0)
            {
                int rem = num%10;
                sumi = sumi + rem;
                num = num/10;
            }
            num = sumi;
        }
        
        return num;
    }
};
