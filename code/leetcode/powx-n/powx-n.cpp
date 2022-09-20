class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0)
            nn=-nn;
        while(nn>0)
        {
            if(nn%2==0)
            {
                x=x*x;
                nn/=2;
            }
            else
            {
                ans=ans*x;
                nn-=1;
            }
        }
        if(n<0)
            return (double)(1.0)/(double)(ans);
        return ans;
    }
};