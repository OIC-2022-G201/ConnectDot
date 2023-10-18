/*************************************************************************//*!
					
					@file	DynamicArray.inl
					@brief	���I�z��̊m�ہA�Ǘ��̏������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�������<br>
						���������������ꉻ�ŏ���<br>
						�|�C���^�^��DYNAMICARRAY_ARRAYMEMBERDELETE�t���O�������Ă���ꍇ�͓����̃f�[�^��Delete�����s����B
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
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >::CDynamicArray() :
m_pArray(NULL) ,
m_Count(0) ,
m_Flag(DYNAMICARRAY_ARRAYMEMBERDELETE | DYNAMICARRAY_ARRAYMEMBERCOPY) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		Count			�v�f��

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
		@brief			�R���X�g���N�^
		@param[in]		List			�v�f
		@param[in]		Count			�v�f��

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
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj			�R�s�[�z��

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
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >::~CDynamicArray(){
	Release();
}
/*************************************************************************//*!
		@brief			�z��Ō���ɗv�f�̒ǉ�
		@param			None
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Add(void){
	T Data;
	return AddNo(&Data,m_Count);
}
/*************************************************************************//*!
		@brief			�z��Ō���ɗv�f�̒ǉ�
		@param[in]		Data			�ǉ��f�[�^
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Add(T* Data){
	return AddNo(Data,m_Count);
}
/*************************************************************************//*!
		@brief			�z��Ō���ɗv�f�̒ǉ�
		@param[in]		Data			�ǉ��f�[�^
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Add(const T& Data){
	return AddNo(Data,m_Count);
}
/*************************************************************************//*!
		@brief			�z��擪�ɗv�f�̒ǉ�
		@param			None
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddFast(void){
	T Data;
	return AddNo(&Data,0);
}
/*************************************************************************//*!
		@brief			�z��擪�ɗv�f�̒ǉ�
		@param[in]		Data			�ǉ��f�[�^
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddFast(T* Data){
	return AddNo(Data,0);
}
/*************************************************************************//*!
		@brief			�z��擪�ɗv�f�̒ǉ�
		@param[in]		Data			�ǉ��f�[�^
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddFast(const T& Data){
	return AddNo(Data, 0);
}
/*************************************************************************//*!
		@brief			�z��w��ʒu�ɗv�f�̒ǉ�
		@param[in]		No				�ǉ��ʒu
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddNo(MofU32 No){
	T Data;
	return AddNo(&Data,No);
}
/*************************************************************************//*!
		@brief			�z��w��ʒu�ɗv�f�̒ǉ�
		@param[in]		Data			�ǉ��f�[�^
		@param[in]		No				�ǉ��ʒu
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddNo(T* Data,MofU32 No){
	//�ő吔�ȏ�Ȃ�Ō�ɒǉ�
	if(No >= m_Count)
	{
		No = m_Count;
	}
	//�Ƃ肠�����w��T�C�Y���������m��
	T* tmp = new T[m_Count + 1];
	//�f�[�^�m�ۂ̎��s
	if(!tmp)
	{
		return FALSE;
	}
	//�����R�s�[
	for(MofU32 i = 0;i < m_Count;i++)
	{
		tmp[((i >= No) ? i + 1 : i)] = m_pArray[i];
	}
	tmp[No] = *Data;
	//���݂܂ł̃f�[�^�̈���J������
	MOF_SAFE_DELETE_ARRAY(m_pArray);
	//�m�ۃf�[�^�֍����ւ�
	m_Count++;
	m_pArray = tmp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z��w��ʒu�ɗv�f�̒ǉ�
		@param[in]		Data			�ǉ��f�[�^
		@param[in]		No				�ǉ��ʒu
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddNo(const T& Data, MofU32 No){
	//�ő吔�ȏ�Ȃ�Ō�ɒǉ�
	if (No >= m_Count)
	{
		No = m_Count;
	}
	//�Ƃ肠�����w��T�C�Y���������m��
	T* tmp = new T[m_Count + 1];
	//�f�[�^�m�ۂ̎��s
	if (!tmp)
	{
		return FALSE;
	}
	//�����R�s�[
	for (MofU32 i = 0; i < m_Count; i++)
	{
		tmp[((i >= No) ? i + 1 : i)] = m_pArray[i];
	}
	tmp[No] = Data;
	//���݂܂ł̃f�[�^�̈���J������
	MOF_SAFE_DELETE_ARRAY(m_pArray);
	//�m�ۃf�[�^�֍����ւ�
	m_Count++;
	m_pArray = tmp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z��Ō���ɗv�f�̒ǉ�
		@param			None
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddLast(void){
	T Data;
	return AddNo(&Data,m_Count);
}
/*************************************************************************//*!
		@brief			�z��Ō���ɗv�f�̒ǉ�
		@param[in]		Data			�ǉ��f�[�^
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddLast(T* Data){
	return AddNo(Data,m_Count);
}
/*************************************************************************//*!
		@brief			�z��Ō���ɗv�f�̒ǉ�
		@param[in]		Data			�ǉ��f�[�^
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddLast(const T& Data){
	return AddNo(Data, m_Count);
}
/*************************************************************************//*!
		@brief			�z��Ō���Ɉ����̔z��v�f��ǉ�
		@param[in]		m				�ǉ��f�[�^
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::AddList(CDynamicArray< T >* m){
	//���s
	if(!m)
	{
		return FALSE;
	}
	//�T�C�Y�ݒ�
	MofU32 Now = m_Count;
	if(!ReSize(m_Count + m->GetArrayCount()))
	{
		return FALSE;
	}
	//���X�g��ǉ�
	for(MofU32 i = 0;i < m->GetArrayCount();i++)
	{
		SetData(m->GetData(i),i + Now);
	}
	//����I��
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z��w��v�f�̍폜
		@param[in]		Data			�폜�v�f
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Delete(T* Data){
	//����
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
		@brief			�z��w��ʒu�̗v�f�̍폜
		@param[in]		No				�폜�ʒu
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Delete(MofU32 No){
	//�ő吔�ȏ�Ȃ玸�s����
	if(No >= m_Count)
	{
		return FALSE;
	}
	//�Ƃ肠�����w��T�C�Y���������m��
	T* tmp = new T[m_Count - 1];
	//�f�[�^�m�ۂ̎��s
	if(!tmp)
	{
		return FALSE;
	}
	//�����R�s�[
	for(MofU32 i = 0,n = 0;i < m_Count;i++)
	{
		if(i == No)
		{
			continue;
		}
		tmp[n++] = m_pArray[i];
	}
	//���݂܂ł̃f�[�^�̈���J������
	if(m_Flag & DYNAMICARRAY_ARRAYMEMBERDELETE)
	{
		ReleaseImpl< T >::Run(m_pArray[No]);
	}
	MOF_SAFE_DELETE_ARRAY(m_pArray);
	//�m�ۃf�[�^�֍����ւ�
	m_Count--;
	m_pArray = tmp;
	//����I��
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z��擪�̗v�f�̍폜
		@param			None
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::DeleteFast(void){
	if(m_Count <= 0)
	{
		return FALSE;
	}
	return Delete((MofU32)0);
}
/*************************************************************************//*!
		@brief			�z��Ō���̗v�f�̍폜
		@param			None
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::DeleteLast(void){
	if(m_Count <= 0)
	{
		return FALSE;
	}
	return Delete(m_Count - 1);
}
/*************************************************************************//*!
		@brief			�z��̗v�f�ʒu�����ւ���
		@param[in]		Ind1			�z��v�f�ʒu
		@param[in]		Ind2			�z��v�f�ʒu
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Swap(MofU32 Ind1,MofU32 Ind2){
	if(Ind1 >= m_Count || Ind2 >= m_Count)
	{
		return FALSE;
	}
	//���������R�s�[���邽�߂̈ꎞ�̈�
	T temp = m_pArray[Ind1];
	//�R�s�[
	m_pArray[Ind1] = m_pArray[Ind2];
	m_pArray[Ind2] = temp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z��̃\�[�g�����s����
		@param[in]		pFunc			��r�֐�
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Sort(int (*pFunc)(const void *, const void *)){
	//�f�[�^�������Ǝ��s
	if(!m_pArray)
	{
		return FALSE;
	}
	//�\�[�g���s
	qsort(m_pArray,m_Count,sizeof(T),pFunc);
	//����I��
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z��̃\�[�g�����s����
		@param[in]		pFunc			��r�֐�
		@param[in]		Count			�\�[�g�Ώې�
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::Sort(int(*pFunc)(const void *, const void *), MofU32 Count){
	//�f�[�^�������Ǝ��s
	if (!m_pArray)
	{
		return FALSE;
	}
	//�\�[�g���s
	qsort(m_pArray, Count, sizeof(T), pFunc);
	//����I��
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z����Ŗ��O�Ō������s���B
						�|�C���^�^��IMofNamedObject���p�����Ă���ꍇ�AGetName�Ŏ擾�ł��閼�O�ƈ������r����<br>
						IMofNamedObject���p�����Ă��Ȃ��ꍇ�͌����Ɏ��s����B
		@param[in]		pName			���O
				
		@return			���������v�f�̃A�h���X
						������Ȃ������ꍇNULL��Ԃ�
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CDynamicArray< T >::Find(LPCMofChar pName){
	return FindNameImpl< T, IsMofInheritance< T , IMofNamedObjectImpl >::value >::Run(m_pArray,m_Count,pName);
}
/*************************************************************************//*!
		@brief			�z��̌�����ݒ肷��
		@param[in]		Count			�v�f��
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::ReSize(MofU32 Count){
	//�O���Ȃ�����ďI��
	if(Count <= 0)
	{
		return Release();
	}
	//�Ƃ肠�����w��T�C�Y���������m��
	T* tmp = new T[Count];
	//�f�[�^�m�ۂ̎��s
	if(!tmp)
	{
		return FALSE;
	}
	//���݂܂ł̃f�[�^���R�s�[
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
	//���݂܂ł̃f�[�^���������
	MOF_SAFE_DELETE_ARRAY(m_pArray);
	//�m�ۃf�[�^�֍����ւ�
	m_Count = Count;
	m_pArray = tmp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���
		@param[in]		pData			����ǉ��f�[�^

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
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
		@brief			�z��̌����A�f�[�^��ݒ肷��
		@param[in]		pData			�v�f
		@param[in]		Count			�v�f��
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::SetArray(T* pData,MofU32 Count){
	//�O���Ȃ�����ďI��
	if(Count <= 0)
	{
		return Release();
	}
	//�Ƃ肠�����w��T�C�Y���������m��
	T* tmp = new T[Count];
	//�f�[�^�m�ۂ̎��s
	if(!tmp)
	{
		return FALSE;
	}
	//�ݒ�f�[�^���R�s�[
	if(pData)
	{
		for(MofU32 i = 0;i < Count;i++)
		{
			tmp[i] = pData[i];
		}
	}
	//���݂܂ł̃f�[�^���������
	if(m_Flag & DYNAMICARRAY_ARRAYMEMBERDELETE)
	{
		ReleaseImpl< T >::Run(pData,m_pArray,m_Count);
		m_pArray = NULL;
	}
	else
	{
		MOF_SAFE_DELETE_ARRAY(m_pArray);
	}
	//�m�ۃf�[�^�֍����ւ�
	m_Count = Count;
	m_pArray = tmp;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z��̎w��v�f�ɑ΂��ăf�[�^��ݒ肷��
		@param[in]		Data			�v�f
		@param[in]		No				�v�f�ʒu
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::SetData(const T& Data,MofU32 No){
	//�ő吔�ȏ�Ȃ�m�ۂ��Ȃ���
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
	//�V�����f�[�^���i�[
	m_pArray[No] = Data;
	//����I��
	return TRUE;
}
/*************************************************************************//*!
		@brief			�t���O�̐ݒ�
		@param[in]		Flag			�t���O
			
		@return			TRUE			����ɐݒ肳�ꂽ<br>
						FALSE			�ǉ��̎��s
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CDynamicArray< T >::SetFlag(MofU32 Flag){
	m_Flag = Flag;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�z��v�f���擾
		@param			None

		@return			�z��v�f��
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CDynamicArray< T >::GetArrayCount(void) const{
	return m_Count;
}
/*************************************************************************//*!
		@brief			�z��擾
		@param			None

		@return			�z��
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CDynamicArray< T >::GetArray(void) const{
	return m_pArray;
}
/*************************************************************************//*!
		@brief			�z��v�f�ԍ��擾
		@param[in]		Data			�����f�[�^

		@return			�z��v�f�ԍ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CDynamicArray< T >::GetDataNo(T* Data) const{
	//����
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
		@brief			�z��v�f�A�h���X�擾
		@param[in]		n				�v�f�ԍ�

		@return			�z��v�f�A�h���X
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CDynamicArray< T >::GetDataAddress(MofU32 n) const{
	if(n >= m_Count)
	{
		return NULL;
	}
	return &m_pArray[n];
}
/*************************************************************************//*!
		@brief			�z��v�f�擾
		@param[in]		n				�v�f�ԍ�

		@return			�z��v�f
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CDynamicArray< T >::GetData(MofU32 n){
	return m_pArray[n];
}
/*************************************************************************//*!
		@brief			�z��v�f�擾
		@param[in]		n				�v�f�ԍ�

		@return			�z��v�f
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CDynamicArray< T >::GetData(MofU32 n) const {
	return m_pArray[n];
}
/*************************************************************************//*!
		@brief			�t���O�擾
		@param			None

		@return			�t���O
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CDynamicArray< T >::GetFlag(void) const{
	return m_Flag;
}

/*************************************************************************//*!
		@brief			���X�g���<br>
						SetArray�֐�������Ŏ��s����B
*//**************************************************************************/
template < typename T > FORCE_INLINE CDynamicArray< T >& CDynamicArray< T >::operator = (const CDynamicArray& pObj){
	//�f�[�^�R�s�[
	SetArray(pObj.m_pArray,pObj.m_Count);
	return (*this);
}
/*************************************************************************//*!
		@brief			�z��v�f�A�N�Z�X<br>
						n�Ԗڂ̗v�f��Ԃ��B
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CDynamicArray< T >::operator [] (int n){
	return m_pArray[n];
}
/*************************************************************************//*!
		@brief			�z��v�f�A�N�Z�X<br>
						n�Ԗڂ̗v�f��Ԃ��B
*//**************************************************************************/
template < typename T > FORCE_INLINE const T& CDynamicArray< T >::operator [] (int n) const {
	return m_pArray[n];
}

//[EOF]