#include <d3dx9.h>
#include <DirectXMath.h>

// D3DX Matrix functions implemented in the means of DirectXMath

using namespace DirectX;

D3DXMATRIX* WINAPI D3DXMatrixInverse_XM(D3DXMATRIX *pOut, FLOAT *pDeterminant, CONST D3DXMATRIX *pM)
{
	XMVECTOR determinant;
	const XMMATRIX out = XMMatrixInverse(&determinant, XMMATRIX(static_cast<const float*>(*pM)));

	*pOut = *reinterpret_cast<const D3DXMATRIX*>(&out);
	if (pDeterminant != nullptr)
	{
		*pDeterminant = XMVectorGetX(determinant);
	}
	return pOut;
}