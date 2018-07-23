#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cctype>

void end() {
	std::string str;
	std::cout << "Press any key to exit..." << std::endl;
	std::getline(std::cin, str);
}

std::string getFileName() {
	std::cout << "Enter file name to be converted: ";
	std::string fileName;
	std::getline(std::cin, fileName);
	return fileName;
}

std::vector<int> readFile(std::string fileName) {
	std::ifstream inFile;
	inFile.open(fileName);
	if (!inFile) {
		std::cout << "Unable to open input file" << std::endl;
		end();
		exit(1);
	}

	try {
		std::vector<int> frequency(26, 0);
		std::string word;
		while (inFile >> word) {
			for (char c : word) {
				c = tolower(c);
				if (std::isalpha((unsigned char) c))
					++frequency[c - 'a'];
			}
		}
		std::cout << "Read successful" << std::endl;
		return frequency;
	}
	catch (const std::exception& e) {
		std::cout << "Read error" << std::endl;
	}
}

void writeFile(const std::vector<int> frequency) {
	std::ofstream outFile;
	outFile.open("frequencies.txt");
	if (!outFile) {
		std::cout << "Unable to open output file" << std::endl;
		end();
		exit(1);
	}
	try {
		for (int i = 0; i < 26; i++) 
			outFile << char (i + 'a') << ' ' << frequency[i] << std::endl;
		std::cout << "File has been converted" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Conversion error" << std::endl;
	}
}

int main() {
	std::string fileName = getFileName();
	std::vector<int> frequency = readFile(fileName);
	writeFile(frequency);
	end();

	return 0;
}