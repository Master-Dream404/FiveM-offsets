#pragma once
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <wchar.h>
#include <tchar.h>
#include <random>
#include <sstream>
#include <thread>
#include <Shlwapi.h>
#include <WinUser.h>
#include <ShlObj.h>
#include <string>
/* all offset found on 03-20-2022 */

/*
		uintptr_t citizen_resource_core_module = (uintptr_t)GetModuleHandle("citizen-resources-core.dll");
		uintptr_t net_module = (uintptr_t)GetModuleHandle("net.dll");
		uintptr_t console_module = (uintptr_t)GetModuleHandle("conhost-v2.dll");
*/

namespace functions
{
	class FiveConsole 
	{
	public:
		using Console = void(*)(std::string, std::string);
		using Shbypass = void(*)(bool, __int64, __int64);

		class Server
		{
		public:
			char IP[18];
			char pad_0010[14];
		};

	};
	class Conhost
	{
	private:
		uintptr_t function = 0x1F530;
		uintptr_t ConsoleModule = (uintptr_t)GetModuleHandle("conhost-v2.dll");
	public:
		void Print(const std::string& channel, const std::string& text)
		{
			auto m_console = (FiveConsole::Console)(ConsoleModule + function);
			m_console(channel, text);
		}
	};

	class Net
	{
	private:
		uintptr_t NetModule = (uintptr_t)GetModuleHandle("net.dll");
	public:
		std::string GetAddress()
		{
			FiveConsole::Server* m_Net_manager = (FiveConsole::Server*)(NetModule + 0x1C1A2);

			return m_Net_manager->IP;
		}
	};
	class Discord
	{
	private:
		uintptr_t DiscordModule = (uintptr_t)GetModuleHandle("discord.dll");
	public:
		class value
		{
		public:
			char DiscordName[16]; //0x0000
			char pad_0010[496]; //0x0010
			char DiscordID[32]; //0x0200
			char pad_0220[3648]; //0x0220
		};
		std::string GetDiscordName()
		{
			value* d_manager = (value*)(DiscordModule + 0x822E0);

			return d_manager->DiscordName;
		}
		std::string GetDiscordId()
		{
			value* d_manager = (value*)(DiscordModule + 0x822E0);

			return d_manager->DiscordID;
		}
	};
	class Metadataloader
	{
	private:
		uintptr_t MetaDataLoaderModule = (uintptr_t)GetModuleHandle("citizen-resources-metadata-lua.dll");
		using dofile_ptr_t = __int64(_fastcall*)(__int64, int, int, int, __int64, __int64);
		using LoadFile_call = __int64(*)(__int64 metadataloader, const std::string& filename);
	public:

		class value
		{
			char pad[16];
			__int64 m_st;
		};

		void LoadFile(const char* file)
		{
			auto LoadFile_manager = (LoadFile_call)(MetaDataLoaderModule + 0x187FE8);

			value ob;
			value* metadata_ptr = &obj;

			LoadFile_manager((__int64)metadata_ptr, file);

		}
	};
	class Resourcecore
	{
	private:
		uintptr_t ResourcecoreModule = (uintptr_t)GetModuleHandle("citizen-resources-core.dll");
	public:
		// nop i am not making this agen find it in my other source code
	};
}

 /*
 to use in otherfiles

functions::Conhost console;
functions::Discord discord;
functions::Metadataloader MetaDataloader;
functions::Net Net;
functions::Resourcecore m_manager;

	std::string serverip = Net.GetAddress();
	console.Print("hi", "Master Dream was here");
	std::string discordName = discord.GetDiscordName();
	MetaDataloader.LoadFile("C:\\Master.lua");

 */
