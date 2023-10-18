/*************************************************************************//*!
					
					@file	DecryptFile.h
					@brief	ファイル複合化を取り扱う基底インターフェイス

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DECRYPTFILE__H__

#define		__DECRYPTFILE__H__

//INCLUDE
#include	"String.h"

namespace Mof {

	/*******************************//*!
	@brief	ファイル複合化基底インターフェイス

			ファイル複合化を取り扱う基底インターフェイス

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IDecryptFile : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			複合化
				@param[in]		pData		ファイルデータ
				@param[in]		Size		ファイルサイズ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Decrypt(LPMofU8* pData, MofU32& Size) = 0;
	};
	typedef IDecryptFile* LPDecryptFile;
	
	/*******************************//*!
	@brief	XORファイル複合化

			ファイル複合化を取り扱うクラス

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXORKeyDecryptFile : public IDecryptFile {
	protected:
		/*******************//*!
		複合化用キー
		*//********************/
		MofU8					m_Key;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		key			キー

				@return			None
		*//**************************************************************************/
		CXORKeyDecryptFile(MofU8 key);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXORKeyDecryptFile();

		/*************************************************************************//*!
				@brief			複合化
				@param[in]		pData		ファイルデータ
				@param[in]		Size		ファイルサイズ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Decrypt(LPMofU8* pData, MofU32& Size);

		//クラス基本定義
		MOF_LIBRARYCLASS(CXORKeyDecryptFile, MOF_DECRYPTFILECLASS_ID);
	};

}

#endif

//[EOF]