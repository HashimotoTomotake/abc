#pragma once

#include <list>

#include "Utility\SingletonBase.h"

#include "WICTextureLoader.h"
#include "SimpleMath.h"
#include "SpriteBatch.h"

namespace System
{
	struct DrawData
	{
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
		DirectX::SimpleMath::Vector2 pos;
	};

	class DrawManager : public Utility::SingletonBase<DrawManager>
	{
	public:

		friend class Utility::SingletonBase<DrawManager>;

	protected:

		DrawManager() {};
		~DrawManager() {};

	public:

		// ����������
		void Initialize(ID3D11Device1* pDevise, ID3D11DeviceContext1* pContext);

		// �`��
		void Draw(DrawData& data);

		// �`��O�㏈��
		void Begin();
		void End();

		// �e�N�X�`���ǂݍ���
		bool LoadTexture(DrawData& pData, wchar_t* pFileName);

		// �e�N�X�`���폜
		void DeleteTexture(DrawData& pData);

		// �f�o�C�X�̐ݒ�
		void SetDevise(ID3D11Device1* pDevise)
		{
			mpDevice = pDevise;
		}

		// �f�o�C�X�̎擾
		ID3D11Device1* GetDevise()
		{
			return mpDevice;
		}

	private:

		ID3D11Device1* mpDevice;

		// �X�v���C�g�o�b�`
		std::unique_ptr<DirectX::SpriteBatch> mSpriteBatch;
	};
}