class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> freqp(26);      //26 alphabets
        vector<int> freqs(26);
        vector<int> op;         //output vector which contains index of anagrams

        if(s.size() < p.size())
        {
            return op;
        }

        //iterate thru string p
        for(int i=0;i<p.size();i++)
        {   
            //increment value of chars of p in vector named freqp
            //freqp = [a,b,c,d,e,....z] => values [0,0,0,0..0]
            //similarily with freqs array for string s
            freqp[p[i]- 'a']++;
            freqs[s[i] - 'a']++;
            //first window is complete
        }

        //check if both vectors are equal
        if(freqp == freqs)
        {   
            //as start pointer is at 0th position
            op.push_back(0);
        }

        //now iterate thru string s
        for(int start=p.size();start<s.size();start++)
        {   
            //we shrink the window size
            freqs[s[start-p.size()] - 'a']--;    //we pop out item from left side of window
            freqs[s[start]- 'a']++;             //add new element to right side of window

            //update output accordingly
            if(freqp == freqs)
            {
                op.push_back(start-p.size()+1);
            }
        }

        return op;
    }
};
