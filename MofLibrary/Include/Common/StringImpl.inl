/*************************************************************************//*!
					
					@file	StringA.inl
					@brief	�}���`�o�C�g������֘A�̏������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			������̍폜<br>
						���݂̕�����̎w��ʒu������̕�������폜����B
		@param[in]		s			�J�n�ʒu
			
		@return			TRUE		����ɍ폜���ꂽ<br>
						FALSE		�ǉ��̎��s
*//**************************************************************************/
FORCE_INLINE MofBool MOF_STRINGIMPL_NAME::Delete(const MofU32 s){
	return Delete(s,m_StrLength);
}
/*************************************************************************//*!
		@brief			������̔�r<br>
						�w�肳�ꂽ�����񂪔�r�Ώۂ̕�����̂ƈ�v���邩�𔻒肷��B<br>
						�啶���A�������̋�ʂ��s���A�s��Ȃ��ꍇ��CompareCase�𗘗p����B
		@param[in]		s			��r������
			
		@return			0			��v
						> 0			�擪�������������傫��
						< 0			�擪��������r�����񂪑傫��
*//**************************************************************************/
FORCE_INLINE MofS32 MOF_STRINGIMPL_NAME::Compare(const MOF_STRINGIMPL_TYPE* s) const {
	return Compare(m_pStr,s);
}
/*************************************************************************//*!
		@brief			������̔�r<br>
						�w�肳�ꂽ�����񂪔�r�Ώۂ̕�����̂ƈ�v���邩�𔻒肷��B<br>
						�啶���A�������̋�ʂ��s���A�s��Ȃ��ꍇ��CompareCase�𗘗p����B
		@param[in]		s			��r������
		@param[in]		l			��r������̒���
			
		@return			0			��v
						> 0			�擪�������������傫��
						< 0			�擪��������r�����񂪑傫��
*//**************************************************************************/
FORCE_INLINE MofS32 MOF_STRINGIMPL_NAME::Compare(const MOF_STRINGIMPL_TYPE* s,MofU32 l) const {
	return Compare(m_pStr,s,l);
}
/*************************************************************************//*!
		@brief			������̔�r<br>
						�w�肳�ꂽ�����񂪔�r�Ώۂ̕�����̂ƈ�v���邩�𔻒肷��B<br>
						�啶���A�������̋�ʂ��s��Ȃ��A�s���ꍇ��Compare�𗘗p����B
		@param[in]		s			��r������
			
		@return			0			��v
						> 0			�擪�������������傫��
						< 0			�擪��������r�����񂪑傫��
*//**************************************************************************/
FORCE_INLINE MofS32 MOF_STRINGIMPL_NAME::CompareCase(const MOF_STRINGIMPL_TYPE* s) const {
	return CompareCase(m_pStr,s);
}
/*************************************************************************//*!
		@brief			������̔�r<br>
						�w�肳�ꂽ�����񂪔�r�Ώۂ̕�����̂ƈ�v���邩�𔻒肷��B<br>
						�啶���A�������̋�ʂ��s��Ȃ��A�s���ꍇ��Compare�𗘗p����B
		@param[in]		s			��r������
		@param[in]		l			��r������̒���
			
		@return			0			��v
						> 0			�擪�������������傫��
						< 0			�擪��������r�����񂪑傫��
*//**************************************************************************/
FORCE_INLINE MofS32 MOF_STRINGIMPL_NAME::CompareCase(const MOF_STRINGIMPL_TYPE* s,MofU32 l) const {
	return CompareCase(m_pStr,s,l);
}
/*************************************************************************//*!
		@brief			������̌���<br>
						�w�肳�ꂽ�����񂪕�����̒��ɑ��݂��邩����������B<br>
						�啶���A�������̋�ʂ��s���A�s��Ȃ��ꍇ��SearchCase�𗘗p����B
		@param[in]		s			������
			
		@return			NULL		���݂��Ȃ�
						���݂���ꍇ�A�w�肳�ꂽ������̐擪�A�h���X
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::Search(const MOF_STRINGIMPL_TYPE* s){
	return Search(m_pStr,s);
}
/*************************************************************************//*!
		@brief			������̌���<br>
						�w�肳�ꂽ�����񂪕�����̒��ɑ��݂��邩����������B<br>
						�啶���A�������̋�ʂ��s���A�s��Ȃ��ꍇ��SearchCase�𗘗p����B
		@param[in]		s			������
		@param[in]		l			������̒���
			
		@return			NULL		���݂��Ȃ�
						���݂���ꍇ�A�w�肳�ꂽ������̐擪�A�h���X
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::Search(const MOF_STRINGIMPL_TYPE* s,MofU32 l){
	return Search(m_pStr,s,l);
}
/*************************************************************************//*!
		@brief			������̌���<br>
						�w�肳�ꂽ�����񂪕�����̒��ɑ��݂��邩����������B<br>
						�啶���A�������̋�ʂ��s��Ȃ��A�s���ꍇ��Search�𗘗p����B
		@param[in]		s			������
			
		@return			NULL		���݂��Ȃ�
						���݂���ꍇ�A�w�肳�ꂽ������̐擪�A�h���X
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::SearchCase(const MOF_STRINGIMPL_TYPE* s){
	return SearchCase(m_pStr,s);
}
/*************************************************************************//*!
		@brief			������̌���<br>
						�w�肳�ꂽ�����񂪕�����̒��ɑ��݂��邩����������B<br>
						�啶���A�������̋�ʂ��s��Ȃ��A�s���ꍇ��Search�𗘗p����B
		@param[in]		s			������
		@param[in]		l			������̒���
			
		@return			NULL		���݂��Ȃ�
						���݂���ꍇ�A�w�肳�ꂽ������̐擪�A�h���X
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::SearchCase(const MOF_STRINGIMPL_TYPE* s,MofU32 l){
	return SearchCase(m_pStr,s,l);
}
/*************************************************************************//*!
		@brief			����������擾
		@param			None

		@return			������
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE* MOF_STRINGIMPL_NAME::GetString(void) const{
	return m_pStr;
}
/*************************************************************************//*!
		@brief			���������擾
		@param[in]		i			�ʒu

		@return			������
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE MOF_STRINGIMPL_NAME::GetAt(int i) const{
	return m_pStr[i];
}
/*************************************************************************//*!
		@brief			�����������擾
		@param			None

		@return			������
*//**************************************************************************/
FORCE_INLINE MofU32 MOF_STRINGIMPL_NAME::GetLength(void) const{
	return m_StrLength;
}
/*************************************************************************//*!
		@brief			����������o�C�g���擾
		@param			None

		@return			������o�C�g��
*//**************************************************************************/
FORCE_INLINE MofU32 MOF_STRINGIMPL_NAME::GetStringSize(void) const{
	return (m_StrLength + 1) * sizeof(MOF_STRINGIMPL_TYPE);
}
/*************************************************************************//*!
		@brief			������L���X�g<br>
						������m_pStr�����̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME::operator MOF_STRINGIMPL_TYPE* (){
	return m_pStr;
}
/*************************************************************************//*!
		@brief			������L���X�g<br>
						������m_pStr�����̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME::operator const MOF_STRINGIMPL_TYPE* () const {
	return m_pStr;
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME& MOF_STRINGIMPL_NAME::operator += ( const MOF_STRINGIMPL_TYPE* s ){
	Add(s);
	return *this;
}
/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME MOF_STRINGIMPL_NAME::operator + ( const MOF_STRINGIMPL_TYPE* v ) const{
	MOF_STRINGIMPL_NAME re(*this);
	re.Add(v);
	return re;
}
/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME MOF_STRINGIMPL_NAME::operator + ( const MofS32& s ) const{
	MOF_STRINGIMPL_NAME re = *this;
	re += s;
	return re;
}
/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME MOF_STRINGIMPL_NAME::operator + ( const MofU32& s ) const{
	MOF_STRINGIMPL_NAME re = *this;
	re += s;
	return re;
}
/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME MOF_STRINGIMPL_NAME::operator + ( const MofFloat& s ) const{
	MOF_STRINGIMPL_NAME re = *this;
	re += s;
	return re;
}
/*************************************************************************//*!
		@brief			�z��w��ɂ�镶����ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_TYPE& MOF_STRINGIMPL_NAME::operator [] ( int i ){
	return m_pStr[i];
}
/*************************************************************************//*!
		@brief			�z��w��ɂ�镶����ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE const MOF_STRINGIMPL_TYPE& MOF_STRINGIMPL_NAME::operator [] ( int i ) const{
	return m_pStr[i];
}
/*************************************************************************//*!
		@brief			��������<br>
						SetString�֐�������Ŏ��s����B
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME& MOF_STRINGIMPL_NAME::operator = ( const MOF_STRINGIMPL_TYPE* s ){
	SetString(s);
	return *this;
}
/*************************************************************************//*!
		@brief			��������<br>
						SetString�֐�������Ŏ��s����B
*//**************************************************************************/
FORCE_INLINE MOF_STRINGIMPL_NAME& MOF_STRINGIMPL_NAME::operator = ( const MOF_STRINGIMPL_NAME& s ){
	SetString(s.m_pStr);
	return *this;
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool MOF_STRINGIMPL_NAME::operator == ( const MOF_STRINGIMPL_TYPE* v ) const{
	return ((Compare(m_pStr,v) == 0) ? true : false);
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool MOF_STRINGIMPL_NAME::operator == ( const MOF_STRINGIMPL_NAME& v ) const{
	return ((Compare(m_pStr,v.m_pStr) == 0) ? true : false);
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool MOF_STRINGIMPL_NAME::operator != ( const MOF_STRINGIMPL_TYPE* v ) const{
	return ((Compare(m_pStr,v) == 0) ? false : true);
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool MOF_STRINGIMPL_NAME::operator != ( const MOF_STRINGIMPL_NAME& v ) const{
	return ((Compare(m_pStr,v.m_pStr) == 0) ? false : true);
}

//[EOF]