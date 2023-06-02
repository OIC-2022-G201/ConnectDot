/*************************************************************************//*!
					
					@file	DirectionalLight.inl
					@brief	方向光源クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			ライト方向設定
		@param[in]		v			方向
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CDirectionalLight::SetDirection(const Vector3& v){
	CVector3Utilities::Normal(v,m_Direction);
	return TRUE;
}
/*************************************************************************//*!
		@brief			ライトタイプ取得
		@param			None

		@return			ライトタイプ
*//**************************************************************************/
FORCE_INLINE LightType CDirectionalLight::GetType(void) const{
	return LIGHTTYPE_DIRECTION;
}
/*************************************************************************//*!
		@brief			ライト方向取得
		@param			None

		@return			ライト方向
*//**************************************************************************/
FORCE_INLINE CVector3& CDirectionalLight::GetDirection(void){
	return m_Direction;
}
/*************************************************************************//*!
		@brief			ライト方向取得
		@param			None

		@return			ライト方向
*//**************************************************************************/
FORCE_INLINE const CVector3& CDirectionalLight::GetDirection(void) const {
	return m_Direction;
}

//[EOF]