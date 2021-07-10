class Solution {
public:
        // Use sieve 
    bool isPrime(int n)
    {
        if(n<=1) return false;
        if(n<=3) return true;
        
        if(n%2==0 || n%3==0) return false;
        
        for(int i=5;i*i<=n;i+=6)
            if(n%i==0 || n%(i+2)==0)
                return false;
        
        return true;
    }
        

        
    int countPrimeSetBits(int left, int right) {
        
        int bitc,count=0;
        
        for(int i=left;i<=right;i++)
        {
            bitc=__builtin_popcount(i);
            if(isPrime(bitc))
                count++;
        }
        return count;
    }
};