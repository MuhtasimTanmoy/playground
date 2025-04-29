class Solution {
public:
    const int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        // Find the maximum element in nums to determine the range for prime
        // generation
        int maxElement = 0;
        for (int index = 0; index < n; index++) {
            maxElement = max(maxElement, nums[index]);
        }

        // Get all prime numbers up to maxElement using the Sieve of
        // Eratosthenes
        vector<int> primes = getPrimes(maxElement);

        // Calculate the prime score for each number in nums
        for (int index = 0; index < n; index++) {
            int num = nums[index];

            // Iterate over the generated primes to count unique prime factors
            for (int prime : primes) {
                if (prime * prime > num)
                    break;  // Stop early if prime^2 exceeds num
                if (num % prime != 0)
                    continue;  // Skip if the prime is not a factor

                primeScores[index]++;  // Increment prime score for the factor
                while (num % prime == 0)
                    num /= prime;  // Remove all occurrences of this factor
            }

            // If num is still greater than 1, it is a prime number itself
            if (num > 1) primeScores[index]++;
        }

        // Initialize next and previous dominant index arrays
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        // Stack to store indices for a monotonic decreasing prime score
        stack<int> decreasingPrimeScoreStack;

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            // While the stack is not empty and the current prime score is
            // greater than the stack's top, update nextDominant
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();

                // Set the next dominant element for the popped index
                nextDominant[topIndex] = index;
            }

            // If the stack is not empty, set the previous dominant element for
            // the current index
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();

            // Push the current index onto the stack
            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        }

        // Sort elements in decreasing order based on their values
        vector<pair<int, int>> sortedArray(n);
        for (int index = 0; index < n; index++) {
            sortedArray[index] = {nums[index], index};
        }

        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        long long score = 1;
        int processingIndex = 0;

        // Process elements while there are operations left
        while (k > 0) {
            // Get the element with the maximum value
            auto [num, index] = sortedArray[processingIndex++];

            // Calculate the number of operations to apply on the current
            // element
            long long operations = min((long long)k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of
            // operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return score;
    }

private:
    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

    // Function to generate prime numbers up to a given limit using the Sieve of
    // Eratosthenes
    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        // Start marking from the first prime number (2)
        for (int number = 2; number <= limit; number++) {
            if (!isPrime[number]) continue;

            // Store the prime number
            primes.push_back(number);

            // Mark multiples of the prime number as non-prime
            for (long long multiple = (long long)number * number;
                 multiple <= limit; multiple += number) {
                isPrime[multiple] = false;
            }
        }

        return primes;
    }
};