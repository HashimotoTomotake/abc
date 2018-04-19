#include <CommonStates.h>
#include "DrawManager.h"

using namespace System;

/// <summary>
/// ����������
/// </summary>
/// <param name="devise">�f�o�C�X</param>
void DrawManager::Initialize(ID3D11Device1* pDevise, ID3D11DeviceContext1* pContext)
{
	SetDevise(pDevise);

	mSpriteBatch = std::make_unique<DirectX::SpriteBatch>(pContext);
}

/// <summary>
/// �`��
/// </summary>
/// <param name="data">�`��f�[�^�\����</param>
void DrawManager::Draw(DrawData& data)
{
	mSpriteBatch->Draw(data.texture.Get(), data.pos);
}

/// <summary>
/// �`��O�㏈��
/// </summary>
void DrawManager::Begin()
{
	DirectX::CommonStates states(mpDevice);

	mSpriteBatch->Begin(DirectX::SpriteSortMode_Deferred, states.NonPremultiplied());
}
void DrawManager::End()
{
	mSpriteBatch->End();
}

/// <summary>
/// �e�N�X�`���ǂݍ���
/// </summary>
/// <param name="pData">�`��f�[�^�\����</param>
/// <param name="fileName">�t�@�C����</param>
/// <returns>�������ǂ���</returns>
bool DrawManager::LoadTexture(DrawData& pData, wchar_t* pFileName)
{
	// �f�o�C�X�������̂Ŏ��s
	if (mpDevice == NULL)
	{
		return false;
	}

	DX::ThrowIfFailed
	(
		DirectX::CreateWICTextureFromFile
		(
			mpDevice,
			pFileName,
			nullptr,
			pData.texture.ReleaseAndGetAddressOf()
		)
	);

	return false;
}