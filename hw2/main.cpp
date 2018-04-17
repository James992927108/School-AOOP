#include "main.h"

int main(int argn, char **argv)
{
	mytar main_tar;
	if (argn != 2)
	{
		usage(argv[0]);
		return 0;
	}
	else
	{
		if (main_tar.open_tarfile(argv[1]))
		{
			if(main_tar.read_tarfile() == true)
			{
				main_tar.show_data();
			}
			main_tar.close_tarfile();
		}
	}

	return 0;
}

void usage(char *prog)
{
	cout << "format : {" << prog << " input FileName}\n";
}