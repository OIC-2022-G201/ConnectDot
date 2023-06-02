/*************************************************************************//*!
					
					@file	StringA.inl
					@brief	マルチバイト文字列関連の処理を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			文字列の削除<br>
						現在の文字列の指定位置から後ろの文字列を削除する。
		@param[in]		s			開始位置
			
		@return			TRUE		正常に削除された<br>
						FALSE		追加の失敗
*//**************************************************************************/
FORCE_INLINE MofBool MOF_STRINGIMPL_NAME::Delete(const MofU32 s){
	return Delete(s,m_StrLength);
}
/*************************************************************************//*!
		@brief			文字列の比較<br>
						指定された文字列が比較対象の文字列のと一致するかを判定する。<br>
						大文字、小文字の区別を行う、行わない場合はCompareCaseを利用する。
		@param[in]		s			比較文字列
			
		@return			0			一致
						> 0			先頭文字が自分が大きい
						< 0			先頭文字が比較文字列が大きい
*//**************************************************************************/
FORCE_INLINE MofS32 MOF_STRINGIMPL_NAME::Compare(const MOF_STRINGIMPL_TYPE* s) const {
	return Compare(m_pStr,s);
}
/*************************************************************************//*!
		@brief			文字列の比較<br>
						指定された文字列が比較対象の文字列のと一致するかを判定する。<br>
						大文字、小文字の区別を行う、行わない場合はCompareCaseを利用する。
		@param[in]		s			比較文字列
		@param[in]		l			比較文字列の長さ
			
		@return			0			一致
						> 0			先頭文字が自分が大きい
						< 0			先頭文字が比較文字列が大きい
*//**************************************************************************/
FORCE_INLINE MofS32 MOF_STRINGIMPL_NAME::Compare(const MOF_STRINGIMPL_TYPE* s,MofU32 l) const {
	return Compare(m_pStr,s,l);
}
/*************************************************************************//*!
		@brief			文字列の比較<br>
						指定された文字列が比較対象の文字列のと一致するかを判定する。<br>
						大文字、小文字の区別を行わない、行う場合はCompareを利用する。
		@param[in]		s			比較文字列
			
		@return			0			一致
						> 0			先頭文字が自分が大きい
						< 0			先頭文字が比較文字列が大きい
*//**************************************************************************/
FORCE_INLINE MofS32 MOF_STRINGIMPL_NAME::CompareCase(const MOF_STRINGIMPL_TYPE* s) const {
	return CompareCase(m_pStr,s);
}
/*************************************************************************//*!
		@brief			文字列の比較<br>
						指定された文字列が比較対象の文字列のと一致するかを判定する。<br>
						大文字、小文字の区別を行わない、行う場合はCompareを利用する。
		@param[in]		s			比較文字列
		@param[in]		l			比較文字列の長さ
			
		@return			0			一致
						> 0			先頭文字が自分が大きい
						< 0			先頭文字が比較文字列が大きい
*//**************************************************************************/
FORCE_INLINE MofS32 MOF_STRINGIMPL_NAME::CompareCase(const MOF_STRINGIMPL_TYPE* s,MofU32 l) const {
	return CompareCase(m_pStr,s,l);
}
/*************************************************************************//*!
		@brief			文字列の検索<br>
						指定された文字列が文字列の中に存在するかを検索する。<br>
						大文字、小文字の区別を行う、行わない場合はSearchCaseを利用する。
		@param[in]		s			文字列
			
		@return			NULL		存在しない
						存在する場合、指定された文字列の先頭アドレス
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::Search(const MOF_STRINGIMPL_TYPE* s){
	return Search(m_pStr,s);
}
/*************************************************************************//*!
		@brief			文字列の検索<br>
						指定された文字列が文字列の中に存在するかを検索する。<br>
						大文字、小文字の区別を行う、行わない場合はSearchCaseを利用する。
		@param[in]		s			文字列
		@param[in]		l			文字列の長さ
			
		@return			NULL		存在しない
						存在する場合、指定された文字列の先頭アドレス
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::Search(const MOF_STRINGIMPL_TYPE* s,MofU32 l){
	return Search(m_pStr,s,l);
}
/*************************************************************************//*!
		@brief			文字列の検索<br>
						指定された文字列が文字列の中に存在するかを検索する。<br>
						大文字、小文字の区別を行わない、行う場合はSearchを利用する。
		@param[in]		s			文字列
			
		@return			NULL		存在しない
						存在する場合、指定された文字列の先頭アドレス
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::SearchCase(const MOF_STRINGIMPL_TYPE* s){
	return SearchCase(m_pStr,s);
}
/*************************************************************************//*!
		@brief			文字列の検索<br>
						指定された文字列が文字列の中に存在するかを検索する。<br>
						大文字、小文字の区別を行わない、行う場合はSearchを利用する。
		@param[in]		s			文字列
		@param[in]		l			文字列の長さ
			
		@return			NULL		存在しない
						存在する場合、指定された文字列の先頭アドレス
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::SearchCase(const MOF_STRINGIMPL_TYPE* s,MofU32 l){
	return SearchCase(m_pStr,s,l);
}
/*************************************************************************//*!
		@brief			内部文字列取得
		@param			None

		@return			文字列
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::GetString(void) const{
	return m_pStr;
}
/*************************************************************************//*!
		@brief			内部文字取得
		@param[in]		i			位置

		@return			文字列
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE MOF_STRINGIMPL_NAME::GetAt(int i) const{
	return m_pStr[i];
}
/*************************************************************************//*!
		@brief			内部文字数取得
		@param			None

		@return			文字数
*//**************************************************************************/
FORCE_INLINE MofU32 MOF_STRINGIMPL_NAME::GetLength(void) const{
	return m_StrLength;
}
/*************************************************************************//*!
		@brief			内部文字列バイト数取得
		@param			None

		@return			文字列バイト数
*//**************************************************************************/
FORCE_INLINE MofU32 MOF_STRINGIMPL_NAME::GetStringSize(void) const{
	return (m_StrLength + 1) * sizeof(MOF_STRINGIMPL_TYPE);
}
/*************************************************************************//*!
		@brief			文字列キャスト<br>
						内部のm_pStrをそのまま返す。
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME::operator MOF_STRINGIMPL_TYPE* (){
	return m_pStr;
}
/*************************************************************************//*!
		@brief			文字列キャスト<br>
						内部のm_pStrをそのまま返す。
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME::operator const MOF_STRINGIMPL_TYPE* () const {
	return m_pStr;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME& MOF_STRINGIMPL_NAME::operator += ( const MOF_STRINGIMPL_TYPE* s ){
	Add(s);
	return *this;
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME MOF_STRINGIMPL_NAME::operator + ( const MOF_STRINGIMPL_TYPE* v ) const{
	MOF_STRINGIMPL_NAME re(*this);
	re.Add(v);
	return re;
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME MOF_STRINGIMPL_NAME::operator + ( const MofS32& s ) const{
	MOF_STRINGIMPL_NAME re = *this;
	re += s;
	return re;
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME MOF_STRINGIMPL_NAME::operator + ( const MofU32& s ) const{
	MOF_STRINGIMPL_NAME re = *this;
	re += s;
	return re;
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME MOF_STRINGIMPL_NAME::operator + ( const MofFloat& s ) const{
	MOF_STRINGIMPL_NAME re = *this;
	re += s;
	return re;
}
/*************************************************************************//*!
		@brief			配列指定による文字列へのアクセス
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE& MOF_STRINGIMPL_NAME::operator [] ( int i ){
	return m_pStr[i];
}
/*************************************************************************//*!
		@brief			配列指定による文字列へのアクセス
*//**************************************************************************/
FORCE_INLINE const MOF_STRINGIMPL_TYPE& MOF_STRINGIMPL_NAME::operator [] ( int i ) const{
	return m_pStr[i];
}
/*************************************************************************//*!
		@brief			文字列代入<br>
						SetString関数を内部で実行する。
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME& MOF_STRINGIMPL_NAME::operator = ( const MOF_STRINGIMPL_TYPE* s ){
	SetString(s);
	return *this;
}
/*************************************************************************//*!
		@brief			文字列代入<br>
						SetString関数を内部で実行する。
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME& MOF_STRINGIMPL_NAME::operator = ( const MOF_STRINGIMPL_NAME& s ){
	SetString(s.m_pStr);
	return *this;
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool MOF_STRINGIMPL_NAME::operator == ( const MOF_STRINGIMPL_TYPE* v ) const{
	return ((Compare(m_pStr,v) == 0) ? true : false);
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool MOF_STRINGIMPL_NAME::operator == ( const MOF_STRINGIMPL_NAME& v ) const{
	return ((Compare(m_pStr,v.m_pStr) == 0) ? true : false);
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool MOF_STRINGIMPL_NAME::operator != ( const MOF_STRINGIMPL_TYPE* v ) const{
	return ((Compare(m_pStr,v) == 0) ? false : true);
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool MOF_STRINGIMPL_NAME::operator != ( const MOF_STRINGIMPL_NAME& v ) const{
	return ((Compare(m_pStr,v.m_pStr) == 0) ? false : true);
}

//[EOF]