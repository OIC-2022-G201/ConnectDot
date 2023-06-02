/*************************************************************************//*!
					
					@file	ShaderEffect_DownScale.h
					@brief	�ėp�k���V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.18
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_DownScale::Create(){
	switch(m_SampleType)
	{
	case SAMPLE_2X2:
		return Create2x2();
	case SAMPLE_3X3LUM:
		return Create3x3Lum();
	}
	return FALSE;
}

//[EOF]