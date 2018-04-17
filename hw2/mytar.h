#ifndef MYTAR_H
#define MYTAR_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <cmath>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::hex;
using std::ios;
using std::ostream;
using std::setfill;
using std::setw;
using std::string;
using std::vector;
using std::left;
using std::right;

struct mytarStruct
{
	char filename[100]; //0
	char filemode[8];   //100
	char userid[8];		//108
	char groupid[8];	//116
	char filesize[12];  //124
	char mtime[12];		//136
	char checksum[8];   //148
	char type;			//156
	char lname[100];	//157
	/* USTAR Section */
	char USTAR_id[6];   //257
	char USTAR_ver[2];  //263
	char username[32];  //265
	char groupname[32]; //297
	char devmajor[8];   //329
	char devminor[8];   //337
	char prefix[155];   //345
	char pad[12];		//500
};

//mytar.cpp
class mytar
{
	//use in open
  private:
	static const int FNAME_LEN = 1024;
	char filename[FNAME_LEN];
	fstream fs;

	int value(char ch);
	vector<mytarStruct> vector_mytar;

  public:
	bool open_tarfile(char *fname);
	bool read_tarfile();
	void close_tarfile();
	void show_data();
	char translate_type(char type);
	string translate_mode(char filemode[]);
	int octalToDec(char filesize[]);
};
#endif
