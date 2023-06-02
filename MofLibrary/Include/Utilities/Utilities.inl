/*************************************************************************//*!
					
					@file	Utilities.inl
					@brief	汎用処理をまとめたスタティッククラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			タイマーの更新<br>
						タイマーの更新を行う。<br>
						前回この関数が呼び出されてから、今回実行されるまでの時間を計測しフレーム時間に設定する。<br>
						bWaitがTRUEなら設定されているFPSまでの余剰時間分をsleepにより待機する。<br>
						FPSが設定されていない場合やbWaitがFALSEの場合は待機処理は行われない。
		@param[in]		bWait		FPSウェイトフラグ
			
		@return			None
*//**************************************************************************/
FORCE_INLINE void CUtilities::UpdateTimer(MofBool bWait){
	if(!m_pFrameTimer)
	{
		return;
	}
	return m_pFrameTimer->Update(bWait);
}
/*************************************************************************//*!
		@brief			乱数生成
		@param			None

		@return			発生した乱数を返す
*//**************************************************************************/
FORCE_INLINE  MofU32 CUtilities::Random(void){
	return m_Random.Random();
}
/*************************************************************************//*!
		@brief			乱数生成<br>
						0～引数の最大値未満の範囲の乱数が発生する
		@param[in]		h				最大値

		@return			発生した乱数を返す
*//**************************************************************************/
FORCE_INLINE  MofU32 CUtilities::Random(MofU32 h){
	return m_Random.Random(h);
}
/*************************************************************************//*!
		@brief			乱数生成<br>
						引数の最少値～引数の最大値未満の範囲の乱数が発生する
		@param[in]		l				最少値
		@param[in]		h				最大値

		@return			発生した乱数を返す
*//**************************************************************************/
FORCE_INLINE  MofU32 CUtilities::Random(MofU32 l,MofU32 h){
	return m_Random.Random(l,h);
}
/*************************************************************************//*!
		@brief			(0.0f～1.0f)の範囲の乱数生成
		@param			None

		@return			発生した乱数を返す
*//**************************************************************************/
FORCE_INLINE  MofFloat CUtilities::RandomFloat(void){
	return m_Random.RandomFloat();
}
/*************************************************************************//*!
		@brief			フレームワークを設定する
		@param[in]		pfw			フレームワーク
				
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CUtilities::SetFramework(LPFramework pfw){
	m_pFramework = pfw;
	return TRUE;
}
/*************************************************************************//*!
		@brief			FPSの設定<br>
						FPSの固定をする場合に設定を行う。<br>
						引数のFPSに0を設定すると固定なしの時間計測のみの処理になる。
		@param[in]		s			FPS
			
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CUtilities::SetFPS(MofU32 s){
	if(!m_pFrameTimer)
	{
		return FALSE;
	}
	return m_pFrameTimer->SetFPS(s);
}
/*************************************************************************//*!
		@brief			フレーム時間の設定<br>
						このタイマーで経過したフレーム時間を引数のミリ秒に差し替える。
		@param[in]		s			フレーム時間(msec)
			
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CUtilities::SetFrameMSecond(MofU32 s){
	if(!m_pFrameTimer)
	{
		return FALSE;
	}
	return m_pFrameTimer->SetFrameMSecond(s);
}
/*************************************************************************//*!
		@brief			乱数の種を設定する
		@param[in]		s				種

		@return			None
*//**************************************************************************/
FORCE_INLINE void CUtilities::SetSeed(MofU32 s){
	return m_Random.SetSeed(s);
}
/*************************************************************************//*!
		@brief			フレームワークを取得する
		@param			None

		@return			フレームワーク
*//**************************************************************************/
FORCE_INLINE LPFramework CUtilities::GetFramework(void){
	return m_pFramework;
}
/*************************************************************************//*!
		@brief			インスタンスハンドル取得する
		@param			None

		@return			インスタンスハンドル
*//**************************************************************************/
FORCE_INLINE MofInstanceHandle CUtilities::GetInstanceHandle(void){
	return m_pFramework->GetHandle();
}
/*************************************************************************//*!
		@brief			制限FPS取得
		@param			None

		@return			FPSの制限値
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetRestrictFPS(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetRestrictFPS();
}
/*************************************************************************//*!
		@brief			制限フレーム時間取得
		@param			None

		@return			フレーム時間の制限値
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetRestrictFrameTime(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetRestrictFrameTime();
}
/*************************************************************************//*!
		@brief			FPS取得
		@param			None

		@return			計測されたFPS
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetFPS(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetFPS();
}
/*************************************************************************//*!
		@brief			フレーム時間取得<br>
						取得するフレーム時間の単位はミリ秒
		@param			None

		@return			フレーム時間(msec)
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetUpdateFrameTime(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetUpdateFrameTime();
}
/*************************************************************************//*!
		@brief			フレーム時間取得<br>
						取得するフレーム時間の単位はミリ秒
		@param			None

		@return			フレーム時間(msec)
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetFrameMSecond(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetFrameMSecond();
}
/*************************************************************************//*!
		@brief			フレーム時間取得<br>
						取得するフレーム時間の単位は秒
		@param			None

		@return			フレーム時間(sec)
*//**************************************************************************/
FORCE_INLINE MofFloat CUtilities::GetFrameSecond(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetFrameSecond();
}
/*************************************************************************//*!
		@brief			カレントディレクトリを取得する
		@param			None
				
		@return			カレントディレクトリのパス
*//**************************************************************************/
FORCE_INLINE LPMofChar CUtilities::GetCurrentDirectory(void){
	return m_CurrentDirectory.GetString();
}

#ifdef		MOFLIB_ANDROID
/*************************************************************************//*!
		@brief			JNI呼び出し元設定

						JNI呼び出し情報を設定します

		@param[in]		env				JNI
		@param[in]		obj				JNI呼び出しオブジェクト

		@return			None
*//**************************************************************************/
FORCE_INLINE void CUtilities::SetJNICall(JNIEnv* env,jobject obj){
	m_Env = env;
	m_Thiz = obj;
	return;
}
/*************************************************************************//*!
		@brief			JNI呼び出し元取得

						JNI呼び出し情報を取得します

		@param			None

		@return			JNI
*//**************************************************************************/
FORCE_INLINE JNIEnv* CUtilities::GetJNIEnv(void){
	return m_Env;
}
/*************************************************************************//*!
		@brief			JNI呼び出し元取得

						JNI呼び出し情報を取得します

		@param			None

		@return			JNI
*//**************************************************************************/
FORCE_INLINE jobject CUtilities::GetJNIObject(void){
	return m_Thiz;
}

#endif

//[EOF]