#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "myGui.h"
#include "input.h"
#include "scene.h"
#include "audio.h"
#include "game.h"
#include "title.h"
#include "singleton.h"
#include "sprite2D.h"
#include "fade.h"
#include "directinput.h"
#include "mousePicker.h"
#include "texture.h"
#include "mouseEvent.h"
#include "debugDraw.h"
#include "sphere.h"

void Manager::Create()
{
	MyDirectInput::CreateInstance();
	MyDirectInput::GetInstance().CreateDeviceInstance();
	Renderer::CreateInstance();
	MyGui::CreateInstance();
	Texture::CreateInstance();
	Sprite2D::CreateInstance();
	MousePicker::CreateInstance();
	MouseEvent::CreateInstance();
	Fade::CreateInstance();
	

}

void Manager::Destory()
{
	Fade::DestroyInstance();
	MouseEvent::DestroyInstance();
	MousePicker::DestroyInstance();
	Sprite2D::DestroyInstance();
	Texture::DestroyInstance();
	MyGui::DestroyInstance();
	Renderer::DestroyInstance();
	MyDirectInput::GetInstance().DestoryDeviceInstance();
	MyDirectInput::DestroyInstance();
}

void Manager::Init()
{
	MyDirectInput::GetInstance().InitInput();
	Input::Init();

	Renderer::GetInstance().Init();
	MyGui::GetInstance().Init();

	Texture::GetInstance().Init();
	Sprite2D::GetInstance().Init();
	MousePicker::GetInstance().Init();
	MouseEvent::GetInstance().Init();
	Fade::GetInstance().Init();

	
	
	Audio::InitMaster();
	Texture::GetInstance().Load();
	Game::Load();
	SetScene<Title>();

}


void Manager::Uninit()
{
	
	m_Scene->Uninit();
	Game::Unload();
	delete m_Scene;

	Audio::UninitMaster();
	Input::Uninit();

	Fade::GetInstance().Uninit();
	MouseEvent::GetInstance().Uninit();
	MousePicker::GetInstance().Uninit();

	Sprite2D::GetInstance().Uninit();
	Texture::GetInstance().Uninit();
	MyGui::GetInstance().Uninit();
	Renderer::GetInstance().Uninit();

	MyDirectInput::GetInstance().ReleaseInput();
	
	
}

void Manager::Update()
{
	MyDirectInput::GetInstance().UpdateInput();
	Input::Update();
	MousePicker::GetInstance().Update();
	MyGui::GetInstance().Update();

	Fade::GetInstance().Update();

	m_Scene->Update();

}

void Manager::Draw()
{
	Renderer::GetInstance().Begin();

	

	m_Scene->Draw();

	Fade::GetInstance().Draw();
	MouseEvent::GetInstance().Draw();

	MyGui::GetInstance().Draw();
	
	MousePicker::GetInstance().Draw();
	
	Renderer::GetInstance().End();
	
}
