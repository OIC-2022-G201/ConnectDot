/*************************************************************************//*!
					
					@file	DynamicArray.inl
					@brief	動的配列の確保、管理の処理を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			内部解放<br>
						内部解放処理を特殊化で処理<br>
						ポインタ型でDYNAMICARRAY_ARRAYMEMBERDELETEフラグが立っている場合は内部のデータにDeleteを実行する。
*//**************************************************************************/
template < > struct CDynamicArrayImpl::ReleaseImpl< CString > {
	static MofBool Run(CString pVal)
	{
		pVal.SetString(NULL);
		return TRUE;
	}
	static MofBool Run(LPMofVoid pData,CString* pArray,MofU32 Count)
	{
		for(MofU32 i = 0;i < Count;i++)
		{
			pArray[i].SetString(NULL);
		}
		MOF_SAFE_DELETE_ARRAY(pArray);
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >::CDynamicArray() :
m_pArray(NULL) ,
m_Count(0) ,
m_Flag(DYNAMICARRAY_ARRAYMEMBERDELETE | DYNAMICARRAY_ARRAYMEMBERCOPY) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		Count			要素数

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >::CDynamicArray(MofU32 Count) :
m_pArray(NULL) ,
m_Count(Count) ,
m_Flag(DYNAMICARRAY_ARRAYMEMBERDELETE | DYNAMICARRAY_ARRAYMEMBERCOPY) {
	if(m_Count > 0)
	{
		m_pArray = new T[m_Count];
	}
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		List			要素
		@param[in]		Count			要素数

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >::CDynamicArray(T* List,MofU32 Count) :
m_pArray(NULL) ,
m_Count(Count) ,
m_Flag(DYNAMICARRAY_ARRAYMEMBERDELETE | DYNAMICARRAY_ARRAYMEMBERCOPY) {
	if(m_Count > 0)
	{
		m_pArray = new T[m_Count];
		if(List)
		{
			for(MofU32 i = 0;i < m_Count;i++)
			{
				m_pArray[i] = List[i];
			}
		}
	}
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj			コピー配列

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >::CDynamicArray(const CDynamicArray< T >& pObj) :
m_pArray(NULL) ,
m_Count(pObj.m_Count) ,
m_Flag(pObj.m_Flag) {
	if(m_Count > 0)
	{
		m_pArray = new T[m_Count];
		if(pObj.m_pArray)
		{
			if(m_Flag & DYNAMICARRAY_ARRAYMEMBERCOPY)
			{
				CopyImpl< T, IsMofInheritance< T , IMofCopyImpl >::value >::Run(m_pArray,pObj.m_pArray,m_Count);
			}
			else
			{
				for(MofU32 i = 0;i < m_Count;i++)
				{
					m_pArray[i] = pObj.m_pArray[i];
				}
			}
		}
	}
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >::~CDynamicArray(){
	Release();
}
/*************************************************************************//*!
		@brief			配列最後尾に要素の追加
		@param			None
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Add(void){
	T Data;
	return AddNo(&Data,m_Count);
}
/*************************************************************************//*!
		@brief			配列最後尾に要素の追加
		@param[in]		Data			追加データ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Add(T* Data){
	return AddNo(Data,m_Count);
}
/*************************************************************************//*!
		@brief			配列最後尾に要素の追加
		@param[in]		Data			追加データ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Add(const T& Data){
	return AddNo(Data,m_Count);
}
/*************************************************************************//*!
		@brief			配列先頭に要素の追加
		@param			None
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddFast(void){
	T Data;
	return AddNo(&Data,0);
}
/*************************************************************************//*!
		@brief			配列先頭に要素の追加
		@param[in]		Data			追加データ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddFast(T* Data){
	return AddNo(Data,0);
}
/*************************************************************************//*!
		@brief			配列先頭に要素の追加
		@param[in]		Data			追加データ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddFast(const T& Data){
	return AddNo(Data, 0);
}
/*************************************************************************//*!
		@brief			配列指定位置に要素の追加
		@param[in]		No				追加位置
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddNo(MofU32 No){
	T Data;
	return AddNo(&Data,No);
}
/*************************************************************************//*!
		@brief			配列指定位置に要素の追加
		@param[in]		Data			追加データ
		@param[in]		No				追加位置
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddNo(T* Data,MofU32 No){
	//最大数以上なら最後に追加
	if(No >= m_Count)
	{
		No = m_Count;
	}
	//とりあえず指定サイズ分メモリ確保
	T* tmp = new T[m_Count + 1];
	//データ確保の失敗
	if(!tmp)
	{
		return FALSE;
	}
	//情報をコピー
	for(MofU32 i = 0;i < m_Count;i++)
	{
		tmp[((i >= No) ? i + 1 : i)] = m_pArray[i];
	}
	tmp[No] = *Data;
	//現在までのデータ領域を開放する
	MOF_SAFE_DELETE_ARRAY(m_pArray);
	//確保データへ差し替え
	m_Count++;
	m_pArray = tmp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列指定位置に要素の追加
		@param[in]		Data			追加データ
		@param[in]		No				追加位置
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddNo(const T& Data, MofU32 No){
	//最大数以上なら最後に追加
	if (No >= m_Count)
	{
		No = m_Count;
	}
	//とりあえず指定サイズ分メモリ確保
	T* tmp = new T[m_Count + 1];
	//データ確保の失敗
	if (!tmp)
	{
		return FALSE;
	}
	//情報をコピー
	for (MofU32 i = 0; i < m_Count; i++)
	{
		tmp[((i >= No) ? i + 1 : i)] = m_pArray[i];
	}
	tmp[No] = Data;
	//現在までのデータ領域を開放する
	MOF_SAFE_DELETE_ARRAY(m_pArray);
	//確保データへ差し替え
	m_Count++;
	m_pArray = tmp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列最後尾に要素の追加
		@param			None
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddLast(void){
	T Data;
	return AddNo(&Data,m_Count);
}
/*************************************************************************//*!
		@brief			配列最後尾に要素の追加
		@param[in]		Data			追加データ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddLast(T* Data){
	return AddNo(Data,m_Count);
}
/*************************************************************************//*!
		@brief			配列最後尾に要素の追加
		@param[in]		Data			追加データ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddLast(const T& Data){
	return AddNo(Data, m_Count);
}
/*************************************************************************//*!
		@brief			配列最後尾に引数の配列要素を追加
		@param[in]		m				追加データ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddList(CDynamicArray< T >* m){
	//失敗
	if(!m)
	{
		return FALSE;
	}
	//サイズ設定
	MofU32 Now = m_Count;
	if(!ReSize(m_Count + m->GetArrayCount()))
	{
		return FALSE;
	}
	//リストを追加
	for(MofU32 i = 0;i < m->GetArrayCount();i++)
	{
		SetData(m->GetData(i),i + Now);
	}
	//正常終了
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列指定要素の削除
		@param[in]		Data			削除要素
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Delete(T* Data){
	//検索
	for(MofU32 i = 0;i < m_Count;i++)
	{
		if(memcmp(Data,&m_pArray[i],sizeof(T)) == 0)
		{
			return Delete(i);
		}
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			配列指定位置の要素の削除
		@param[in]		No				削除位置
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Delete(MofU32 No){
	//最大数以上なら失敗する
	if(No >= m_Count)
	{
		return FALSE;
	}
	//とりあえず指定サイズ分メモリ確保
	T* tmp = new T[m_Count - 1];
	//データ確保の失敗
	if(!tmp)
	{
		return FALSE;
	}
	//情報をコピー
	for(MofU32 i = 0,n = 0;i < m_Count;i++)
	{
		if(i == No)
		{
			continue;
		}
		tmp[n++] = m_pArray[i];
	}
	//現在までのデータ領域を開放する
	if(m_Flag & DYNAMICARRAY_ARRAYMEMBERDELETE)
	{
		ReleaseImpl< T >::Run(m_pArray[No]);
	}
	MOF_SAFE_DELETE_ARRAY(m_pArray);
	//確保データへ差し替え
	m_Count--;
	m_pArray = tmp;
	//正常終了
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列先頭の要素の削除
		@param			None
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::DeleteFast(void){
	if(m_Count <= 0)
	{
		return FALSE;
	}
	return Delete((MofU32)0);
}
/*************************************************************************//*!
		@brief			配列最後尾の要素の削除
		@param			None
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::DeleteLast(void){
	if(m_Count <= 0)
	{
		return FALSE;
	}
	return Delete(m_Count - 1);
}
/*************************************************************************//*!
		@brief			配列の要素位置を入れ替える
		@param[in]		Ind1			配列要素位置
		@param[in]		Ind2			配列要素位置
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Swap(MofU32 Ind1,MofU32 Ind2){
	if(Ind1 >= m_Count || Ind2 >= m_Count)
	{
		return FALSE;
	}
	//メモリをコピーするための一時領域
	T temp = m_pArray[Ind1];
	//コピー
	m_pArray[Ind1] = m_pArray[Ind2];
	m_pArray[Ind2] = temp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列のソートを実行する
		@param[in]		pFunc			比較関数
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Sort(int (*pFunc)(const void *, const void *)){
	//データが無いと失敗
	if(!m_pArray)
	{
		return FALSE;
	}
	//ソート実行
	qsort(m_pArray,m_Count,sizeof(T),pFunc);
	//正常終了
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列のソートを実行する
		@param[in]		pFunc			比較関数
		@param[in]		Count			ソート対象数
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Sort(int(*pFunc)(const void *, const void *), MofU32 Count){
	//データが無いと失敗
	if (!m_pArray)
	{
		return FALSE;
	}
	//ソート実行
	qsort(m_pArray, Count, sizeof(T), pFunc);
	//正常終了
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列内で名前で検索を行う。
						ポインタ型でIMofNamedObjectを継承している場合、GetNameで取得できる名前と引数を比較する<br>
						IMofNamedObjectを継承していない場合は検索に失敗する。
		@param[in]		pName			名前
				
		@return			発見した要素のアドレス
						見つからなかった場合NULLを返す
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CDynamicArray< T >::Find(LPCMofChar pName){
	return FindNameImpl< T, IsMofInheritance< T , IMofNamedObjectImpl >::value >::Run(m_pArray,m_Count,pName);
}
/*************************************************************************//*!
		@brief			配列の件数を設定する
		@param[in]		Count			要素数
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::ReSize(MofU32 Count){
	//０件なら消して終了
	if(Count <= 0)
	{
		return Release();
	}
	//とりあえず指定サイズ分メモリ確保
	T* tmp = new T[Count];
	//データ確保の失敗
	if(!tmp)
	{
		return FALSE;
	}
	//現在までのデータをコピー
	if(m_pArray)
	{
		for(MofU32 i = 0;i < MOF_MIN(Count,m_Count);i++)
		{
			tmp[i] = m_pArray[i];
		}
		if(m_Flag & DYNAMICARRAY_ARRAYMEMBERDELETE && Count < m_Count)
		{
			for(MofU32 i = Count;i < m_Count;i++)
			{
				ReleaseImpl< T >::Run(m_pArray[i]);
			}
		}
	}
	//現在までのデータを解放する
	MOF_SAFE_DELETE_ARRAY(m_pArray);
	//確保データへ差し替え
	m_Count = Count;
	m_pArray = tmp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			解放
		@param[in]		pData			解放追加データ

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Release(LPMofVoid pData){
	if(m_Flag & DYNAMICARRAY_ARRAYMEMBERDELETE)
	{
		ReleaseImpl< T >::Run(pData,m_pArray,m_Count);
		m_pArray = NULL;
	}
	else
	{
		MOF_SAFE_DELETE_ARRAY(m_pArray);
	}
	m_Count = 0;
	return TRUE;
}

/*************************************************************************//*!
		@brief			配列の件数、データを設定する
		@param[in]		pData			要素
		@param[in]		Count			要素数
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::SetArray(T* pData,MofU32 Count){
	//０件なら消して終了
	if(Count <= 0)
	{
		return Release();
	}
	//とりあえず指定サイズ分メモリ確保
	T* tmp = new T[Count];
	//データ確保の失敗
	if(!tmp)
	{
		return FALSE;
	}
	//設定データをコピー
	if(pData)
	{
		for(MofU32 i = 0;i < Count;i++)
		{
			tmp[i] = pData[i];
		}
	}
	//現在までのデータを解放する
	if(m_Flag & DYNAMICARRAY_ARRAYMEMBERDELETE)
	{
		ReleaseImpl< T >::Run(pData,m_pArray,m_Count);
		m_pArray = NULL;
	}
	else
	{
		MOF_SAFE_DELETE_ARRAY(m_pArray);
	}
	//確保データへ差し替え
	m_Count = Count;
	m_pArray = tmp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列の指定要素に対してデータを設定する
		@param[in]		Data			要素
		@param[in]		No				要素位置
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::SetData(const T& Data,MofU32 No){
	//最大数以上なら確保しなおし
	if(No >= m_Count)
	{
		T* tmp = new T[No + 1];
		if(!tmp)
		{
			return FALSE;
		}
		for(MofU32 i = 0;i < m_Count;i++)
		{
			tmp[i] = m_pArray[i];
		}
		MOF_SAFE_DELETE_ARRAY(m_pArray);
		m_Count = No + 1;
		m_pArray = tmp;
	}
	//新しいデータを格納
	m_pArray[No] = Data;
	//正常終了
	return TRUE;
}
/*************************************************************************//*!
		@brief			フラグの設定
		@param[in]		Flag			フラグ
			
		@return			TRUE			正常に設定された<br>
						FALSE			追加の失敗
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::SetFlag(MofU32 Flag){
	m_Flag = Flag;
	return TRUE;
}
/*************************************************************************//*!
		@brief			配列要素数取得
		@param			None

		@return			配列要素数
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CDynamicArray< T >::GetArrayCount(void) const{
	return m_Count;
}
/*************************************************************************//*!
		@brief			配列取得
		@param			None

		@return			配列
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CDynamicArray< T >::GetArray(void) const{
	return m_pArray;
}
/*************************************************************************//*!
		@brief			配列要素番号取得
		@param[in]		Data			検索データ

		@return			配列要素番号
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CDynamicArray< T >::GetDataNo(T* Data) const{
	//検索
	for(MofU32 i = 0;i < m_Count;i++)
	{
		if(m_pArray[i] == *Data)
		{
			return i;
		}
	}
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			配列要素アドレス取得
		@param[in]		n				要素番号

		@return			配列要素アドレス
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CDynamicArray< T >::GetDataAddress(MofU32 n) const{
	if(n >= m_Count)
	{
		return NULL;
	}
	return &m_pArray[n];
}
/*************************************************************************//*!
		@brief			配列要素取得
		@param[in]		n				要素番号

		@return			配列要素
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CDynamicArray< T >::GetData(MofU32 n){
	return m_pArray[n];
}
/*************************************************************************//*!
		@brief			配列要素取得
		@param[in]		n				要素番号

		@return			配列要素
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CDynamicArray< T >::GetData(MofU32 n) const {
	return m_pArray[n];
}
/*************************************************************************//*!
		@brief			フラグ取得
		@param			None

		@return			フラグ
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CDynamicArray< T >::GetFlag(void) const{
	return m_Flag;
}

/*************************************************************************//*!
		@brief			リスト代入<br>
						SetArray関数を内部で実行する。
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >& CDynamicArray< T >::operator = (const CDynamicArray& pObj){
	//データコピー
	SetArray(pObj.m_pArray,pObj.m_Count);
	return (*this);
}
/*************************************************************************//*!
		@brief			配列要素アクセス<br>
						n番目の要素を返す。
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CDynamicArray< T >::operator [] (int n){
	return m_pArray[n];
}
/*************************************************************************//*!
		@brief			配列要素アクセス<br>
						n番目の要素を返す。
*//**************************************************************************/
template < typename T > FORCE_INLINE const T& CDynamicArray< T >::operator [] (int n) const {
	return m_pArray[n];
}

//[EOF]