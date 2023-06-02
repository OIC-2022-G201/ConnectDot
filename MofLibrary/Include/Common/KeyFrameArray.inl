/*************************************************************************//*!
					
					@file	KeyFrameArray.inl
					@brief	キーフレーム配列クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			内部補間
		@param[in]		Data1		前のキーの値
		@param[in]		Data2		今のキーの値
		@param[in]		t			補間時間
		@param[out]		Out			出力

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
template < > struct CKeyFrameArrayImpl::InterpolationImpl< MofFloat > {
	static MofBool GetInterpolationValue(const MofFloat& Data1,const MofFloat& Data2, const MofFloat t,MofFloat& Out)
	{
		Out = Data1 + (MofFloat)((Data2 - Data1) * t);
		return TRUE;
	}
	static MofBool GetInterpolateBezierValue(const MofFloat& Data1, const MofFloat& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, MofFloat& Out)
	{
		float fCurrentPos = (nt - pt) * t + pt;
		float fCurrentCalc = 0.5f;
		float fCalcRange = 0.5f;

		float fTemp1;
		float fTemp2;
		float fTemp3;

		float fCurrentX;

		for (int iLoop = 0; iLoop < 8; iLoop++)
		{
			fTemp1 = 1.0f - fCurrentCalc;
			fTemp2 = fTemp1 * fTemp1;
			fTemp3 = fTemp2 * fTemp1;
			fCurrentX = (fTemp3 * pt) +
				(3 * fTemp2 * fCurrentCalc * (y1 + pt)) +
				(3 * fTemp1 * fCurrentCalc * fCurrentCalc * (y2 + nt)) +
				(fCurrentCalc * fCurrentCalc * fCurrentCalc * nt);

			fCalcRange /= 2.0f;
			if (fCurrentX > fCurrentPos)
			{
				fCurrentCalc -= fCalcRange;
			}
			else
			{
				fCurrentCalc += fCalcRange;
			}
		}
		fTemp1 = 1.0f - fCurrentCalc;
		fTemp2 = fTemp1 * fTemp1;
		fTemp3 = fTemp2 * fTemp1;
		Out = (Data1 * fTemp3) + (3 * fTemp2 * fCurrentCalc * (x1 + Data1)) + (3 * fTemp1 * fCurrentCalc * fCurrentCalc * (x2 + Data2)) + (fCurrentCalc * fCurrentCalc * fCurrentCalc * Data2);
		return TRUE;
	}
	static MofBool GetVector3TimeInterpolationValue(const MofFloat& Data1, const MofFloat& Data2, const Vector3& t, MofFloat& Out)
	{
		Out = Data1 + (MofFloat)((Data2 - Data1) * t.x);
		return TRUE;
	}
	static MofBool GetVector4TimeInterpolationValue(const MofFloat& Data1, const MofFloat& Data2, const Vector4& t, MofFloat& Out)
	{
		Out = Data1 + (MofFloat)((Data2 - Data1) * t.x);
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			内部補間(クォータニオン球面線形補間)
		@param[in]		Data1		前のキーの値
		@param[in]		Data2		今のキーの値
		@param[in]		t			補間時間
		@param[out]		Out			出力

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
template < > struct CKeyFrameArrayImpl::InterpolationImpl< Quaternion > {
	static MofBool GetInterpolationValue(const Quaternion& Data1,const Quaternion& Data2,MofFloat t,Quaternion& Out)
	{
		CQuaternionUtilities::Slerp(Data1,Data2,t,Out);
		return TRUE;
	}
	static MofBool GetInterpolateBezierValue(const Quaternion& Data1, const Quaternion& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, Quaternion& Out)
	{
		MofFloat vt = CKeyFrameArray<Quaternion>::GetInterpolateBezierTime(x1, x2, y1, y2, pt, nt, t);
		return GetInterpolationValue(Data1, Data2, vt, Out);
	}
	static MofBool GetVector3TimeInterpolationValue(const Quaternion& Data1, const Quaternion& Data2, Vector3& t, Quaternion& Out)
	{
		CQuaternionUtilities::Slerp(Data1, Data2, t.x, Out);
		return TRUE;
	}
	static MofBool GetVector4TimeInterpolationValue(const Quaternion& Data1, const Quaternion& Data2, Vector4& t, Quaternion& Out)
	{
		CQuaternionUtilities::Slerp(Data1, Data2, t.x, Out);
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			内部補間(Vector3線形補間)
		@param[in]		Data1		前のキーの値
		@param[in]		Data2		今のキーの値
		@param[in]		t			補間時間
		@param[out]		Out			出力

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
template < > struct CKeyFrameArrayImpl::InterpolationImpl< Vector3 > {
	static MofBool GetInterpolationValue(const Vector3& Data1, const Vector3& Data2, const MofFloat t, Vector3& Out)
	{
		Out = Data1 + ((Data2 - Data1) * t);
		return TRUE;
	}
	static MofBool GetInterpolateBezierValue(const Vector3& Data1, const Vector3& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, Vector3& Out)
	{
		MofFloat vt = CKeyFrameArray<Vector3>::GetInterpolateBezierTime(x1, x2, y1, y2, pt, nt, t);
		return GetInterpolationValue(Data1, Data2, vt, Out);
	}
	static MofBool GetVector3TimeInterpolationValue(const Vector3& Data1, const Vector3& Data2, const Vector3& t, Vector3& Out)
	{
		Out = Data1 + ((Data2 - Data1) * t);
		return TRUE;
	}
	static MofBool GetVector4TimeInterpolationValue(const Vector3& Data1, const Vector3& Data2, const Vector4& t, Vector3& Out)
	{
		Out = Data1 + ((Data2 - Data1) * Vector3(t.x,t.y,t.z));
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			内部補間(Vector4線形補間)
		@param[in]		Data1		前のキーの値
		@param[in]		Data2		今のキーの値
		@param[in]		t			補間時間
		@param[out]		Out			出力

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
template < > struct CKeyFrameArrayImpl::InterpolationImpl< Vector4 > {
	static MofBool GetInterpolationValue(const Vector4& Data1, const Vector4& Data2, const MofFloat t, Vector4& Out)
	{
		Out = Data1 + ((Data2 - Data1) * t);
		return TRUE;
	}
	static MofBool GetInterpolateBezierValue(const Vector4& Data1, const Vector4& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, Vector4& Out)
	{
		MofFloat vt = CKeyFrameArray<Vector4>::GetInterpolateBezierTime(x1, x2, y1, y2, pt, nt, t);
		return GetInterpolationValue(Data1, Data2, vt, Out);
	}
	static MofBool GetVector3TimeInterpolationValue(const Vector4& Data1, const Vector4& Data2, const Vector3& t, Vector4& Out)
	{
		Out = Data1 + ((Data2 - Data1) * Vector4(t.x,t.y,t.z,1.0f));
		return TRUE;
	}
	static MofBool GetVector4TimeInterpolationValue(const Vector4& Data1, const Vector4& Data2, const Vector4& t, Vector4& Out)
	{
		Out = Data1 + ((Data2 - Data1) * t);
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrameArray< T >::CKeyFrameArray() :
CDynamicArray< CKeyFrame< T >* >() {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー配列

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrameArray< T >::CKeyFrameArray(const CKeyFrameArray< T >& pObj) :
CDynamicArray< CKeyFrame< T >* >(pObj) {
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrameArray< T >::~CKeyFrameArray(){
	this->Release();
}
/*************************************************************************//*!
		@brief			データのソートを実行する比較関数
		@param[in]		A			フレームＡ
		@param[in]		B			フレームＢ

		@return			<0			Aが前
						>0			Bが前
						0			同一
*//**************************************************************************/
template < typename T > FORCE_INLINE int CKeyFrameArray< T >::KeySortCompare(const void* A,const void* B){
	//キーフレーム取り出し
	CKeyFrame< T >* DataA = *((CKeyFrame< T >**)A);
	CKeyFrame< T >* DataB = *((CKeyFrame< T >**)B);
	//比較
	if(DataA->m_Time < DataB->m_Time)
	{
		return -1;
	}
	if(DataA->m_Time > DataB->m_Time)
	{
		return 1;
	}
	return 0;
}
/*************************************************************************//*!
		@brief			キーフレームの追加
		@param[in]		Time		追加キーフレーム時間
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::AddKeyFrame(MofFloat Time){
	if(GetKeyFrame(Time))
	{
		return FALSE;
	}
	T Data;
	GetTimeState(Time,Data);
	CKeyFrame< T >* pNow = GetNowKeyFrame(Time);
	if(pNow)
	{
		CKeyFrame< T >* pAdd = new CKeyFrame< T >(Data,Time,pNow->m_Flag,pNow->m_InterpolationType,NULL);
		if(!AddLast(&pAdd))
		{
			return FALSE;
		}
	}
	else
	{
		CKeyFrame< T >* pAdd = new CKeyFrame< T >(Data,Time,0,KEYINTERPOLATION_NONE,NULL);
		if(!AddLast(&pAdd))
		{
			return FALSE;
		}
	}
	return Sort();
}
/*************************************************************************//*!
		@brief			キーフレームの追加
		@param[in]		Data		追加キーフレーム内容
		@param[in]		Time		追加キーフレーム時間
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::AddKeyFrame(const T& Data,MofFloat Time){
	if(GetKeyFrame(Time))
	{
		return FALSE;
	}
	CKeyFrame< T >* pNow = GetNowKeyFrame(Time);
	if(pNow)
	{
		CKeyFrame< T >* pAdd = new CKeyFrame< T >(Data,Time,pNow->m_Flag,pNow->m_InterpolationType,NULL);
		if(!this->AddLast(&pAdd))
		{
			return FALSE;
		}
	}
	else
	{
		CKeyFrame< T >* pAdd = new CKeyFrame< T >(Data,Time,0,KEYINTERPOLATION_NONE,NULL);
		if(!this->AddLast(&pAdd))
		{
			return FALSE;
		}
	}
	return Sort();
}
/*************************************************************************//*!
		@brief			キーフレームの削除
		@param[in]		Time		削除キーフレーム時間
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::DeleteKeyFrame(MofFloat Time){
	CKeyFrame< T >* pDel = GetKeyFrame(Time);
	if(!pDel)
	{
		return FALSE;
	}
	return Delete(&pDel);
}
/*************************************************************************//*!
		@brief			配列のソートを実行する
		@param[in]		pFunc			比較関数
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::Sort(int (*pFunc)(const void *, const void *)){
	return CDynamicArray< CKeyFrame< T >* >::Sort(pFunc);
}
/*************************************************************************//*!
		@brief			ループフラグがあるかを判定する
		@param			None
				
		@return			TRUE			ループする<br>
						FALSE			ループしない
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::IsLoop(void){
	return ((this->m_Flag & KEYFRAMEARRAY_LOOPFLAG) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			ループフラグの設定
		@param[in]		Loop		ループフラグ<br>
									ループを有効にする場合はKEYFRAMEARRAY_LOOPALLFRAMEかKEYFRAMEARRAY_LOOPSTARTFRAMEを指定<br>
									ループを無効にする場合は0を指定する。
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::SetLoop(MofU32 Loop){
	if(Loop)
	{
		if(!(this->m_Flag & KEYFRAMEARRAY_LOOPFLAG))
		{
			this->m_Flag |= (Loop & KEYFRAMEARRAY_LOOPFLAG);
		}
	}
	else if(this->m_Flag & KEYFRAMEARRAY_LOOPFLAG)
	{
		this->m_Flag &= ~KEYFRAMEARRAY_LOOPFLAG;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			最初のキーフレームの時間取得
		@param			None

		@return			最初のキーフレームの時間
*//**************************************************************************/
template < typename T > FORCE_INLINE MofFloat CKeyFrameArray< T >::GetStartKeyTime(void) const {
	if(this->m_Count <= 0)
	{
		return 0.0f;
	}
	return this->m_pArray[0]->m_Time;
}
/*************************************************************************//*!
		@brief			最終のキーフレームの時間取得
		@param			None

		@return			最終のキーフレームの時間
*//**************************************************************************/
template < typename T > FORCE_INLINE MofFloat CKeyFrameArray< T >::GetLastKeyTime(void) const {
	if(this->m_Count <= 0)
	{
		return 0.0f;
	}
	return this->m_pArray[this->m_Count - 1]->m_Time;
}
/*************************************************************************//*!
		@brief			今の時間のループの終了時間取得
		@param[in]		t			時間

		@return			今の時間のループの終了時間
*//**************************************************************************/
template < typename T > FORCE_INLINE MofFloat CKeyFrameArray< T >::GetLoopLastTime(MofFloat t) const {
	//キーフレームが0なら基礎データを返す
	if(this->m_Count <= 0)
	{
		return 0;
	}
	//終了フレームの時間より後なら
	if(t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//終了時間より後なら終了時間以内に収めるように計算をする
		if(this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			return this->m_pArray[this->m_Count - 1]->m_Time + (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * ((int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time)) + 1);
		}
		else if(this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			return this->m_pArray[this->m_Count - 1]->m_Time * ((int)(t / this->m_pArray[this->m_Count - 1]->m_Time) + 1);
		}
	}
	//普通に終了時間
	return GetLastKeyTime();
}
/*************************************************************************//*!
		@brief			指定時間のキーを取得
		@param[in]		t			時間

		@return			NULL		キーが見つからない<br>
						それ以外	見つけたキーフレーム
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >* CKeyFrameArray< T >::GetKeyFrame(MofFloat t) const {
	//全部フレームから指定時間のものを探す
	for(MofU32 i = 0;i < this->m_Count;i++)
	{
		if(this->m_pArray[i]->m_Time + 0.006f >= t && this->m_pArray[i]->m_Time - 0.006f <= t)
		{
			return this->m_pArray[i];
		}
	}
	//指定時間のキーが見つからない
	return NULL;
}
/*************************************************************************//*!
		@brief			指定時間のキー番号を取得
		@param[in]		t			時間

		@return			配列要素番号
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CKeyFrameArray< T >::GetKeyFrameNo(MofFloat t) const {
	//全部フレームから指定時間のものを探す
	for (MofU32 i = 0; i < this->m_Count; i++)
	{
		if (this->m_pArray[i]->m_Time + 0.006f >= t && this->m_pArray[i]->m_Time - 0.006f <= t)
		{
			return i;
		}
	}
	//指定時間のキーが見つからない
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			指定時間のキーを取得
		@param[in]		t			時間

		@return			NULL		キーが見つからない<br>
						それ以外	見つけたキーフレーム
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >* CKeyFrameArray< T >::GetNowKeyFrame(MofFloat t) const {
	//キーがない
	if(this->m_Count <= 0)
	{
		return NULL;
	}
	//終了フレームの時間より後なら
	if(t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//終了時間より後なら終了時間以内に収めるように計算をする
		if(this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time;
			t -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			t += this->m_pArray[0]->m_Time;
		}
		else if(this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(t / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			return this->m_pArray[this->m_Count - 1];
		}
	}
	//初期フレームの時間より前なら現在のフレームはない
	if(t <= this->m_pArray[0]->m_Time)
	{
		return NULL;
	}
	//全キーフレーム走査
	for(MofU32 i = 1;i < this->m_Count;i++)
	{
		//キーフレームの時間ぴったりなら
		if(t == this->m_pArray[i]->m_Time)
		{
			return this->m_pArray[i];
		}
		//キーフレームの時間以前なら
		else if(t < this->m_pArray[i]->m_Time)
		{
			return this->m_pArray[i - 1];
		}
	}
	//ここまで来てるということは正しいキーが見つかっていない
	return NULL;
}
/*************************************************************************//*!
		@brief			指定時間のキー番号を取得
		@param[in]		t			時間

		@return			配列要素番号
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CKeyFrameArray< T >::GetNowKeyFrameNo(MofFloat t) const {
	//キーがない
	if (this->m_Count <= 0)
	{
		return MOF_U32_MAX;
	}
	//終了フレームの時間より後なら
	if (t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//終了時間より後なら終了時間以内に収めるように計算をする
		if (this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time;
			t -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			t += this->m_pArray[0]->m_Time;
		}
		else if (this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(t / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			return this->m_Count - 1;
		}
	}
	//初期フレームの時間より前なら現在のフレームはない
	if (t <= this->m_pArray[0]->m_Time)
	{
		return MOF_U32_MAX;
	}
	//全キーフレーム走査
	for (MofU32 i = 1; i < this->m_Count; i++)
	{
		//キーフレームの時間ぴったりなら
		if (t == this->m_pArray[i]->m_Time)
		{
			return i;
		}
		//キーフレームの時間以前なら
		else if (t < this->m_pArray[i]->m_Time)
		{
			return i - 1;
		}
	}
	//ここまで来てるということは正しいキーが見つかっていない
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			指定時間の次のキーを取得
		@param[in]		t			時間

		@return			NULL		キーが見つからない<br>
						それ以外	見つけたキーフレーム
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >* CKeyFrameArray< T >::GetNextKeyFrame(MofFloat t) const {
	//キーがない
	if(this->m_Count <= 0)
	{
		return NULL;
	}
	//終了フレームの時間より後なら
	if(t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//終了時間より後なら終了時間以内に収めるように計算をする
		if(this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time;
			t -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			t += this->m_pArray[0]->m_Time;
		}
		else if(this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(t / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			return NULL;
		}
	}
	//初期フレームの時間より前なら初期フレームを返す
	if(t <= this->m_pArray[0]->m_Time)
	{
		return this->m_pArray[0];
	}
	//全キーフレーム走査
	for(MofU32 i = 1;i < this->m_Count;i++)
	{
		//キーフレームの時間ぴったりなら
		if(t == this->m_pArray[i]->m_Time)
		{
			return this->m_pArray[i + 1];
		}
		//キーフレームの時間以前なら
		else if(t < this->m_pArray[i]->m_Time)
		{
			return this->m_pArray[i];
		}
	}
	//ここまで来てるということは正しいキーが見つかっていない
	return NULL;
}
/*************************************************************************//*!
		@brief			指定時間のキー番号を取得
		@param[in]		t			時間

		@return			配列要素番号
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CKeyFrameArray< T >::GetNextKeyFrameNo(MofFloat t) const {
	//キーがない
	if (this->m_Count <= 0)
	{
		return MOF_U32_MAX;
	}
	//終了フレームの時間より後なら
	if (t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//終了時間より後なら終了時間以内に収めるように計算をする
		if (this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time;
			t -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			t += this->m_pArray[0]->m_Time;
		}
		else if (this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(t / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			return MOF_U32_MAX;
		}
	}
	//初期フレームの時間より前なら初期フレームを返す
	if (t <= this->m_pArray[0]->m_Time)
	{
		return 0;
	}
	//全キーフレーム走査
	for (MofU32 i = 1; i < this->m_Count; i++)
	{
		//キーフレームの時間ぴったりなら
		if (t == this->m_pArray[i]->m_Time)
		{
			return i + 1;
		}
		//キーフレームの時間以前なら
		else if (t < this->m_pArray[i]->m_Time)
		{
			return i;
		}
	}
	//ここまで来てるということは正しいキーが見つかっていない
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			指定時間のキー状態を取得
		@param[in]		Time		時間
		@param[out]		Out			出力
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::GetTimeState(MofFloat Time,T& Out) const {
	//キーがない
	if(this->m_Count <= 0)
	{
		return FALSE;
	}
	//キーフレームが一つならその状態を返す
	if(this->m_Count == 1)
	{
		Out = this->m_pArray[0]->m_Value;
		return TRUE;
	}
	//終了フレームの時間より後なら
	if(Time > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//終了時間より後なら終了時間以内に収めるように計算をする
		if(this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			Time -= this->m_pArray[this->m_Count - 1]->m_Time;
			Time -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(Time / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			Time += this->m_pArray[0]->m_Time;
		}
		else if(this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			Time -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(Time / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			Out = this->m_pArray[this->m_Count - 1]->m_Value;
			return TRUE;
		}
	}
	//初期フレームの時間より前なら初期フレームを返す
	if(Time <= this->m_pArray[0]->m_Time)
	{
		Out = this->m_pArray[0]->m_Value;
		return TRUE;
	}
	//全キーフレーム走査
	for(MofU32 i = 1;i < this->m_Count;i++)
	{
		//キーフレームの時間ぴったりなら
		if(Time == this->m_pArray[i]->m_Time)
		{
			Out = this->m_pArray[i]->m_Value;
			return TRUE;
		}
		//キーフレームの時間以前なら
		else if(Time < this->m_pArray[i]->m_Time)
		{
			//前と今のポインタ取り出し
			CKeyFrame< T >* prev = this->m_pArray[i - 1];
			if(prev->m_InterpolationType == KEYINTERPOLATION_NONE)
			{
				Out = prev->m_Value;
				return TRUE;
			}
			CKeyFrame< T >* next = this->m_pArray[i];
			//総動作時間を求める
			MofFloat t = (Time - prev->m_Time) / (MofFloat)(next->m_Time - prev->m_Time);
			switch(prev->m_InterpolationType)
			{
				case KEYINTERPOLATION_EASE:
					t = (1 - prev->m_InterpolationValue[0]) * t + prev->m_InterpolationValue[0] * t * t;
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);

				case KEYINTERPOLATION_HERMITE:
					t = GetInterpolateHermiteTime(prev->m_InterpolationValue[0], prev->m_InterpolationValue[1], t);
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);

				case KEYINTERPOLATION_BEZIER1:
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);
					//return InterpolationImpl< T >::GetInterpolateBezierValue(prev->m_Value, next->m_Value, prev->m_InterpolationValue[0], prev->m_InterpolationValue[1], prev->m_InterpolationValue[2], prev->m_InterpolationValue[3], prev->m_Time, next->m_Time, t, Out);

				case KEYINTERPOLATION_BEZIER2:
					t = GetInterpolateBezierTime(prev->m_InterpolationValue[0],prev->m_InterpolationValue[1],prev->m_InterpolationValue[2],prev->m_InterpolationValue[3],t);
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);

				case KEYINTERPOLATION_BEZIER2_VECTOR3:
				{
					Vector3 vt(
						GetInterpolateBezierTime(prev->m_InterpolationValue[0], prev->m_InterpolationValue[1], prev->m_InterpolationValue[2], prev->m_InterpolationValue[3], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[4], prev->m_InterpolationValue[5], prev->m_InterpolationValue[6], prev->m_InterpolationValue[7], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[8], prev->m_InterpolationValue[9], prev->m_InterpolationValue[10], prev->m_InterpolationValue[11], t)
						);
					return InterpolationImpl< T >::GetVector3TimeInterpolationValue(prev->m_Value, next->m_Value, vt, Out);
				}

				case KEYINTERPOLATION_BEZIER2_VECTOR4:
				{
					Vector4 vt(
						GetInterpolateBezierTime(prev->m_InterpolationValue[0], prev->m_InterpolationValue[1], prev->m_InterpolationValue[2], prev->m_InterpolationValue[3], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[4], prev->m_InterpolationValue[5], prev->m_InterpolationValue[6], prev->m_InterpolationValue[7], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[8], prev->m_InterpolationValue[9], prev->m_InterpolationValue[10], prev->m_InterpolationValue[11], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[12], prev->m_InterpolationValue[13], prev->m_InterpolationValue[14], prev->m_InterpolationValue[15], t)
						);
					return InterpolationImpl< T >::GetVector4TimeInterpolationValue(prev->m_Value, next->m_Value, vt, Out);
				}

				default:
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);
			}
		}
	}
	//ここまで来てるということは正しいキーが見つかっていない
	return FALSE;
}
/*************************************************************************//*!
		@brief			エルミート補間で現在の時間を求める
		@param[in]		x1			Xコントロールポイント
		@param[in]		x2			Xコントロールポイント
		@param[in]		x			現在位置
				
		@return			時間
*//**************************************************************************/
FORCE_INLINE MofFloat CKeyFrameArrayImpl::GetInterpolateHermiteTime(const MofFloat x1, const MofFloat x2, const MofFloat t){
	float start = 0.0f;
	float end = 1.0f;
	float t2 = t * t;
	float t3 = t2 * t;
	return (2 * t3 - 3 * t2 + 1) * start + (-2 * t3 + 3 * t2) * end + (t3 - 2 * t2 + t) * (x1 - start) + (t3 - t2) * (x2 - end);
}
/*************************************************************************//*!
		@brief			３次ベジェ補間で現在の時間を求める
		@param[in]		x1			Xコントロールポイント
		@param[in]		x2			Xコントロールポイント
		@param[in]		y1			Yコントロールポイント
		@param[in]		y2			Yコントロールポイント
		@param[in]		pt			前のキーの時間
		@param[in]		nt			次のキーの時間
		@param[in]		t			現在位置
				
		@return			時間
*//**************************************************************************/
FORCE_INLINE MofFloat CKeyFrameArrayImpl::GetInterpolateBezierTime(const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t){
	float start = 0.0f;
	float end = 1.0f;
	float fCurrentPos = (nt - pt) * t + pt;
	float fCurrentCalc = 0.5f;
	float fCalcRange = 0.5f;

	float fTemp1;
	float fTemp2;
	float fTemp3;

	float fCurrentX;

	for (int iLoop = 0; iLoop < 8; iLoop++)
	{
		fTemp1 = 1.0f - fCurrentCalc;
		fTemp2 = fTemp1 * fTemp1;
		fTemp3 = fTemp2 * fTemp1;
		fCurrentX = (fTemp3 * pt) +
			(3 * fTemp2 * fCurrentCalc * (y1 + pt)) +
			(3 * fTemp1 * fCurrentCalc * fCurrentCalc * (y2 + nt)) +
			(fCurrentCalc * fCurrentCalc * fCurrentCalc * nt);

		fCalcRange /= 2.0f;
		if (fCurrentX > fCurrentPos)
		{
			fCurrentCalc -= fCalcRange;
		}
		else
		{
			fCurrentCalc += fCalcRange;
		}
	}
	fTemp1 = 1.0f - fCurrentCalc;
	fTemp2 = fTemp1 * fTemp1;
	fTemp3 = fTemp2 * fTemp1;
	return (start * fTemp3) + (3 * fTemp2 * fCurrentCalc * (x1 + start)) + (3 * fTemp1 * fCurrentCalc * fCurrentCalc * (x2 + end)) + (fCurrentCalc * fCurrentCalc * fCurrentCalc * end);
}
/*************************************************************************//*!
		@brief			３次ベジェ補間で現在の時間を求める
		@param[in]		x1			Xコントロールポイント
		@param[in]		x2			Xコントロールポイント
		@param[in]		y1			Yコントロールポイント
		@param[in]		y2			Yコントロールポイント
		@param[in]		x			現在位置
				
		@return			時間
*//**************************************************************************/
FORCE_INLINE MofFloat CKeyFrameArrayImpl::GetInterpolateBezierTime(const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat x){
	if (MOF_ABS(x1 - x2) < 0.0001f && MOF_ABS(y1 - y2) < 0.0001f)
	{
		return x;
	}
	int l;
	float NT, InvT;
	for (l = 0, NT = x, InvT = 1.0f - NT; l < 32; l++)
	{
		float TempX = 3.0f * InvT * InvT * NT * x1 + 3.0f * InvT * NT * NT * x2 + NT * NT * NT - x;
		if (TempX < 0.0001f && TempX > -0.0001f)
		{
			break;
		}
		NT -= TempX * 0.5f;
		InvT = 1.0f - NT;
	}
	return 3.0f * InvT * InvT * NT * y1 + 3.0f * InvT * NT * NT * y2 + NT * NT * NT;
	/*
	RateH = InvT * InvT * T * Y1 + InvT * T * T * Y2 + T * T * T;
	MofFloat t = 0.5f;
	MofFloat s = 0.5f;
	for(MofU32 i = 0; i < MOF_KEYINTERPOLATIONBEZIER2COUNT;i++)
	{
		MofFloat ft = (3.0f * s * s * t * x1) + (3.0f * s * t * t * x2) + (t * t * t) - x;
		if(MOF_ABS(ft) < 0.00001f)
		{
			break;
		}
		if(ft > 0.0f)
		{
			t -= 1 / (4 << i);
		}
		else
		{
			t += 1 / (4 << i);
		}
		s = 1.0f - t;
	}
	return (3.0f * s * s * t * y1) + (3.0f * s * t * t * y2) + (t * t * t);*/
}

//[EOF]