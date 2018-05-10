#include <windows.h>
#include <string>

int main(int argc, char** argv)
{
    std::string batFileName = "main.bat";
    system(batFileName.c_str());
    return 0;
}