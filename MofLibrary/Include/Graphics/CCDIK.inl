/*****************************************************************************
					
					［ファイル名］	CCDIK.inl
					［処理概要］	CCDIKクラス
					
															@author	CDW
															@date	2014.05.14
*****************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCCDIK::SetName(LPCMofChar pName){
	return m_Info.Target.SetString(pName);
}
/*************************************************************************//*!
		@brief			位置設定
		@param[in]		p				位置
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCCDIK::SetTargetPosition(Vector3& p){
	m_TargetPos = p;
	return TRUE;
}
/*************************************************************************//*!
		@brief			位置設定
		@param[in]		p				位置
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCCDIK::SetTargetPosition(Matrix44& p) {
	CMatrix44Utilities::GetTranslation(p, m_TargetPos);
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CCCDIK::GetName(void){
	return &m_Info.Target;
}
/*************************************************************************//*!
		@brief			ルート取得
		@param			None

		@return			ルート
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDIK::GetRoot(void){
	return m_pRoot;
}

/*************************************************************************//*!
		@brief			エフェクタ取得
		@param			None

		@return			エフェクタ
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDIK::GetEffector(void){
	return m_pEffector;
}
/*************************************************************************//*!
		@brief			ターゲット取得
		@param			None

		@return			ターゲット
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDIK::GetTarget(void) {
	return m_pTarget;
}

/*************************************************************************//*!
		@brief			子取得
		@param[in]		pName		名前

		@return			子
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDIK::GetJoint(LPCMofChar pName){
	if(!pName)
	{
		return NULL;
	}
	return m_pRoot->GetJoint(pName);
}

/*************************************************************************//*!
		@brief			ターゲット位置取得
		@param			None

		@return			ターゲット位置
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDIK::GetTargetPosition(void){
	return m_TargetPos;
}

/*************************************************************************//*!
		@brief			反復回数取得
		@param			None

		@return			反復回数
*//**************************************************************************/
FORCE_INLINE MofS32 CCCDIK::GetMaxIteration(void){
	return m_Info.Iteration;
}

/*************************************************************************//*!
		@brief			許容誤差取得
		@param			None

		@return			許容誤差
*//**************************************************************************/
FORCE_INLINE MofFloat CCCDIK::GetTolerance(void){
	return m_Info.Tolerance;
}
//[EOF]