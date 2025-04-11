class Solution {
    public long numberOfPowerfulInt(long start, long end, int limit, String suffix) {
        return count(end, limit, suffix) - count(start - 1, limit, suffix);
    }

    private long count(long cap, int limit, String suffix) {
        String s = Long.toString(cap);
        int prefixLen = s.length() - suffix.length();

        if (prefixLen < 0) return 0;

        long[][] dp = new long[prefixLen + 1][2];
        dp[prefixLen][0] = 1;
        dp[prefixLen][1] = s.substring(prefixLen).compareTo(suffix) >= 0 ? 1 : 0;

        for (int i = prefixLen - 1; i >= 0; i--) {
            int digit = s.charAt(i) - '0';
            dp[i][0] = (limit + 1) * dp[i + 1][0];
            if (digit <= limit) {
                dp[i][1] = (long) digit * dp[i + 1][0] + dp[i + 1][1];
            } else {
                dp[i][1] = (long) (limit + 1) * dp[i + 1][0];
            }
        }
        return dp[0][1];
    }
}