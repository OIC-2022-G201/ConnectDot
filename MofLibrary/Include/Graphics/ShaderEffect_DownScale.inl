/*************************************************************************//*!
					
					@file	ShaderEffect_DownScale.h
					@brief	汎用縮小シェーダークラス。

															@author	CDW
															@date	2015.05.18
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
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