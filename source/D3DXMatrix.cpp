#include <d3dx9.h>
#include <DirectXMath.h>
#include <cmath>

// D3DX Matrix functions implemented in the means of DirectXMath

using namespace DirectX;

D3DXMATRIX* WINAPI D3DXMatrixInverse_XM(D3DXMATRIX *pOut, FLOAT *pDeterminant, CONST D3DXMATRIX *pM)
{
	XMVECTOR determinant;
	const XMMATRIX out = XMMatrixInverse(&determinant, XMMATRIX(static_cast<const float*>(*pM)));
	const float det = XMVectorGetX(determinant);

	// Mirror the behaviour of D3DXMatrixInverse
	if (det == 0.0f || !std::isfinite(1.0f / det))
	{
		return nullptr;
	}

	if (pDeterminant != nullptr)
	{
		*pDeterminant = det;
	}
	*pOut = *reinterpret_cast<const D3DXMATRIX*>(&out);
	return pOut;
}