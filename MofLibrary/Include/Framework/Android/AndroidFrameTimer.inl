/*************************************************************************//*!
					
					@file	AndroidFrameTimer.inl
					@brief	Androidでフレーム時間を計測、調整するためのクラス。<br>
							timeGetTimeにより時間の調整を行う。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			FPSの設定<br>
						FPSの固定をする場合に設定を行う。<br>
						引数のFPSに0を設定すると固定なしの時間計測のみの処理になる。
		@param[in]		s			FPS
			
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidFrameTimer::SetFPS(MofU32 s){
	m_FPS = s;
	if(s == 0)
	{
		m_FrameTime = 0;
	}
	else
	{
		m_FrameTime = 1000 / s;
	}
	//現在の時間をセットする
	m_FPSBeforeTime = GetTimeMS();
	return TRUE;
}
/*************************************************************************//*!
		@brief			フレーム時間の設定<br>
						このタイマーで経過したフレーム時間を引数のミリ秒に差し替える。
		@param[in]		s			フレーム時間(msec)
			
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidFrameTimer::SetFrameMSecond(MofU32 s){
	m_NowFrameTime = s;
	return TRUE;
}
/*************************************************************************//*!
		@brief			制限FPS取得
		@param			None

		@return			FPSの制限値
*//**************************************************************************/
FORCE_INLINE MofU32 CAndroidFrameTimer::GetRestrictFPS(void) const{
	return m_FPS;
}
/*************************************************************************//*!
		@brief			制限フレーム時間取得
		@param			None

		@return			フレーム時間の制限値
*//**************************************************************************/
FORCE_INLINE MofU32 CAndroidFrameTimer::GetRestrictFrameTime(void) const {
	return m_FrameTime;
}
/*************************************************************************//*!
		@brief			FPS取得
		@param			None

		@return			計測されたFPS
*//**************************************************************************/
FORCE_INLINE MofU32 CAndroidFrameTimer::GetFPS(void) const{
	return m_NowFPS;
}
/*************************************************************************//*!
		@brief			フレーム時間取得<br>
						取得するフレーム時間の単位はミリ秒
		@param			None

		@return			フレーム時間(msec)
*//**************************************************************************/
FORCE_INLINE MofU32 CAndroidFrameTimer::GetUpdateFrameTime(void) const {
	return m_UpdateFrameTime;
}
/*************************************************************************//*!
		@brief			フレーム時間取得<br>
						取得するフレーム時間の単位はミリ秒
		@param			None

		@return			フレーム時間(msec)
*//**************************************************************************/
FORCE_INLINE MofU32 CAndroidFrameTimer::GetFrameMSecond(void) const{
	return m_NowFrameTime;
}
/*************************************************************************//*!
		@brief			フレーム時間取得<br>
						取得するフレーム時間の単位は秒
		@param			None

		@return			フレーム時間(sec)
*//**************************************************************************/
FORCE_INLINE MofFloat CAndroidFrameTimer::GetFrameSecond(void) const{
	return m_NowFrameTime * 0.001f;
}

//[EOF]