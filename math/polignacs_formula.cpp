//Largest power of a prime p that divides the factorial n!
//For n = 6, one has 6! = 720 = 2^4 . 3^2 . 5^1

void factFactorize ( int n ) { 
    for ( int i = 0; i < prime.size() && prime[i] <= n; i++ ) {
        int x = n;
        int freq = 0;
 
        while ( x / prime[i] ) {
            freq += x / prime[i];
            x = x / prime[i];
        }
 
        printf ( "%d^%d\n", prime[i], freq );
    }
}
