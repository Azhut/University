def prime_generator():
    yield 2
    primes = [2]
    num = 3

    while True:
        is_prime = True

        for prime in primes:
            if num % prime == 0:
                is_prime = False
                break

        if is_prime:
            yield num
            primes.append(num)

        num += 2


generator = prime_generator()

for i in range(40):
    print(next(generator))
