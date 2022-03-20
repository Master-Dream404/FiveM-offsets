#pragma once

/* all offset found on 03-20-2022 by !Master Dream */

namespace offset
{
	/* net.dll */ 
	uintptr_t serverIP = 0x1C1A2;//for server ip
	uintptr_t g_steam_name = 0xB9050;//get user steam name
	uintptr_t ICoreGameInit = 0xC1680;//ICoreGameInit for FiveM events and (FiveM events)
	
	/* conhost-v2.dll */ 
	uintptr_t c_print = 0x1F530;//Console print
	uintptr_t c_open = 0x66550;//Check if Console is open or closet

	/* discord.dll */
	uintptr_t discordmanager = 0x822E0;// this include discord name and id

	/* citizen-resources-core.dll */
	uintptr_t m_resource_name = 0xB45E;// m_resource = my resource but take it as resource_name
	uintptr_t m_resource_path = 0xB48F;// get resource path
	uintptr_t m_resource_state = 0xB49E;// get the resource state like started or stopped
	uintptr_t m_manager = 0xB480;//resource manager
	uintptr_t m_core = 0x60D9D;//ResourceCore 
	uintptr_t m_stop = 0x1AD40;//resource stop
	uintptr_t m_start = 0x1AC80;//resource start
	
	/* citizen-scrpting-lua.dll */
	uintptr_t r_internal_file = 0x2C960;//RunFileInternal
	uintptr_t l_system_file = 0x1BFD0;//LoadSystemFile
	uintptr_t l_f_internal = 0x14390;//LoadFileInternal
	uintptr_t l_system_file_internal = 0xF;//LoadSystemFileInternal i cant find...
	uintptr_t l_natives_build = 0x1ABB0;//LoadNativesBuild
	uintptr_t LoadFile = 0xA5160;//LoadFile
	uintptr_t DoFile = 0xA5154;//DoFile

	/* citizen-resources-metadata-lua.dll */
	uintptr_t LoadFile = 0x187FE8;//LoadFile
	uintptr_t DoFile = 0x19A8D0;//DoFile

	/* adhesive.dll */
	uintptr_t Nop = 0x62;// to nop a func in a dll

}
