int setbits(unsigned long long int n){
    int cnt = 0;
    while(n){
        cnt += 1;
        n &= (n - 1);
    }
    return cnt;
}