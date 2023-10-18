/*************************************************************************//*!
					
					@file	Thread.inl
					@brief	スレッドを作成実行するための基底インターフェイスとクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			解放
		@param[in]		pData			解放追加データ

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CThread::Release(LPMofVoid pData){
	return Join();
}
/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CThread::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CThread::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CRunnable::CRunnable() {
}
/*************************************************************************//*!
		@brief			解放
		@param[in]		pData			解放追加データ

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CRunnable::Release(LPMofVoid pData){
	return TRUE;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			pRunnable		内部の処理実装

		@return			None
*//**************************************************************************/
FORCE_INLINE CRunnableThread::CRunnableThread(LPRunnable pRunnable) : 
CThread() ,
m_pRunnable(pRunnable) {
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CRunnableThread::~CRunnableThread(){
	Release();
}
/*************************************************************************//*!
		@brief			スレッドの内部実行処理<br>
						コンストラクタで与えられたのCRunnableのRunを実行する。
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CRunnableThread::Run(void){
	if(m_pRunnable)
	{
		m_pRunnable->Run();
	}
	return;
}
/*************************************************************************//*!
		@brief			解放
		@param[in]		pData			解放追加データ

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CRunnableThread::Release(LPMofVoid pData){
	if(Join())
	{
		MOF_SAFE_DELETE(m_pRunnable);
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			f				内部の処理コールバック

		@return			None
*//**************************************************************************/
template < typename Func > FORCE_INLINE CCallbackThread::CCallbackThread(Func f) :
CThread() ,
m_pFunc(new CallbackFuncImpl<Func>(f)) {
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CCallbackThread::~CCallbackThread(){
	Release();
}
/*************************************************************************//*!
		@brief			スレッドの内部実行処理<br>
						コンストラクタで与えられたのCRunnableのRunを実行する。
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CCallbackThread::Run(void){
	(*m_pFunc)();
}
/*************************************************************************//*!
		@brief			解放
		@param[in]		pData			解放追加データ

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCallbackThread::Release(LPMofVoid pData){
	if(Join())
	{
		MOF_SAFE_DELETE(m_pFunc);
		return TRUE;
	}
	return FALSE;
}

//[EOF]