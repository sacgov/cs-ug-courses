function p = prime_pairs(n)
v = primes(100000);
p = -1
for i = v
    if(isprime(i+n))
        p =i
        break
    end
end
        
        
    