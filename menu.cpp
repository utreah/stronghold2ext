#include "stdafx.h"
#include "menu.h"


void printMenuInfo()
{
	DWORD procIId = GetProcessId(L"Stronghold2.exe");
	std::cout << "\t\t\t\KEYS/SETTINGS" << std::endl;;
	if (procIId)
	{
		std::cout << "Game Has Been Found! Process Name : " << "Stronghold2.exe" << std::endl;
	}

	std::cout << "[NUMPAD1] -> INFINITE MONEY/CROWN/FOOD/ [ON/OFF]" << std::endl;
	std::cout << "[NUMPAD2] -> INFINITE RESOURCES		[ON/OFF]" << std::endl;
	std::cout << "[NUMPAD3] -> INFINITE FOOD		[ON/OFF]" << std::endl;
	std::cout << "[NUMPAD4] -> INFINITE ARMORY            [ON/OFF]" << std::endl;
}
