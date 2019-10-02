#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string getInput()
{
	string temp;
	getline(cin, temp);
	return temp;
}

vector<float> parseInput(string input)
{
	input += ',';
	int length = input.length();
	string temp = "";
	vector<float> ret;
	for (int i = 0; i < length; i++)
	{
		if (input.at(i) == ',')
		{
			ret.push_back(stof(temp) + ((rand() % 10) / 10.0));
			temp = "";
		}
		else
		{
			temp += input.at(i);
		}
	}
	return ret;
}

int main(void)
{
	ofstream dataOutput;
	dataOutput.open("dataOutput.txt");
	string input = getInput();
	while (input != "")
	{
		vector<float> data;
		data = parseInput(input);
		for (int i = 0; i < data.size(); i++)
		{
			if (i == data.size() - 1)
			{
				dataOutput << data[i];
			}
			else
			{
				dataOutput << data[i] << ",";
			}
		}
		dataOutput << '\n';
		input = getInput();
	}

	dataOutput.close();
	return 0;
}