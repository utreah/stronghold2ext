#include "stdafx.h"
#include "menu.h"


void printMenuInfo()
{
	DWORD procIId = GetProcessId(L"Stronghold2.exe");
	std::cout << "\t\t\t\TUSLAR/AYARLAR" << std::endl;;
	if (procIId)
	{
		std::cout << "Oyun Bulundu! Oyunun client adi : " << "Stronghold2.exe" << std::endl;
	}

	std::cout << "[NUMPAD1] -> SINIRSIZ PARA/MUTLULUK/TAC [ON/OFF]" << std::endl;
	std::cout << "[NUMPAD2] -> SINIRSIZ KAYNAK		[ON/OFF]" << std::endl;
	std::cout << "[NUMPAD3] -> SINIRSIZ YEMEK		[ON/OFF]" << std::endl;
	std::cout << "[NUMPAD4] -> SINIRSIZ ASKERI MALZEME    [ON/OFF]" << std::endl;
}
