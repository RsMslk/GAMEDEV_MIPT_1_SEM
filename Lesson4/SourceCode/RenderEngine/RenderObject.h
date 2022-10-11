#pragma once

#include "Common.h"
#include "RenderProxy.h"
#include "../RenderBackend/IRenderData.h"

class RENDERENGINE_API RenderObject
{
public:
	RenderObject(RenderProxy* pRenderProxy) :
		m_pRenderProxy(pRenderProxy),
		m_pRenderData(nullptr)
	{}

	virtual void* GetVertices() const = 0;
	virtual UINT32 GetVerticesSize() const = 0;
	virtual void* GetIndices() const = 0;
	virtual UINT32 GetIndicesSize() const = 0;
	virtual std::string GetVsShaderName() const = 0;
	virtual std::string GetPsShaderName() const = 0;

	void GetPosition(float* result) { m_pRenderProxy->GetPosition(result); }
	IRenderData* GetRenderData() const { return m_pRenderData; }
	bool Is_Visible() { return m_pRenderProxy->Is_Visible(); }
	void SetRenderData(IRenderData* renderData) { m_pRenderData = renderData; }
	void Set_is_Visible(bool in) { m_pRenderProxy->Set_is_Visible(in); }
	

protected:
	RenderProxy* m_pRenderProxy;
	IRenderData* m_pRenderData;
};

