#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <future>
#include <algorithm> 

using ComplexityCache = std::vector<int>;

inline int sqrti(int in)
{
	return static_cast<int>(sqrtf(static_cast<float>(in)));
}

int calculate(const ComplexityCache& cache)
{
	const int candidate = cache.size();
	int bestResult = candidate;
	
	for (int i = 1; i <= candidate / 2; ++i)
	{
		const int measuredComplexityOffset = cache[candidate - i] + cache[i];
		bestResult = std::min(bestResult, measuredComplexityOffset);
	}
	return bestResult;
}

int Mult_complexity(const ComplexityCache& cache)
{
	const int candidate = cache.size();
	int bestResult = candidate + 1; // 
	for (int i = 2; i <= sqrti(candidate) && i < static_cast<int>(cache.size()); ++i)
	{
		if ((candidate % i) == 0)
		{
			const int measuredComplexityOffset = cache[candidate / i] + cache[i];
			bestResult = std::min(bestResult, measuredComplexityOffset);
		}
	}
	return bestResult;
}

int calculateNextComplexity(const ComplexityCache& cache)
{
	auto add_complexity = std::async(std::launch::async, calculate, cache);
	auto multiply_compexity = std::async(std::launch::async, Mult_complexity, cache);
	return std::min(add_complexity.get(), multiply_compexity.get());
}

int main()
{

	ComplexityCache complexityCache;

	int target_number = 0;
	std::cout << "Number of complexities to calculate (1 to ?): ";
	std::cin >> target_number;

	while (static_cast<int>(complexityCache.size()) <= target_number)
	{
		complexityCache.push_back(calculateNextComplexity(complexityCache));
	}

	int totalComplexity = 0;
	for (std::size_t i = 0; i < complexityCache.size(); ++i)
	{
		std::cout << i << ": " << complexityCache[i] << '\n';
		totalComplexity += complexityCache[i];
	}
	std::cout << "Total complexity: " << totalComplexity << '\n';
	std::string scratch;
	std::getline(std::cin, scratch); 
	std::getline(std::cin, scratch); 
	return 0;
}