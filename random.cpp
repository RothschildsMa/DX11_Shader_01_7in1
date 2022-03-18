#include "random.h"

unsigned int Random::d = 2531011L;

//źÌæŸ
unsigned int Random::FastNRand(void)
{
	return(((d *= 16807) >> 16) & 0x7fff);
}


//źŹÌæŸ
float Random::FastFRand(void)
{
	unsigned int res = ((d *= 16807) >> 9) | 0x3f800000;

	return (*(float*)&res) - 1.0f;
}

//źÌæŸ(ÍÍwèĆa ` b-1)
int Random::GetRandom(int a, int b)
{
	if (a >= b) return a;

	return(FastNRand() % ((b - a) + 1)) + a;
}

//źŹÌæŸ(ÍÍwèĆ)
float Random::GetRandom(float a, float b)
{
	if (a >= b) return a;

	float f = FastFRand();
	return (f*(b - a)) + a;
}

//xNgÌæŸ
D3DXVECTOR3& Random::GetRandom(D3DXVECTOR3& out)
{
	out.x = GetRandom(-1.0f, 1.0f);
	out.y = GetRandom(-1.0f, 1.0f);
	out.z = GetRandom(-1.0f, 1.0f);

	D3DXVec3Normalize(&out, &out);

	return out;
}
