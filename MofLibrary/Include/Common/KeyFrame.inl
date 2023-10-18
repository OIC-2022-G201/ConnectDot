/*************************************************************************//*!
					
					@file	KeyFrame.inl
					@brief	キーフレームクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >::CKeyFrame() :
m_Value(NULL) ,
m_Time(0.0f) ,
m_Flag(0) ,
m_InterpolationType(KEYINTERPOLATION_LINEAR) {
	memset(m_InterpolationValue,0,sizeof(MofFloat) * MOF_KEYFRAMEINTERPOLATIONCOUNT);
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		v			要素
		@param[in]		t			時間
		@param[in]		f			フラグ
		@param[in]		inter		補間方法
		@param[in]		pinterval	補間パラメーター

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >::CKeyFrame(const T& v,MofFloat t,MofU32 f,KeyFrameInterpolationType inter,LPCMofFloat pinterval) :
m_Value(v) ,
m_Time(t) ,
m_Flag(f) ,
m_InterpolationType(inter) {
	memset(m_InterpolationValue,0,sizeof(MofFloat) * MOF_KEYFRAMEINTERPOLATIONCOUNT);
	switch(inter)
	{
		case KEYINTERPOLATION_EASE:
			memcpy(m_InterpolationValue,pinterval,sizeof(MofFloat));
			break;
		case KEYINTERPOLATION_HERMITE:
			memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 2);
			break;
		case KEYINTERPOLATION_BEZIER1:
			memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 4);
			break;
		case KEYINTERPOLATION_BEZIER2:
			memcpy(m_InterpolationValue,pinterval,sizeof(MofFloat) * 4);
			break;
		case KEYINTERPOLATION_BEZIER2_VECTOR3:
			memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 12);
			break;
		case KEYINTERPOLATION_BEZIER2_VECTOR4:
			memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 16);
			break;
		default:
			memset(m_InterpolationValue,0,sizeof(MofFloat) * 16);
			break;
	}
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーフレーム

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >::CKeyFrame(const CKeyFrame< T >& pObj) :
m_Value(pObj.m_Value) ,
m_Time(pObj.m_Time) ,
m_Flag(pObj.m_Flag) ,
m_InterpolationType(pObj.m_InterpolationType) {
	memcpy(m_InterpolationValue,pObj.m_InterpolationValue,sizeof(MofFloat) * MOF_KEYFRAMEINTERPOLATIONCOUNT);
}		
/*************************************************************************//*!
		@brief			コピーキーフレームの作成
		@param			None

		@return			作成されたコピーキーフレーム<br>
						作成に失敗した場合NULLを返す
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >* CKeyFrame< T >::CreateCopyObject(void) const{
	return new CKeyFrame< T >(*this);
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >::~CKeyFrame(){
}
/*************************************************************************//*!
		@brief			データ設定
		@param[in]		v			データ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrame< T >::SetValue(T& v){
	m_Value = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			時間設定
		@param[in]		t			データ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrame< T >::SetTime(MofFloat v){
	m_Time = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			補間設定
		@param[in]		inter		補間方法
		@param[in]		pinterval	補間パラメーター

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrame< T >::SetInterpolation(KeyFrameInterpolationType inter, LPCMofFloat pinterval) {
	m_InterpolationType = inter;
	switch (inter)
	{
	case KEYINTERPOLATION_EASE:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat));
		break;
	case KEYINTERPOLATION_HERMITE:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 2);
		break;
	case KEYINTERPOLATION_BEZIER1:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 4);
		break;
	case KEYINTERPOLATION_BEZIER2:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 4);
		break;
	case KEYINTERPOLATION_BEZIER2_VECTOR3:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 12);
		break;
	case KEYINTERPOLATION_BEZIER2_VECTOR4:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 16);
		break;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			時間取得
		@param			None

		@return			時間
*//**************************************************************************/
template < typename T > FORCE_INLINE MofFloat CKeyFrame< T >::GetTime(void) const{
	return m_Time;
}
/*************************************************************************//*!
		@brief			フラグ取得
		@param			None

		@return			フラグ
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CKeyFrame< T >::GetFlag(void) const{
	return m_Flag;
}
/*************************************************************************//*!
		@brief			補間方法取得
		@param			None

		@return			補間方法
*//**************************************************************************/
template < typename T > FORCE_INLINE KeyFrameInterpolationType CKeyFrame< T >::GetInterpolationType(void) const{
	return m_InterpolationType;
}
/*************************************************************************//*!
		@brief			補間情報取得
		@param			None

		@return			補間情報
*//**************************************************************************/
template < typename T > FORCE_INLINE LPCMofFloat CKeyFrame< T >::GetInterpolationValue(void) const{
	return m_InterpolationValue;
}
/*************************************************************************//*!
		@brief			データ取得
		@param			None

		@return			データ
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CKeyFrame< T >::GetValue(void){
	return m_Value;
}
/*************************************************************************//*!
		@brief			データ取得
		@param			None

		@return			データ
*//**************************************************************************/
template < typename T > FORCE_INLINE const T& CKeyFrame< T >::GetValue(void) const{
	return m_Value;
}

//[EOF]