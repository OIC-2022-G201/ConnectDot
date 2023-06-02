/*************************************************************************//*!
					
					@file	ConvertSpriteStudio.h
					@brief	�X�v���C�g�X�^�W�I��ssae�t�@�C���̕ϊ����s�����߂̃N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTSPRITESTUDIOFILE__H__

#define		__CONVERTSPRITESTUDIOFILE__H__

//INCLUDE
#include	"../MosCommon.h"
#include	"../Texture.h"

#ifdef		MOFLIB_CONVERTSS

#if defined(DEBUG) || defined(_DEBUG)

#if _MSC_VER >= 1910

#pragma comment (lib,"ssloader2017_md32_d.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"ssloader2015_md32_d.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"ssloader2013_md32_d.lib")

#else

#pragma comment (lib,"ssloader_md32_d.lib")

#endif // _MSC_VER == 1800

#else

#if _MSC_VER >= 1910

#pragma comment (lib,"ssloader2017_md32.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"ssloader2015_md32.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"ssloader2013_md32.lib")

#else

#pragma comment (lib,"ssloader_md32.lib")

#endif // _MSC_VER == 1800

#endif

namespace Mof {
	
	/*******************************//*!
	@brief	�X�v���C�g�X�^�W�I�t�@�C���ϊ��N���X

			�X�v���C�g�X�^�W�I��ssae�t�@�C���̕ϊ����s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertSpriteStudio : public CWriteChunkFile {
	private:
		/*******************//*!
		�ϊ��x�[�X�p�X
		*//********************/
		CString				m_Directory;
		/*******************//*!
		�ݒ�
		*//********************/
		SsAnimationSettings	m_Settings;
		/*******************//*!
		�Z���}�b�v�̐�
		*//********************/
		MofU32				m_CellMapCount;
		/*******************//*!
		�Z���}�b�v�̐�
		*//********************/
		MofU32				m_CellMapNum;
		/*******************//*!
		�Z���}�b�v
		*//********************/
		SsCellMap**			m_ppCellMap;
		
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pInName		���̓t�@�C����
				@param[out]		pOutName	�o�̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertSSAE(LPCMofChar pInName,LPCMofChar pOutName);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pInName		���̓t�@�C����
				@param[out]		pOutName	�o�̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertSSEE(LPCMofChar pInName,LPCMofChar pOutName);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pAnim		ssae�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(SsAnimePack* pAnim);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pAnim		ssee�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pSprite		�X�v���C�g
				@param[in]		pModel		�X�v���C�g�i�[���f��
				@param[in]		pAnim		ssee�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(SsPart* pSprite, SsAnimePack* pModel, SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pName		�Z���}�b�v��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertCellMap(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pSprite		�X�v���C�g
				@param[in]		pModel		�X�v���C�g�i�[���f��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertSprite(SsPart* pSprite,SsAnimePack* pModel);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pAnim		ssae�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertAnimation(SsAnimation* pAnim);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pEffect		�G�t�F�N�g
				@param[in]		pAnim		ssee�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertEffect(SsEffectNode* pEffect, SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pSprite		�X�v���C�g
				@param[in]		pModel		�X�v���C�g�i�[���f��
				@param[in]		pEffect		�G�t�F�N�g
				@param[in]		pAnim		ssee�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertEffect(SsPart* pSprite, SsAnimePack* pModel, SsEffectNode* pEffect, SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pEffect		�G�t�F�N�g
				@param[in]		pAnim		ssee�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertEffectParameter(SsEffectNode* pEffect, SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pAnim		ssae�A�j���[�V����
				@param[in]		mt			�ő厞��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertPartAnimation(SsPartAnime* pAnim, int mt);
		/*************************************************************************//*!
				@brief			�L�[�ɕϊ�����
				@param[in]		attr		�����e�[�u��
				@param[in]		mt			�ő厞��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConverFloatKey(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			�L�[�ɕϊ�����
				@param[in]		attr		�����e�[�u��
				@param[in]		mt			�ő厞��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConverBoolKey(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			�L�[�ɕϊ�����
				@param[in]		attr		�����e�[�u��
				@param[in]		mt			�ő厞��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConverS32Key(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			�����񂩂�x�N�g��2�f�[�^�����o��
				@param[in]		str			����
				@param[in]		point		�x�N�g���Q
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertStringToVector2(const std::string& str, Vector2& point);
		/*************************************************************************//*!
				@brief			�����񂩂�x�N�g��4�f�[�^�����o��
				@param[in]		str			����
				@param[in]		color		�x�N�g���S
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertStringToColor(const std::string& str, Vector4& color);
		/*************************************************************************//*!
				@brief			�����񂩂�u�����h�^�[�Q�b�g�����o��
				@param[in]		str			����
				@param[in]		out			�o��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertStringToBlendTarget(const std::string& str, SsColorBlendTarget::_enum& out);
		/*************************************************************************//*!
				@brief			�����񂩂�u�����h�^�[�Q�b�g�����o��
				@param[in]		str			����
				@param[in]		out			�o��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertStringToBlendType(const std::string& str, SsBlendType::_enum& out);
		/*************************************************************************//*!
				@brief			�L�[�ɕϊ�����
				@param[in]		attr		�����e�[�u��
				@param[in]		n			�ԍ�
				@param[in]		mt			�ő厞��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConverVertexKey(SsAttribute* attr, MofU32 n, int mt);
		/*************************************************************************//*!
				@brief			�L�[�ɕϊ�����
				@param[in]		attr		�����e�[�u��
				@param[in]		n			�ԍ�
				@param[in]		mt			�ő厞��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConverColorKey(SsAttribute* attr, MofU32 n, int mt);
		/*************************************************************************//*!
				@brief			�L�[�ɕϊ�����
				@param[in]		attr		�����e�[�u��
				@param[in]		mt			�ő厞��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConverColorRateKey(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			�L�[�ɕϊ�����
				@param[in]		attr		�����e�[�u��
				@param[in]		mt			�ő厞��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConverEffectKey(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			�X�v���C�g�^�C�v��Ǝ��`���ɕϊ�����
				@param[in]		t			SpriteStudio�̃X�v���C�g�^�C�v
				
				@return			�Ǝ��`���ł̃X�v���C�g�^�C�v
		*//**************************************************************************/
		MofU32 ConvertSpriteType(SsPartType::_enum t);
		/*************************************************************************//*!
				@brief			�G�t�F�N�g�^�C�v��Ǝ��`���ɕϊ�����
				@param[in]		t			SpriteStudio�̃G�t�F�N�g�^�C�v
				
				@return			�Ǝ��`���ł̃X�v���C�g�^�C�v
		*//**************************************************************************/
		MofU32 ConvertEffectType(SsEffectNodeType::_enum t);
		/*************************************************************************//*!
				@brief			�u�����f�B���O���@��Ǝ��`���ɕϊ�����
				@param[in]		t			SpriteStudio�̃u�����f�B���O�^�C�v
				
				@return			�Ǝ��`���ł̃u�����f�B���O���@
		*//**************************************************************************/
		MofU32 ConvertBlendingType(SsBlendType::_enum t);
		/*************************************************************************//*!
				@brief			�u�����f�B���O���@��Ǝ��`���ɕϊ�����
				@param[in]		t			SpriteStudio�̃u�����f�B���O�^�C�v
				
				@return			�Ǝ��`���ł̃u�����f�B���O���@
		*//**************************************************************************/
		MofU32 ConvertBlendingType(SsRenderBlendType::_enum t);
		/*************************************************************************//*!
				@brief			�L�[�^�C�v��Ǝ��`���ɕϊ�����
				@param[in]		t			SpriteStudio�̃L�[�^�C�v
				
				@return			�Ǝ��`���ł̃L�[�^�C�v
		*//**************************************************************************/
		MofU32 ConvertKeyType(SsAttributeKind::_enum t);
		/*************************************************************************//*!
				@brief			�L�[��ԃ^�C�v��Ǝ��`���ɕϊ�����
				@param[in]		t			SpriteStudio�̃L�[��ԃ^�C�v
				
				@return			�Ǝ��`���ł̃L�[�^�C�v
		*//**************************************************************************/
		MofU32 ConvertKeyInterpolationType(SsInterpolationType::_enum t);
		/*************************************************************************//*!
				@brief			��ԏ��ɕϊ�����
				@param[in]		pKey		�L�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertKeyInterpolation(SsKeyframe* pKey);
		
		/*************************************************************************//*!
				@brief			�Ώۃp�[�c�̍ŏ��̃Z���}�b�v�����擾
				@param[in]		pSprite		�X�v���C�g
				@param[in]		pModel		�X�v���C�g�i�[���f��
				@param[out]		pString		�Z���}�b�v�摜��
				
				@return			�Z���}�b�v<br>
								������Ȃ��ꍇ�m�t�k�k��Ԃ�
		*//**************************************************************************/
		SsCell* GetFirstCellName(SsPart* pSprite,SsAnimePack* pModel,CString& pString);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertSpriteStudio();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertSpriteStudio();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pInName		���̓t�@�C����
				@param[out]		pOutName	�o�̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CConvertSpriteStudio,MOF_CONVERTSPRITESTUDIOCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertSpriteStudio.inl"

}

#endif

#endif	//__CONVERTSPRITESTUDIOFILE__H__

//[EOF]