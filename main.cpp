#include <iostream>
#include <bits/stdc++.h>
#include <thread>
#include <algorithm>

class MultithreadRandomNumberSum {
private:
  std::vector<std::thread> threads;
  std::vector<int> results;
  int numThreads;
  std::vector<int>::iterator maxScoreIt;
  int maxScoreIndex;

  int addRandomNumbers() {
    int sum = 0;

    for (int i = 1; i <= 100; i++) {
      sum += (rand() % 1000) + 1;
    }

    return sum;
  }
public:
  MultithreadRandomNumberSum(int size) {
    this->numThreads = size;
    this->threads.reserve(size);
    this->results.resize(size);
  };

  void runRandomSum() {
    // Create the 10 thread and perform the random sum
    for (int i = 0; i < numThreads ; i++) {
      threads.emplace_back(([this, i]() {
        results[i] = this->addRandomNumbers();
        std::cout << "Thread " << i << ": " << results[i] << std::endl;
      }));
    }

    // Wait for each thread to finish
    for (auto& thread : threads) {
      thread.join();
    }

    // Print the thread with the highest score
    maxScoreIt = std::max_element(results.begin(), results.end());
    maxScoreIndex = std::distance(results.begin(), maxScoreIt);
    std::cout << "Highest score: Thread " << maxScoreIndex << " with a sum of " << *maxScoreIt << std::endl;
  }
};

int main() {
  srand(time(nullptr));
  MultithreadRandomNumberSum randomSum(10);
  randomSum.runRandomSum();

  return 0;
}