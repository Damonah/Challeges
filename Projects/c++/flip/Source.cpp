
#include <iostream> 
#include <vector> 
#include <fstream> 
#include <string> 
#include <algorithm> 
using namespace std;





vector<char> getInput();
vector<char> sortPancakes(vector<char> pancakes, char completed);
static char flips;

int main()
{
	vector<char> pancakes = getInput();
	if (pancakes.size() == 0) 
		return EXIT_FAILURE;
	pancakes = sortPancakes(pancakes, 0);
	cout << "Sorted. Result: {";
	for (char p : pancakes)
	{
		cout << (int)p << ", ";
	}
	cout << "\b\b}" << endl;

	return flips;
}

char findMax(vector<char> pancakes, char endIndex)  
{
	char maxIndex, maxValue;
	for (char i = 0; i<endIndex; i++)
		if (pancakes.at(i) >= maxValue)
		{
			maxValue = pancakes.at(i);
			maxIndex = i;
		}
	return maxIndex;
}

vector<char> sortPancakes(vector<char> pancakes, char completed)
{
	if (is_sorted(pancakes.begin(), pancakes.end())) 
		return pancakes;
	else
	{
		if (pancakes.at((pancakes.size() - 1 - completed) < *(max_element(pancakes.begin(), pancakes.end() - completed)))) 
		{
			char maxIndex = findMax(pancakes, pancakes.size() - completed);
			if (maxIndex != 0) 
			{
				reverse(pancakes.begin(), (pancakes.end() - (pancakes.size() - (maxIndex + 1)))); 
				cout << "\t" << (short)++flips << " : {";
				for (char c : pancakes)
				{
					cout << (short)c << ", ";
				}
				cout << "\b\b}" << endl;
			}

			reverse(pancakes.begin(), pancakes.end() - completed); 
			cout << "\t" << (short)++flips << " : {";
			for (char c : pancakes)
			{
				cout << (short)c << ", ";
			}
			cout << "\b\b}" << endl;
			return sortPancakes(pancakes, ++completed); 
		}
	}
}

vector<char> getInput() 
{
	vector<char> result;
	ifstream file("input.txt");
	if (file.is_open())
	{
		string line;
		getline(file, line);
		while (getline(file, line, ' '))
			result.push_back(stoi(line));
	}
	else
		cout << "Could not open input.txt file!";
	return result;
}