#include "RenderProxy.h"

void RenderProxy::SetPosition(float position[3])
{
	m_vPosition[0] = position[0];
	m_vPosition[1] = position[1];
	m_vPosition[2] = position[2];
}

bool RenderProxy::Is_Visible()
{
	return this.m_is_Visible;
};
void RenderProxy::Set_is_Visible(bool in)
{
	this.m_is_Visible = in;
};