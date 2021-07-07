#pragma once

#ifdef DLLEXPORTS
#define PUBLIC_API __declspec(dllexport)
#else
#define PUBLIC_API __declspec(dllimport)
#endif

#ifndef NULL
#define NULL 0
#endif

namespace SpriteGameToolkit
{
	typedef unsigned char byte;
	typedef unsigned short ushort;
	typedef unsigned int uint;
}
