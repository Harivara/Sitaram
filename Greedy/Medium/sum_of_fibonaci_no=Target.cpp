// https://www.geeksforgeeks.org/dsa/minimum-fibonacci-terms-sum-equal-k/


// The important difference is that the Fibonacci sequence has a special property (Zeckendorf's theorem) 
// that makes the greedy approach optimal


// Function to find the minimum Fibonacci terms
int minimumFibonacciTerms(int k) {
    vector<int> fib = {1, 1};  

    // Generate Fibonacci numbers up to k
    while (fib.back() < k) {
        fib.push_back(
            fib[fib.size() - 1] + 
            fib[fib.size() - 2]
        );
    }

    int count = 0;  

    // Start from the largest Fibonacci number
    for (int i = fib.size() - 1; 
         i >= 0 && k > 0; i--) {
        
        // Use the largest possible Fibonacci number
        while (k >= fib[i]) {
            k -= fib[i];  
            count++;  
        }
    }
    
    return count;  
}
