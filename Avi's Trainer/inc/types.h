#pragma once

#include <windows.h>

typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

typedef struct
{
	float x;
	float y;
	float z;
	float w;
} Vector4;
typedef struct
{
	float x;
	float y;
	float z;
} Vector3;
typedef struct
{
	float x;
	float y;
} Vector2;


struct Color {
	int r, g, b, a, f;
};

struct Rect {
	Vector2 pos;
	Vector2 size;
	bool center;
};