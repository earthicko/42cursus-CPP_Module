#include <iostream>
#include <cstdlib>

void	doTest(const char *const command)
{
	std::cout << "************************************************************";
	std::cout << std::endl;
	std::cout << "Execute " << command << std::endl;
	system(command);
	std::cout << "Result:" << std::endl;
	system("cat sampletext.txt.replace");
	system("rm sampletext.txt.replace");
	std::cout << std::endl;
}

int	main(void)
{
	system("make");
	doTest("./ex04 sampletext.txt file FILE");
	doTest("./ex04 sampletext.txt file \"\"");
	doTest("./ex04 sampletext.txt \"\" file");
	doTest("./ex04 nonexistent file FILE");
	doTest("./ex04 nonexistent file \"\"");
	doTest("./ex04 nonexistent \"\" file");
	return (0);
}
