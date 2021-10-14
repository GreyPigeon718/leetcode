class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {

        vector<int> v;
        if(num.empty())
            return v;
        if(size > num.size())
            return v;
        if(size == 0)
            return v;
        for(int i = 0; i < num.size()-size+1; ++i)
        {
            int tmp = 0;
            for(int j = i; j < i+size; ++j)
            {
                if(num[j] > tmp)
                    tmp = num[j];
            }
            v.push_back(tmp);
        }
        return v;
    }
};