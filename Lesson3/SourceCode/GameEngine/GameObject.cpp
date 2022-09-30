#include "GameObject.h"
#include "GameObject.h"

void GameObject::SetPosition(float x, float y, float z)
{
	m_vPosition[0] = x;
	m_vPosition[1] = y;
	m_vPosition[2] = z;

	m_pRenderProxy->SetPosition(m_vPosition);
}

float GameObject::Get_X()
{
	return this->m_vPosition[0];
};

float GameObject::Get_Y()
{
	return this->m_vPosition[1];
};

float GameObject::Get_Z()
{
	return this->m_vPosition[2];
};

float GameObject::Get_Vx()
{
	return this->m_vVelocity[0];
};

float GameObject::Get_Vy()
{
	return this->m_vVelocity[1];
};

float GameObject::Get_Vz()
{
	return this->m_vVelocity[2];
};

float GameObject::Get_Ax()
{
	return this->m_vAcceleration[0];
};

float GameObject::Get_Ay()
{
	return this->m_vAcceleration[1];
};

float GameObject::Get_Az()
{
	return this->m_vAcceleration[2];
};

float GameObject::Get_M()
{
	return this->m_vMass;
};

int GameObject::Get_Type()
{
	return this->type; // 0 - physics on, 1 - movement tuda-suda, 2 - controls on
}