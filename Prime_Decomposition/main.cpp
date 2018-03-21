#include <iostream>
#include <list>


/* TODO:
 * Prime Number = A number only divisible by 1 & its self
 * Determine if the given number is prime
 * Divide by 2 and move up if the result is not a whole number
 * If the result is not prime, store the value and divide again
 * Repeat until result is prime.
 * EQ: 12 = {2,2,3}
 */

bool isPrime(int x) {
    //std::cout << "isPrime: " << x << std::endl;
    if (x == 2) {return true;}
    else {return x % 2 != 0;}
}

bool isWhole(float f) {
    return f-(int)f == 0;
}

int generatePrime(int pNum) {
    pNum = ++pNum;
    while(!isPrime(pNum)) {
        //std::cout << "prime: " << pNum << std::endl;
        ++pNum;
    }

    return pNum;
}

std::list<int> decompressPrime(int x) {
    int result;
    std::list<int> decomp;
    int divider = generatePrime(1);

    while(!isWhole(result) || !isPrime(result) ) {
        //std::cout << "result: " << result << "divider: " << divider << std::endl;
        result = x / divider;

        if (!isWhole(result)) {
            // increment divider
            divider = generatePrime(divider);
        } else if (!isPrime(result)) {
            // store value and set x as result
            decomp.push_back(divider);

            x = result;
        }
    }
    // store last result
    decomp.push_back(divider);
    decomp.push_back(result);
    return decomp;
}

int main() {
    int input;
    std::list<int> decompressed;
    bool loop = true;
    while(loop) {
        int z = 0;
        std::cout << "Please Insert a prime number to find its decomposition" << std::endl;
        std::cin >> input;

        std::cout << "Prime Decomposition: " << std::endl;
        if(isWhole(input)) {
            decompressed = decompressPrime(input);
            for(int d : decompressed)
            std::cout << "output: " << d << "," << std::endl;
        }
    }
    return 0;
}