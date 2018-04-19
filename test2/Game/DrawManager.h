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

		// 初期化処理
		void Initialize(ID3D11Device1* pDevise, ID3D11DeviceContext1* pContext);

		// 描画
		void Draw(DrawData& data);

		// 描画前後処理
		void Begin();
		void End();

		// テクスチャ読み込み
		bool LoadTexture(DrawData& pData, wchar_t* pFileName);

		// テクスチャ削除
		void DeleteTexture(DrawData& pData);

		// デバイスの設定
		void SetDevise(ID3D11Device1* pDevise)
		{
			mpDevice = pDevise;
		}

		// デバイスの取得
		ID3D11Device1* GetDevise()
		{
			return mpDevice;
		}

	private:

		ID3D11Device1* mpDevice;

		// スプライトバッチ
		std::unique_ptr<DirectX::SpriteBatch> mSpriteBatch;
	};
}