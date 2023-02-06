// stronghold2ext.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include "stdafx.h"

int main()
{

	DWORD procId = 0;
	HANDLE hProcess = 0;
	uintptr_t LocalPlayer = 0,moduleBase = 0;
	uintptr_t moneyAddr = 0, crownAddr=0, happinessAddr=0, peasantTotalAddr = 0,ironAddr = 0, stoneAddr = 0,woodAddr = 0, candleAddr = 0;
	uintptr_t wheatAddr = 0, flourAddr = 0, hopAddr = 0, beerAddr = 0, grapeAddr = 0, lordFishAddr = 0, duckAddr = 0, pigAddr = 0;
	uintptr_t meatAddr = 0, cheeseAddr = 0, breadAddr = 0, appleAddr = 0;
	uintptr_t carrotAddr = 0,wineAddr = 0,gameSpeedAddr = 0;

	uintptr_t iArmorAddr = 0, lArmorAddr = 0, bowAddr = 0, crossbAddr = 0, swordsAddr = 0, macesAddr = 0, pikesAddr = 0, spearsAddr = 0;
	bool bMoney = false,bResources = false, bFood = false, bArmory = false;
	const float newMoneyVal = 3152;
	const int newCrownVal = 3152;
	procId = GetProcessId(L"Stronghold2.exe");
	if (procId)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
		moduleBase = GetModuleBaseAddr(procId, L"Stronghold2.exe");
		LocalPlayer = moduleBase + 0x006E8C60;
		moneyAddr = FindDMAAddy(hProcess, LocalPlayer, { 0x1010 });
		crownAddr = FindDMAAddy(hProcess, LocalPlayer, { 0x1c });
		happinessAddr = FindDMAAddy(hProcess, LocalPlayer, { 0x1028 });
		peasantTotalAddr = FindDMAAddy(hProcess, LocalPlayer, { 0x1030 });
		ironAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF68 });
		stoneAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF64 });
		woodAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF60 }); 
		candleAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF84 });
		gameSpeedAddr = (uintptr_t)"Stronghold2.exe" + 0xE46518;
		//food
		wheatAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF6C });
		flourAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF70 });
		hopAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF74 });
		beerAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF78 });
		grapeAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF7C });
		lordFishAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF94 });
		duckAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xF98 });
		pigAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFA0 });
		carrotAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFA4 });
		wineAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFA8 });
		breadAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFB8 });
		meatAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFC0 });
		appleAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFB4 });
		cheeseAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFBC });
		//Armory
		iArmorAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFEC });
		lArmorAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFF0 });
		bowAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFD4 });
		crossbAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFD8 });
		swordsAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFDC });
		macesAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFE0 });
		pikesAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFE4 });
		spearsAddr = FindDMAAddy(hProcess, LocalPlayer, { 0xFE8 });
	}
	else
	{
		std::cout << "Game has not been found! Please start the game!" << std::endl;
		std::cin.get();
	}
	// printMenuInfo();
	DWORD dwExit = 0;
	while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
	{
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			bMoney = !bMoney;
		}
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			bResources = !bResources;
		}
		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			bFood = !bFood;
		}
		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			bArmory = !bArmory;
		}
		if (bMoney)
		{
			mem::PatchEx((BYTE*)moneyAddr, (BYTE*)&newMoneyVal, sizeof(newMoneyVal), hProcess);
			mem::PatchEx((BYTE*)crownAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)happinessAddr, (BYTE*)&newMoneyVal, sizeof(newMoneyVal), hProcess);
			mem::PatchEx((BYTE*)peasantTotalAddr, (BYTE*)&newCrownVal, sizeof(newMoneyVal), hProcess);
		}
		if (bResources)
		{
			mem::PatchEx((BYTE*)ironAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)woodAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)stoneAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)candleAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
		}
		if (bFood)
		{
			mem::PatchEx((BYTE*)wheatAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)flourAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)hopAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)beerAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)grapeAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)lordFishAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)duckAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)pigAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)carrotAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)wineAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			// 
			mem::PatchEx((BYTE*)meatAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)cheeseAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)appleAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)breadAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
		}
		if (bArmory)
		{
			mem::PatchEx((BYTE*)iArmorAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)lArmorAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)bowAddr,	(BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)crossbAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);			
			mem::PatchEx((BYTE*)swordsAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)macesAddr,	(BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)pikesAddr,	(BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
			mem::PatchEx((BYTE*)spearsAddr, (BYTE*)&newCrownVal, sizeof(newCrownVal), hProcess);
		}
	}
	std::cout << "Game has not been found!" << std::endl;

}

