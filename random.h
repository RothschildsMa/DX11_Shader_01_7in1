#pragma once

#include"main.h"

class Random
{
private:
	static unsigned int d;

public:

	static unsigned int FastNRand(void);		//źÌæŸ
	static float FastFRand(void);				//źŹÌæŸ
	static int GetRandom(int a, int b);			//źÌæŸ(ÍÍwèĆa ` b-1)
	static float GetRandom(float a, float b);	//źŹÌæŸ(ÍÍwèĆ)
	static D3DXVECTOR3& GetRandom(D3DXVECTOR3& out);	//xNgÌæŸ

};