#pragma once




DWORD GetProcessId(const wchar_t* procName);

uintptr_t GetModuleBaseAddr(DWORD procId, const wchar_t* modName);

uintptr_t FindDMAAddy(HANDLE hProcess, uintptr_t ptr, std::vector<unsigned int>offsets);

