#pragma once
#include <vector>
#include "../RenderObject.h"

namespace
{
	struct PosColorVertex
	{
		float m_x;
		float m_y;
		float m_z;
		uint32_t m_abgr;
	};
};

class Cube : public RenderObject
{
public:
	Cube();
	~Cube();
	
private:
	
	inline static const PosColorVertex s_cubeVertices[] =
	{
		{-1.0f,  1.0f, -1.0f, 0xffff0000 }, //0
		{ 1.0f,  1.0f, -1.0f, 0xffff00ff }, //1
		{-1.0f, -1.0f, -1.0f, 0xffffff00 }, //2
		{ 1.0f, -1.0f, -1.0f, 0xffffffff }, //3
		{ 0.0f,  0.0f,  1.0f, 0xff000000 }, //4
	};
	
	inline static const uint16_t s_cubeTriList[] =
	{
		0, 3, 1, // osnovanie
		3, 0, 2,
		0, 1, 4,
		0, 4, 2,
		3, 2, 4,
		3, 4, 1,
		//3, 0, 1,
		//0, 3, 2, // osnovanie
		//1, 0, 4,
		//4, 0, 2,
		//2, 3, 4,
		//4, 3, 1
	};
};

