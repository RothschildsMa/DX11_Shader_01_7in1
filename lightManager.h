#pragma once

#include "singleton.h"




class LightManager : public Singleton<LightManager>
{
private:
	LIGHT m_Light;

public:
	void Init();
	void Uninit();
	void Update();
	void Draw();



};





