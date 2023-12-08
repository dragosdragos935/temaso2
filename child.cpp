#include <iostream>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <start_value> <end_value>\n";
        return 1;
    }

    int start = std::stoi(argv[1]);
    int end = std::stoi(argv[2]);

    std::cout << "Child process for range [" << start << " - " << end << "]\n";

    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
