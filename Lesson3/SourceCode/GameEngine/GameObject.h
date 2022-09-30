#pragma once

#include "Common.h"
#include "RenderProxy.h"

class GameObject
{
public:
	GameObject() = default;

	~GameObject()
	{
		delete m_pRenderProxy;
	}
	float Get_X();
	float Get_Y();
	float Get_Z();
	float Get_Vx();
	float Get_Vy();
	float Get_Vz();
	float Get_Ax();
	float Get_Ay();
	float Get_Az();
	float Get_M();
	int   Get_Type();

	void SetPosition(float x, float y, float z);
	void SetVelocity(float x, float y, float z)
	{
		this->m_vVelocity[0] = x;
		this->m_vVelocity[1] = y;
		this->m_vVelocity[2] = z;
	};
	void SetMass(float m)
	{
		this->m_vMass = m;
	};
	void SetAcceleration(float x, float y, float z)
	{
		this->m_vAcceleration[0] = x;
		this->m_vAcceleration[1] = y;
		this->m_vAcceleration[2] = z;
	}
	void SetType(int in)
	{
		this->type = in;
	}

	RenderProxy* const GetRenderProxy() { return m_pRenderProxy; }
protected:
	RenderProxy* m_pRenderProxy;
	float m_vVelocity[3];
	float m_vMass;
	float m_vPosition[3];
	float m_vAcceleration[3];
	int type; // 0 - physics on, 1 - movement tuda-suda, 2 - controls on
};

