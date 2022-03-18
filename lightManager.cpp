

#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "myGui.h"


#include "lightManager.h"

void LightManager::Init()
{
	
	m_Light.Enable = true;
	m_Light.Direction = { 1.0f, -1.0f, 1.0f, 0.0f };
	m_Light.Direction = XMVector4Normalize(m_Light.Direction);
	m_Light.Ambient = { 0.2f, 0.2f, 0.2f, 1.0f };
	m_Light.Diffuse = { 1.0f, 1.0f, 1.0f, 1.0f };


}

void LightManager::Uninit()
{
}

void LightManager::Update()
{
}

void LightManager::Draw()
{
	Renderer::GetInstance().SetLight(m_Light);
	
}
