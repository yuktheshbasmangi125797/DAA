#include <iostream>
#include <chrono>
// __Iterative__
unsigned long long findFactorialLoop(int num)
{
    unsigned long long answer = 1;

    for (int count = 1; count <= num; count++)
    {
        answer = answer * count;
    }

    return answer;
}
// ___Recursive_____
unsigned long long findFactorialRec(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    return num * findFactorialRec(num - 1);
}
int main()
{
    int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;
    if (number < 0)
    {
        std::cout << "Invalid input! Enter a non-negative number."
                  << std::endl;
        return 1;
    }
    // -------- ITERATIVE METHOD --------
    auto loopStart = std::chrono::high_resolution_clock::now();
    unsigned long long loopResult = findFactorialLoop(number);
    auto loopEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> loopTime =
        loopEnd - loopStart;
   // -------- RECURSIVE METHOD --------
    auto recStart = std::chrono::high_resolution_clock::now();
    unsigned long long recResult = findFactorialRec(number);
    auto recEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> recTime =
        recEnd - recStart;
    // -------- DISPLAY RESULTS --------
    std::cout << "\n========== FACTORIAL RESULTS ==========\n";
    std::cout << "Number       : " << number << std::endl;
    std::cout << "\nIterative Method\n";
    std::cout << "Factorial    : " << loopResult << std::endl;
    std::cout << "Time         : " << loopTime.count()
              << " ns" << std::endl;
    std::cout << "\nRecursive Method\n";
    std::cout << "Factorial    : " << recResult << std::endl;
    std::cout << "Time         : " << recTime.count()
              << " ns" << std::endl;
    return 0;
}
