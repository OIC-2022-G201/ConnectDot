/*****************************************************************************
					
					［ファイル名］	CCDJoint.inl
					［処理概要］	CCD用関節クラス
					
															@author	CDW
															@date	2014.05.14
*****************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetName(LPCMofChar pName){
	return m_Info.Target.SetString(pName);
}
/*************************************************************************//*!
		@brief			親設定
		@param[in]		p				親
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetParent(LPCCDJoint p){
	m_pParent = p;
	return TRUE;
}

/*************************************************************************//*!
		@brief			行列設定
		@param[in]		m				行列
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetMatrix(CMatrix44& m){
	m.GetTranslation(m_Position);
	m.GetRotation(m_Orientation);
	m.GetScaling(m_Scaling);
	m_JointMatrix = m;
	return TRUE;
}

/*************************************************************************//*!
		@brief			位置設定
		@param[in]		p				位置
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetPosition(Vector3& p){
	m_Position = p;
	return TRUE;
}
/*************************************************************************//*!
		@brief			姿勢設定
		@param[in]		q				姿勢
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetOrientation(Quaternion& q){
	m_Orientation = q;
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CCCDJoint::GetName(void){
	return &m_Info.Target;
}
/*************************************************************************//*!
		@brief			ボーン取得
		@param			None

		@return			ボーン
*//**************************************************************************/
FORCE_INLINE LPBone CCCDJoint::GetBone(void) {
	return m_pBone;
}
/*************************************************************************//*!
		@brief			設定情報取得
		@param			None

		@return			設定情報
*//**************************************************************************/
FORCE_INLINE BONEIKJOINT& CCCDJoint::GetInfo(void) {
	return m_Info;
}
/*************************************************************************//*!
		@brief			親取得
		@param			None

		@return			親
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDJoint::GetParent(void){
	return m_pParent;
}
/*************************************************************************//*!
		@brief			子取得
		@param			None

		@return			子
*//**************************************************************************/
FORCE_INLINE LPCCDJointArray CCCDJoint::GetChildren(void){
	return m_pChildren;
}

/*************************************************************************//*!
		@brief			子取得
		@param[in]		No			番号

		@return			子
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDJoint::GetChild(MofU32 No){
	if(!m_pChildren || No >= m_pChildren->GetArrayCount())
	{
		return NULL;
	}
	return m_pChildren->GetData(No);
}
/*************************************************************************//*!
		@brief			子取得
		@param[in]		pName		名前

		@return			子
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDJoint::GetJoint(LPCMofChar pName){
	if(!pName)
	{
		return NULL;
	}
	if(!CString::Compare(m_Info.Target.GetString(),pName))
	{
		return this;
	}
	if(m_pChildren)
	{
		for(MofU32 i = 0;i < m_pChildren->GetArrayCount();i++)
		{
			LPCCDJoint re = m_pChildren->GetData(i)->GetJoint(pName);
			if(re)
			{
				return re;
			}
		}
	}
	return NULL;
}

/*************************************************************************//*!
		@brief			行列取得
		@param			None

		@return			行列
*//**************************************************************************/
FORCE_INLINE CMatrix44& CCCDJoint::GetMatrix(void){
	return m_JointMatrix;
}
/*************************************************************************//*!
		@brief			位置取得
		@param			None

		@return			位置
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetPosition(void){
	return m_Position;
}
/*************************************************************************//*!
		@brief			姿勢取得
		@param			None

		@return			姿勢
*//**************************************************************************/
FORCE_INLINE CQuaternion& CCCDJoint::GetOrientation(void){
	return m_Orientation;
}

/*************************************************************************//*!
		@brief			制限取得
		@param			None

		@return			制限
*//**************************************************************************/
FORCE_INLINE MofFloat CCCDJoint::GetRestriction(void) {
	return m_Info.Restriction;
}
/*************************************************************************//*!
		@brief			比率取得
		@param			None

		@return			比率
*//**************************************************************************/
FORCE_INLINE MofFloat CCCDJoint::GetWeight(void){
	return m_Info.Weight;
}

/*************************************************************************//*!
		@brief			制限取得
		@param			None

		@return			制限
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetMinSingleRestriction(void){
	return m_Info.MinSingleRestriction;
}

/*************************************************************************//*!
		@brief			制限取得
		@param			None

		@return			制限
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetMaxSingleRestriction(void){
	return m_Info.MaxSingleRestriction;
}

/*************************************************************************//*!
		@brief			制限取得
		@param			None

		@return			制限
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetMinRestriction(void){
	return m_Info.MinRestriction;
}

/*************************************************************************//*!
		@brief			制限取得
		@param			None

		@return			制限
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetMaxRestriction(void){
	return m_Info.MaxRestriction;
}

//[EOF]