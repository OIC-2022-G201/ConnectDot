/*************************************************************************//*!
					
					@file	RenderCommandProxy.inl
					@brief	�`��R�}���h�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�ۑ���Ԃ̐ݒ�
		@param[in]		st			�ݒ�
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CRenderCommandProxy::SetStatus(const GRAPHICSSTATUS& st){
	m_ProxyStatus = st;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���݂̕`��^�[�Q�b�g�擾
		@param[out]		None
				
		@return			���݂̕`��^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CRenderCommandProxy::GetRenderTarget(void){
	return m_ProxyStatus.pRenderTargets[0];
}
/*************************************************************************//*!
		@brief			�w�肵���ԍ��̕`��^�[�Q�b�g�擾
		@param[in]		index		
				
		@return			���݂̕`��^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CRenderCommandProxy::GetRenderTargetAt(MofU32 index){
	if(m_ProxyStatus.RenderTargetCount <= index)
	{
		return NULL;
	}
	return m_ProxyStatus.pRenderTargets[index];
}
/*************************************************************************//*!
		@brief			���݂̕`��^�[�Q�b�g�����擾
		@param			None
				
		@return			���݂̕`��^�[�Q�b�g��
*//**************************************************************************/
FORCE_INLINE MofU32 CRenderCommandProxy::GetRenderTargetCount(void){
	return m_ProxyStatus.RenderTargetCount;
}
/*************************************************************************//*!
		@brief			���݂̐[�x�^�[�Q�b�g�擾
		@param[out]		None
				
		@return			���݂̐[�x�^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPDepthTarget CRenderCommandProxy::GetDepthTarget(void){
	return m_ProxyStatus.pDepthTarget;
}
/*************************************************************************//*!
		@brief			�u�����h�X�e�[�g�擾
		@param[out]		None
				
		@return			���݂̃u�����h�X�e�[�g
*//**************************************************************************/
FORCE_INLINE Blending CRenderCommandProxy::GetBlending(void){
	return m_ProxyStatus.BlendType[0];
}

//[EOF]