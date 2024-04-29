#include <iostream>

int main (int argc, char **argv)
{
	std::string	concatenated;
	int			i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc == 2)
		std::cout << argv[1] << std::endl;
	else
	{
		while(argc != 1)
		{
			if (argc == 2)
				concatenated.append(argv[i]);
			else
			{
				concatenated.append(argv[i]);
				concatenated.append(" ");
			}
			i++;
			argc--;
		}
		transform(concatenated.begin(), concatenated.end(), concatenated.begin(), ::toupper);
		std::cout << concatenated << std::endl;
	}
}