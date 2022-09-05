//
// Created by yuumo on 2022/07/30.
//

#include <iostream>
#include <fstream>

void	replace(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream ifd(filename.c_str());
	if (!ifd) {
		std::cerr << "Error" << std::endl;
		return ;
	}

	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs) {
		std::cerr << "Error" << std::endl;
		return ;
	}

	std::string	line;
	int pos;

	while (getline(ifd, line, '\n')) {
		if (!ifd.eof())
			line += '\n';

		while ((pos = line.find(s1)) != -1) {
			line.erase(pos, s1.size());
			line.insert(pos, s2);
		}
		ofs << line;
	}
	ofs.close();
}

int main(int argc, char **argv) {
	if (argc == 4)
	{
		if (static_cast<std::string>(argv[3]).find(static_cast<std::string>(argv[2])) != std::string::npos) {
			std::cout << "Error: The original string is contained in the string to be replaced" << std::endl;
			return 0;
		}
		replace(argv[1], argv[2], argv[3]);
	}
	else
		std::cerr << "Argument error" << std::endl;
	return 0;
}