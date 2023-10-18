/*************************************************************************//*!
					
					@file	XAudioStreamingSoundBuffer.inl
					@brief	XAudio2での各種サウンドバッファの処理を行う基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			同時再生数の設定
		@param[in]		cnt			数
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CXAudioStreamingSoundBuffer::SetBufferCount(MofU32 cnt) {
	return FALSE;
}
/*************************************************************************//*!
		@brief			サウンドバッファ取得
		@param			None

		@return			サウンドバッファ
*//**************************************************************************/
FORCE_INLINE MofSoundBuffer CXAudioStreamingSoundBuffer::GetBuffer(void){
	return m_pBuffer;
}

//[EOF]