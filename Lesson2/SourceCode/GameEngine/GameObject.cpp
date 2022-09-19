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