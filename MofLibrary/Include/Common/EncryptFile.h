/*************************************************************************//*!
					
					@file	EncryptFile.h
					@brief	ファイル暗号化を取り扱う基底インターフェイス

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ENCRYPTFILE__H__

#define		__ENCRYPTFILE__H__

//INCLUDE
#include	"String.h"

namespace Mof {

	/*******************************//*!
	@brief	ファイル暗号化基底インターフェイス

			ファイル暗号化を取り扱う基底インターフェイス

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IEncryptFile : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			複合化
				@param[in]		pData		ファイルデータ
				@param[in]		Size		ファイルサイズ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Encrypt(LPMofU8* pData, MofU32& Size) = 0;
	};
	typedef IEncryptFile* LPEncryptFile;
	
	/*******************************//*!
	@brief	XORファイル暗号化

			ファイル暗号化を取り扱うクラス

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXORKeyEncryptFile : public IEncryptFile {
	protected:
		/*******************//*!
		暗号化用キー
		*//********************/
		MofU8					m_Key;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		key			キー

				@return			None
		*//**************************************************************************/
		CXORKeyEncryptFile(MofU8 key);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXORKeyEncryptFile();

		/*************************************************************************//*!
				@brief			暗号化
				@param[in]		pData		ファイルデータ
				@param[in]		Size		ファイルサイズ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Encrypt(LPMofU8* pData, MofU32& Size);

		//クラス基本定義
		MOF_LIBRARYCLASS(CXORKeyEncryptFile, MOF_ENCRYPTFILECLASS_ID);
	};

}

#endif

//[EOF]