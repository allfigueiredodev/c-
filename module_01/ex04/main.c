#include "Sed.hpp"

int main (int argc, char **argv){
	std::ifstream	infile;
	std::string		content;
	std::string		filename;
	int				line_count = 0;

	if (argc != 4){
		std::cerr << RED <<"Bad arguments" << DFT << std::endl;
		std::cerr << CYAN <<"Try this way: ./sed <filename> s1 s2" << DFT << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (infile.fail()){
		std::cerr << RED << "Fail opening the file" << DFT << std::endl; 
		return (1);
	}
	while (std::getline(infile, content))
		line_count++;
	Sed	replace = Sed(line_count);
	infile.clear();
	infile.seekg(0);
	for (int i = 0; std::getline(infile, content); i++)
		replace.setStr(content, i);
	filename = argv[1];
	std::ofstream	outfile(filename + ".replace");
	if (outfile.fail()){
		std::cerr << RED << "Fail creating the file" << DFT << std::endl; 
		return (1);
	}
	replace.changeStr(argv[2], argv[3], line_count);
	for (int j = 0; j < line_count; j++)
		outfile << replace.getStr(j) << std::endl;
	outfile.close();
	infile.close();
}