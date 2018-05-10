#include <iostream>
#include <string>
#include <map>
#include <windows.h>

class Action
{
	public:
	virtual void Do(int argc, char ** argv) = 0;
};

class Print: public Action
{
	public:
	virtual void Do(int argc, char ** argv)
	{
		std::string str = argv[2];
		std::string param = "";
		if(argc > 3)
			 param = argv[3];
		std::cout << str;
		std::cout << (param=="-n"?"\n":"");
		
	}
};

class SetConsoleColor: public Action
{
	public:
	std::map<std::string, int> Colors;

	SetConsoleColor()
	{
		Colors = 
		{
			{"Black", 0},
            {"Blue", 1},
            {"Green", 2},
            {"Cyan", 3},
            {"Red", 4},
            {"Magenta", 5},
            {"Yellow", 6},
            {"White", 7}
		};
	}

	virtual void Do(int argc, char ** argv)
	{
		std::string bgColor = argv[2];
		std::string fgColor = argv[4];
		bool bgIntensity = argv[3];
		bool fgIntensity = argv[5];

		HANDLE hOut;
    	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    	SetConsoleTextAttribute( hOut, (Colors[fgColor]|(((int)fgIntensity)<<3))|((Colors[bgColor]|(((int)bgIntensity)<<3))<<4) );
	}
};

class SetCursorPosition: public Action
{
	public:
	virtual void Do(int argc, char ** argv)
	{
		int x = std::stoi(argv[2]), y = std::stoi(argv[3]);
		COORD pos = {x, y};
    	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleCursorPosition(output, pos);
	}
};

int main(int argc, char** argv)
{
		std::map<std::string, Action *> actions;
		actions["Print"] = new Print();
		actions["SetConsoleColor"] = new SetConsoleColor();
		actions["SetCursorPosition"] = new SetCursorPosition();

		if(argc > 1)
			actions[argv[1]]->Do(argc, argv);
		
		return 0;
}