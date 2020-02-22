class Solution {
    public double new21Game(int N, int K, int W) {
        if (N < K) return 0.0;
        if (K == 0) return 1.0;
        
        double[] dp = new double [N + 1];
        dp[0] = 1.0;
        
        double result = 0.0;
        double prevSum = 1.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = prevSum / W;
            
            if (i >= W) prevSum -= dp[i - W];
            if (i < K) prevSum += dp[i];
            else result += dp[i];       
            System.out.println(i + ": " + dp[i] + " " + prevSum + " " + result);
        }
        
        return result;       
    }
}