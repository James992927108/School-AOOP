#include "mytar.h"

bool mytar ::open_tarfile(char *fname)
{
    fs.open(fname, ios::in | ios::binary);
    if (!fs.good())
    {
        filename[0] = '\0';
        return false;
    }
    else
    {
        strncpy(filename, fname, FNAME_LEN);
        filename[FNAME_LEN - 1] = '\0';
        return true;
    }
}

void mytar ::close_tarfile()
{
    fs.close();
    filename[0] = '\0';
}

bool mytar ::read_tarfile()
{

    mytarStruct block;

    for (fs.read((char *)&block, 512); fs.gcount() && block.filename[0] != '\0'; fs.read((char *)&block, 512))
    {
        vector_mytar.push_back(block);

        if (strcmp(block.USTAR_id, "ustar  ") != 0)
        {
            cout << "Not a ustar file.\nFile opening error.\n";
            return false;
        }

        int size = ceil((double)atoi(block.filesize) / 1000);
        fs.seekg(size * 512, ios::cur);
    }
    return true;
}

void mytar ::show_data()
{
    cout<<"total " << vector_mytar.size() <<" files.\n";
    for (unsigned int i = 0; i < vector_mytar.size(); i++)
    {
        cout << translate_type(vector_mytar[i].type)
             << translate_mode(vector_mytar[i].filemode)
             << " " << left << setw(13)
             << vector_mytar[i].username
             << " " << right << setw(9)
             << octalToDec(vector_mytar[i].filesize)
             << " " << vector_mytar[i].filename << endl;
    }
}
char mytar ::translate_type(char type)
{
    if (type == '0')
        return '_';
    else
        return 'd';
}

string mytar ::translate_mode(char filemode[])
{
    int number = atoi(filemode), check;
    string sum = "\0", s;

    while (number > 0)
    {
        check = number % 10;
        switch (check)
        {
        case 0:
            s = "---";
            break;
        case 1:
            s = "--x";
            break;
        case 2:
            s = "-w-";
            break;
        case 3:
            s = "-wx";
            break;
        case 4:
            s = "r--";
            break;
        case 5:
            s = "r-x";
            break;
        case 6:
            s = "rw-";
            break;
        case 7:
            s = "rwx";
            break;
        }
        sum = s + sum;
        number /= 10;
    }
    return sum;
}

int mytar::octalToDec(char filesize[])
{
    int number = atoi(filesize), i = 0, sum = 0;

    while (number > 0)
    {
        sum += number % 10 * pow(8, i);
        number /= 10;
        ++i;
    }
    return sum;
}