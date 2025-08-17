#include <iostream>
#include <bits/stdc++.h>
#include <thread>
#include <algorithm>

class Adder {
public:
  int addRandomNumbers() {
    int sum = 0;

    for (int i = 1; i <= 100; i++) {
      sum += (rand() % 1000) + 1;
    }

    return sum;
  }
};

int main() {
  Adder adder;
  std::vector<int> results(10);
  std::vector<std::thread> threads;
  srand(time(nullptr));

  // Create the 10 thread and perform the random sum
  for (int i = 0; i < 10; i++) {
    threads.emplace_back(([i, &results, &adder]() {
      results[i] = adder.addRandomNumbers();
      std::cout << "Thread " << i << ": " << results[i] << std::endl;
    }));
  }

  // Wait for each thread to finish
  for (auto& thread : threads) {
    thread.join();
  }


  // Print the thread with the highest score
  auto maxScore = std::max_element(results.begin(), results.end());
  int maxScoreIndex = std::distance(results.begin(), maxScore);
  std::cout << "Highest score: Thread " << maxScoreIndex << " with a sum of " << *maxScore << std::endl;

  return 0;
}