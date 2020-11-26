// This is to demonstrate how code can comment itself if written with
// such intention.

#include <iostream>

const short MAJ = 0;
const short MIN = 1;
const short BUG = 7;

std::string computeVersion()
{
	std::string version;
	version += std::to_string(MAJ);
	version += ".";
	version += std::to_string(MIN);
	version += ".";
	version += std::to_string(BUG);
	return "Version:\t" + version + "\nDeveloper:\tDaniel Shamany";
}

std::string helpPage()
{
	std::string page;
	page += "HELP:\n";
	page += "Enter any positive number, and retrieve its digit count.\n";
	page += "\n-v\tDisplay program version\n";
	return page;
}

int main(int argc, const char *argv[])
{
	std::string s = "";
	if (argc > 1)
	{
		for (int i = 0; i < argc; ++i)
		{
			s = argv[i]; // Requered for easy checking of string
			if (s == "-v")
			{
				system("clear");
				std::cout << computeVersion() << std::endl;
				return 0;
			}
			else if (s == "-h")
			{
				system("clear");
				std::cout << helpPage() << std::endl;
				return 0;
			}
		}
	}
	int num = 0;
	while (std::cin >> num && num >= 0)
	{
		int length = 1;
		while (num /= 10)
			++length;
		std::cout << length << std::endl;
	}
	return 0;
}
