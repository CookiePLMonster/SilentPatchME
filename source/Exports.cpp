#include <d3dx9.h>
#include <mutex>
#include <Shlwapi.h>

#pragma comment(lib, "Shlwapi.lib")

// These exports implement a bare minimum required for Mass Effect
// In the case where this wrapper is needed for a different game,
// extending this file and the .def file with more exports should be enough.

// Init functions declarations
static decltype(D3DXUVAtlasCreate) D3DXUVAtlasCreate_init;
static decltype(D3DXWeldVertices) D3DXWeldVertices_init;
static decltype(D3DXSimplifyMesh) D3DXSimplifyMesh_init;
static decltype(D3DXDebugMute) D3DXDebugMute_init;
static decltype(D3DXCleanMesh) D3DXCleanMesh_init;
static decltype(D3DXDisassembleShader) D3DXDisassembleShader_init;
static decltype(D3DXCompileShader) D3DXCompileShader_init;
static decltype(D3DXAssembleShader) D3DXAssembleShader_init;
static decltype(D3DXLoadSurfaceFromMemory) D3DXLoadSurfaceFromMemory_init;
static decltype(D3DXPreprocessShader) D3DXPreprocessShader_init;
static decltype(D3DXCreateMesh) D3DXCreateMesh_init;


// Export function pointers
auto pD3DXUVAtlasCreate = D3DXUVAtlasCreate_init;
auto pD3DXWeldVertices = D3DXWeldVertices_init;
auto pD3DXSimplifyMesh = D3DXSimplifyMesh_init;
auto pD3DXDebugMute = D3DXDebugMute_init;
auto pD3DXCleanMesh = D3DXCleanMesh_init;
auto pD3DXDisassembleShader = D3DXDisassembleShader_init;
auto pD3DXCompileShader = D3DXCompileShader_init;
auto pD3DXAssembleShader = D3DXAssembleShader_init;
auto pD3DXLoadSurfaceFromMemory = D3DXLoadSurfaceFromMemory_init;
auto pD3DXPreprocessShader = D3DXPreprocessShader_init;
auto pD3DXCreateMesh = D3DXCreateMesh_init;


// Init function
std::once_flag initFlag;
static void D3DX_InitExports()
{
    std::call_once(initFlag, [] {
        wchar_t dllPath[MAX_PATH];
        GetSystemDirectoryW(dllPath, MAX_PATH);
        PathAppendW(dllPath, L"d3dx9_31.dll");

        HMODULE d3dx9 = LoadLibraryW(dllPath);
        if (d3dx9 == nullptr)
        {
            // Everything will be broken, don't bother recovering
            std::terminate();
        }

        pD3DXUVAtlasCreate = reinterpret_cast<decltype(pD3DXUVAtlasCreate)>(GetProcAddress(d3dx9, "D3DXUVAtlasCreate"));
        pD3DXWeldVertices = reinterpret_cast<decltype(pD3DXWeldVertices)>(GetProcAddress(d3dx9, "D3DXWeldVertices"));
        pD3DXSimplifyMesh = reinterpret_cast<decltype(pD3DXSimplifyMesh)>(GetProcAddress(d3dx9, "D3DXSimplifyMesh"));
        pD3DXDebugMute = reinterpret_cast<decltype(pD3DXDebugMute)>(GetProcAddress(d3dx9, "D3DXDebugMute"));
        pD3DXCleanMesh = reinterpret_cast<decltype(pD3DXCleanMesh)>(GetProcAddress(d3dx9, "D3DXCleanMesh"));
        pD3DXDisassembleShader = reinterpret_cast<decltype(pD3DXDisassembleShader)>(GetProcAddress(d3dx9, "D3DXDisassembleShader"));
        pD3DXCompileShader = reinterpret_cast<decltype(pD3DXCompileShader)>(GetProcAddress(d3dx9, "D3DXCompileShader"));
        pD3DXAssembleShader = reinterpret_cast<decltype(pD3DXAssembleShader)>(GetProcAddress(d3dx9, "D3DXAssembleShader"));
        pD3DXLoadSurfaceFromMemory = reinterpret_cast<decltype(pD3DXLoadSurfaceFromMemory)>(GetProcAddress(d3dx9, "D3DXLoadSurfaceFromMemory"));
        pD3DXPreprocessShader = reinterpret_cast<decltype(pD3DXPreprocessShader)>(GetProcAddress(d3dx9, "D3DXPreprocessShader"));
        pD3DXCreateMesh = reinterpret_cast<decltype(pD3DXCreateMesh)>(GetProcAddress(d3dx9, "D3DXCreateMesh"));

        // Leak the DLL handle deliberately
    });
}


// Init functions definitions
static HRESULT WINAPI D3DXUVAtlasCreate_init(LPD3DXMESH pMesh, UINT uMaxChartNumber, FLOAT fMaxStretch, UINT uWidth, UINT uHeight, FLOAT fGutter, DWORD dwTextureIndex,
                        CONST DWORD *pdwAdjacency, CONST DWORD *pdwFalseEdgeAdjacency, CONST FLOAT *pfIMTArray, LPD3DXUVATLASCB pStatusCallback, FLOAT fCallbackFrequency,
                        LPVOID pUserContext, DWORD dwOptions, LPD3DXMESH *ppMeshOut, LPD3DXBUFFER *ppFacePartitioning, LPD3DXBUFFER *ppVertexRemapArray, FLOAT *pfMaxStretchOut, UINT *puNumChartsOut)
{
    D3DX_InitExports();
    return pD3DXUVAtlasCreate(pMesh, uMaxChartNumber, fMaxStretch, uWidth, uHeight, fGutter, dwTextureIndex, pdwAdjacency, pdwFalseEdgeAdjacency, pfIMTArray, pStatusCallback,
                                fCallbackFrequency, pUserContext, dwOptions, ppMeshOut, ppFacePartitioning, ppVertexRemapArray, pfMaxStretchOut, puNumChartsOut);
}

static HRESULT WINAPI D3DXWeldVertices_init(LPD3DXMESH pMesh, DWORD Flags, CONST D3DXWELDEPSILONS *pEpsilons, CONST DWORD *pAdjacencyIn, DWORD *pAdjacencyOut, DWORD *pFaceRemap, LPD3DXBUFFER *ppVertexRemap)
{
    D3DX_InitExports();
    return pD3DXWeldVertices(pMesh, Flags, pEpsilons, pAdjacencyIn, pAdjacencyOut, pFaceRemap, ppVertexRemap);
}

static HRESULT WINAPI D3DXSimplifyMesh_init(LPD3DXMESH pMesh, CONST DWORD* pAdjacency, CONST D3DXATTRIBUTEWEIGHTS *pVertexAttributeWeights, CONST FLOAT *pVertexWeights, DWORD MinValue,
                        DWORD Options, LPD3DXMESH* ppMesh)
{
    D3DX_InitExports();
    return pD3DXSimplifyMesh(pMesh, pAdjacency, pVertexAttributeWeights, pVertexWeights, MinValue, Options, ppMesh);
}

static BOOL WINAPI D3DXDebugMute_init(BOOL Mute)
{
    D3DX_InitExports();
    return pD3DXDebugMute(Mute);
}

static HRESULT WINAPI D3DXCleanMesh_init(D3DXCLEANTYPE CleanType, LPD3DXMESH pMeshIn, CONST DWORD* pAdjacencyIn, LPD3DXMESH* ppMeshOut, DWORD* pAdjacencyOut, LPD3DXBUFFER* ppErrorsAndWarnings)
{
    D3DX_InitExports();
    return pD3DXCleanMesh(CleanType, pMeshIn, pAdjacencyIn, ppMeshOut, pAdjacencyOut, ppErrorsAndWarnings);
}

static HRESULT WINAPI D3DXDisassembleShader_init(CONST DWORD* pShader, BOOL EnableColorCode, LPCSTR pComments, LPD3DXBUFFER* ppDisassembly)
{
    D3DX_InitExports();
    return pD3DXDisassembleShader(pShader, EnableColorCode, pComments, ppDisassembly);
}

static HRESULT WINAPI D3DXCompileShader_init(LPCSTR pSrcData, UINT SrcDataLen, CONST D3DXMACRO* pDefines, LPD3DXINCLUDE pInclude, LPCSTR pFunctionName, LPCSTR pProfile, DWORD Flags, LPD3DXBUFFER* ppShader,
                        LPD3DXBUFFER* ppErrorMsgs, LPD3DXCONSTANTTABLE* ppConstantTable)
{
    D3DX_InitExports();
    return pD3DXCompileShader(pSrcData, SrcDataLen, pDefines, pInclude, pFunctionName, pProfile, Flags, ppShader, ppErrorMsgs, ppConstantTable);
}

static HRESULT WINAPI D3DXAssembleShader_init(LPCSTR pSrcData, UINT SrcDataLen, CONST D3DXMACRO* pDefines, LPD3DXINCLUDE pInclude, DWORD Flags, LPD3DXBUFFER* ppShader, LPD3DXBUFFER* ppErrorMsgs)
{
    D3DX_InitExports();
    return pD3DXAssembleShader(pSrcData, SrcDataLen, pDefines, pInclude, Flags, ppShader, ppErrorMsgs);
}

static HRESULT WINAPI D3DXLoadSurfaceFromMemory_init(LPDIRECT3DSURFACE9 pDestSurface, CONST PALETTEENTRY* pDestPalette, CONST RECT* pDestRect, LPCVOID pSrcMemory, D3DFORMAT SrcFormat, UINT SrcPitch,
                        CONST PALETTEENTRY* pSrcPalette, CONST RECT* pSrcRect, DWORD Filter, D3DCOLOR ColorKey)
{
    D3DX_InitExports();
    return pD3DXLoadSurfaceFromMemory(pDestSurface, pDestPalette, pDestRect, pSrcMemory, SrcFormat, SrcPitch, pSrcPalette, pSrcRect, Filter, ColorKey);
}

static HRESULT WINAPI D3DXPreprocessShader_init(LPCSTR pSrcData, UINT SrcDataSize, CONST D3DXMACRO* pDefines, LPD3DXINCLUDE pInclude, LPD3DXBUFFER* ppShaderText, LPD3DXBUFFER* ppErrorMsgs)
{
    D3DX_InitExports();
    return pD3DXPreprocessShader(pSrcData, SrcDataSize, pDefines, pInclude, ppShaderText, ppErrorMsgs);
}

static HRESULT WINAPI D3DXCreateMesh_init(DWORD NumFaces, DWORD NumVertices, DWORD Options, CONST D3DVERTEXELEMENT9 *pDeclaration, LPDIRECT3DDEVICE9 pD3DDevice, LPD3DXMESH* ppMesh)
{
    D3DX_InitExports();
    return pD3DXCreateMesh(NumFaces, NumVertices, Options, pDeclaration, pD3DDevice, ppMesh);
}


// Exports
HRESULT WINAPI D3DXUVAtlasCreate_Export(LPD3DXMESH pMesh, UINT uMaxChartNumber, FLOAT fMaxStretch, UINT uWidth, UINT uHeight, FLOAT fGutter, DWORD dwTextureIndex,
                        CONST DWORD *pdwAdjacency, CONST DWORD *pdwFalseEdgeAdjacency, CONST FLOAT *pfIMTArray, LPD3DXUVATLASCB pStatusCallback, FLOAT fCallbackFrequency,
                        LPVOID pUserContext, DWORD dwOptions, LPD3DXMESH *ppMeshOut, LPD3DXBUFFER *ppFacePartitioning, LPD3DXBUFFER *ppVertexRemapArray, FLOAT *pfMaxStretchOut, UINT *puNumChartsOut)
{
    return pD3DXUVAtlasCreate(pMesh, uMaxChartNumber, fMaxStretch, uWidth, uHeight, fGutter, dwTextureIndex, pdwAdjacency, pdwFalseEdgeAdjacency, pfIMTArray, pStatusCallback,
                                fCallbackFrequency, pUserContext, dwOptions, ppMeshOut, ppFacePartitioning, ppVertexRemapArray, pfMaxStretchOut, puNumChartsOut);
}

HRESULT WINAPI D3DXWeldVertices_Export(LPD3DXMESH pMesh, DWORD Flags, CONST D3DXWELDEPSILONS *pEpsilons, CONST DWORD *pAdjacencyIn, DWORD *pAdjacencyOut, DWORD *pFaceRemap, LPD3DXBUFFER *ppVertexRemap)
{
    return pD3DXWeldVertices(pMesh, Flags, pEpsilons, pAdjacencyIn, pAdjacencyOut, pFaceRemap, ppVertexRemap);
}

HRESULT WINAPI D3DXSimplifyMesh_Export(LPD3DXMESH pMesh, CONST DWORD* pAdjacency, CONST D3DXATTRIBUTEWEIGHTS *pVertexAttributeWeights, CONST FLOAT *pVertexWeights, DWORD MinValue,
                        DWORD Options, LPD3DXMESH* ppMesh)
{
    return pD3DXSimplifyMesh(pMesh, pAdjacency, pVertexAttributeWeights, pVertexWeights, MinValue, Options, ppMesh);
}

BOOL WINAPI D3DXDebugMute_Export(BOOL Mute)
{
    return pD3DXDebugMute(Mute);
}

HRESULT WINAPI D3DXCleanMesh_Export(D3DXCLEANTYPE CleanType, LPD3DXMESH pMeshIn, CONST DWORD* pAdjacencyIn, LPD3DXMESH* ppMeshOut, DWORD* pAdjacencyOut, LPD3DXBUFFER* ppErrorsAndWarnings)
{
    return pD3DXCleanMesh(CleanType, pMeshIn, pAdjacencyIn, ppMeshOut, pAdjacencyOut, ppErrorsAndWarnings);
}

HRESULT WINAPI D3DXDisassembleShader_Export(CONST DWORD* pShader, BOOL EnableColorCode, LPCSTR pComments, LPD3DXBUFFER* ppDisassembly)
{
    return pD3DXDisassembleShader(pShader, EnableColorCode, pComments, ppDisassembly);
}

HRESULT WINAPI D3DXCompileShader_Export(LPCSTR pSrcData, UINT SrcDataLen, CONST D3DXMACRO* pDefines, LPD3DXINCLUDE pInclude, LPCSTR pFunctionName, LPCSTR pProfile, DWORD Flags, LPD3DXBUFFER* ppShader,
                        LPD3DXBUFFER* ppErrorMsgs, LPD3DXCONSTANTTABLE* ppConstantTable)
{
    return pD3DXCompileShader(pSrcData, SrcDataLen, pDefines, pInclude, pFunctionName, pProfile, Flags, ppShader, ppErrorMsgs, ppConstantTable);
}

HRESULT WINAPI D3DXAssembleShader_Export(LPCSTR pSrcData, UINT SrcDataLen, CONST D3DXMACRO* pDefines, LPD3DXINCLUDE pInclude, DWORD Flags, LPD3DXBUFFER* ppShader, LPD3DXBUFFER* ppErrorMsgs)
{
    return pD3DXAssembleShader(pSrcData, SrcDataLen, pDefines, pInclude, Flags, ppShader, ppErrorMsgs);
}

HRESULT WINAPI D3DXLoadSurfaceFromMemory_Export(LPDIRECT3DSURFACE9 pDestSurface, CONST PALETTEENTRY* pDestPalette, CONST RECT* pDestRect, LPCVOID pSrcMemory, D3DFORMAT SrcFormat, UINT SrcPitch,
                        CONST PALETTEENTRY* pSrcPalette, CONST RECT* pSrcRect, DWORD Filter, D3DCOLOR ColorKey)
{
    return pD3DXLoadSurfaceFromMemory(pDestSurface, pDestPalette, pDestRect, pSrcMemory, SrcFormat, SrcPitch, pSrcPalette, pSrcRect, Filter, ColorKey);
}

HRESULT WINAPI D3DXPreprocessShader_Export(LPCSTR pSrcData, UINT SrcDataSize, CONST D3DXMACRO* pDefines, LPD3DXINCLUDE pInclude, LPD3DXBUFFER* ppShaderText, LPD3DXBUFFER* ppErrorMsgs)
{
    return pD3DXPreprocessShader(pSrcData, SrcDataSize, pDefines, pInclude, ppShaderText, ppErrorMsgs);
}

HRESULT WINAPI D3DXCreateMesh_Export(DWORD NumFaces, DWORD NumVertices, DWORD Options, CONST D3DVERTEXELEMENT9 *pDeclaration, LPDIRECT3DDEVICE9 pD3DDevice, LPD3DXMESH* ppMesh)
{
    return pD3DXCreateMesh(NumFaces, NumVertices, Options, pDeclaration, pD3DDevice, ppMesh);
}