/*************************************************************************//*!
					
					@file	VertexBufferBase.inl
					@brief	���_�o�b�t�@���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���_�T�C�Y�̌v�Z
		@param[in]		Flag			�v�Z����t���O�̑g�ݍ��킹

		@return			�K�v�ȃT�C�Y
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::CalculateVertexSize(VertexFlag Flag){
	//�T�C�Y
	MofU32 Size = 0;
	//���_���W
	if(Flag & VERTEXFLAG_POSITION)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//�@��
	if(Flag & VERTEXFLAG_NORMAL)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//�ڐ�
	if(Flag & VERTEXFLAG_TANGENT)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//�]�@��
	if(Flag & VERTEXFLAG_BINORMAL)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//�t�u
	if(Flag & VERTEXFLAG_TEXTURECOORDS1)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS2)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS3)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS4)
	{
		Size += sizeof(MofFloat) * 2;
	}
	//�F
	if(Flag & VERTEXFLAG_COLOR1)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF1)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(Flag & VERTEXFLAG_COLOR2)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF2)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(Flag & VERTEXFLAG_COLOR3)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF3)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(Flag & VERTEXFLAG_COLOR4)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF4)
	{
		Size += sizeof(MofFloat) * 4;
	}
	//�E�F�C�g
	if(Flag & VERTEXFLAG_WAIT1)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (Flag & VERTEXFLAG_WAIT2)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (Flag & VERTEXFLAG_WAIT3)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (Flag & VERTEXFLAG_WAIT4)
	{
		Size += sizeof(MofFloat) * 5;
	}
	//���_�T�C�Y
	if(Flag & VERTEXFLAG_POINTSIZE)
	{
		Size += sizeof(MofFloat);
	}
	//�}�g���N�X
	if (Flag & VERTEXFLAG_MATRIX)
	{
		Size += sizeof(MofFloat) * 16;
	}
	return Size;
}
/*************************************************************************//*!
		@brief			���_�t���O���̌v�Z
		@param[in]		Flag			�v�Z����t���O�̑g�ݍ��킹

		@return			�K�v�ȃt���O��
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::CalculateVertexFlagCount(VertexFlag Flag){
	//��
	MofU32 Count = 0;
	//���_���W
	if(Flag & VERTEXFLAG_POSITION)
	{
		Count++;
	}
	//�@��
	if(Flag & VERTEXFLAG_NORMAL)
	{
		Count++;
	}
	//�ڐ�
	if(Flag & VERTEXFLAG_TANGENT)
	{
		Count++;
	}
	//�]�@��
	if(Flag & VERTEXFLAG_BINORMAL)
	{
		Count++;
	}
	//�t�u
	if(Flag & VERTEXFLAG_TEXTURECOORDS1)
	{
		Count++;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS2)
	{
		Count++;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS3)
	{
		Count++;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS4)
	{
		Count++;
	}
	//�F
	if((Flag & VERTEXFLAG_COLOR1) || (Flag & VERTEXFLAG_COLORF1))
	{
		Count++;
	}
	if((Flag & VERTEXFLAG_COLOR2) || (Flag & VERTEXFLAG_COLORF2))
	{
		Count++;
	}
	if((Flag & VERTEXFLAG_COLOR3) || (Flag & VERTEXFLAG_COLORF3))
	{
		Count++;
	}
	if((Flag & VERTEXFLAG_COLOR4) || (Flag & VERTEXFLAG_COLORF4))
	{
		Count++;
	}
	//�E�F�C�g
	if(Flag & VERTEXFLAG_WAIT1)
	{
		Count++;
		Count++;
	}
	if (Flag & VERTEXFLAG_WAIT2)
	{
		Count++;
		Count++;
	}
	if (Flag & VERTEXFLAG_WAIT3)
	{
		Count++;
		Count++;
	}
	if (Flag & VERTEXFLAG_WAIT4)
	{
		Count++;
		Count++;
	}
	//���_�T�C�Y
	if(Flag & VERTEXFLAG_POINTSIZE)
	{
		Count++;
	}
	//�}�g���N�X
	if (Flag & VERTEXFLAG_MATRIX)
	{
		Count++;
	}
	return Count;
}
/*************************************************************************//*!
		@brief			����t���O�̃I�t�Z�b�g�ʒu�̌v�Z
		@param[in]		OFlag			���ׂ����t���O

		@return			�t���O�̃I�t�Z�b�g�ʒu
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::CalculateVertexOffset(VertexFlag OFlag){
	return CalculateVertexOffset(m_Flag, OFlag);
}
/*************************************************************************//*!
		@brief			����t���O�̃I�t�Z�b�g�ʒu�̌v�Z
		@param[in]		Flag			�v�Z����t���O�̑g�ݍ��킹
		@param[in]		OFlag			���ׂ����t���O

		@return			�t���O�̃I�t�Z�b�g�ʒu
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::CalculateVertexOffset(VertexFlag Flag,VertexFlag OFlag){
	//�T�C�Y
	MofU32 Size = 0;
	//���_���W
	if(OFlag == VERTEXFLAG_POSITION)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_POSITION)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//�@��
	if(OFlag == VERTEXFLAG_NORMAL)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_NORMAL)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//�ڐ�
	if(OFlag == VERTEXFLAG_TANGENT)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TANGENT)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//�]�@��
	if(OFlag == VERTEXFLAG_BINORMAL)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_BINORMAL)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//�t�u
	if(OFlag == VERTEXFLAG_TEXTURECOORDS1)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS1)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(OFlag == VERTEXFLAG_TEXTURECOORDS2)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS2)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(OFlag == VERTEXFLAG_TEXTURECOORDS3)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS3)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(OFlag == VERTEXFLAG_TEXTURECOORDS4)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS4)
	{
		Size += sizeof(MofFloat) * 2;
	}
	//�F
	if(OFlag == VERTEXFLAG_COLOR1 || OFlag == VERTEXFLAG_COLORF1)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_COLOR1)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF1)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(OFlag == VERTEXFLAG_COLOR2 || OFlag == VERTEXFLAG_COLORF2)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_COLOR2)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF2)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(OFlag == VERTEXFLAG_COLOR3 || OFlag == VERTEXFLAG_COLORF3)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_COLOR3)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF3)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(OFlag == VERTEXFLAG_COLOR4 || OFlag == VERTEXFLAG_COLORF4)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_COLOR4)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF4)
	{
		Size += sizeof(MofFloat) * 4;
	}
	//�E�F�C�g
	if(OFlag == VERTEXFLAG_WAIT1)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_WAIT1)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if(OFlag == VERTEXFLAG_WAIT2)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_WAIT2)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (OFlag == VERTEXFLAG_WAIT3)
	{
		return Size;
	}
	if (Flag & VERTEXFLAG_WAIT3)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (OFlag == VERTEXFLAG_WAIT4)
	{
		return Size;
	}
	if (Flag & VERTEXFLAG_WAIT4)
	{
		Size += sizeof(MofFloat) * 5;
	}
	//���_�T�C�Y
	if(OFlag == VERTEXFLAG_POINTSIZE)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_POINTSIZE)
	{
		Size += sizeof(MofFloat);
	}
	//�}�g���N�X
	if (OFlag == VERTEXFLAG_MATRIX)
	{
		return Size;
	}
	if (Flag & VERTEXFLAG_MATRIX)
	{
		Size += sizeof(MofFloat) * 16;
	}
	return Size;
}
/*************************************************************************//*!
		@brief			�o�b�t�@�̐ݒ�
		@param[in]		Usage			���p���@
				
		@return			TRUE			����I��<br>
						����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CVertexBufferBase::SetUsage(const BufferAccess Usage) {
	m_Usage = Usage;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���_�擾
		@param			None

		@return			���_�̎擾
*//**************************************************************************/
FORCE_INLINE LPMofVoid CVertexBufferBase::GetVertex(void) const{
	return m_pVertex;
}
/*************************************************************************//*!
		@brief			���_�T�C�Y�擾
		@param			None

		@return			���_�T�C�Y�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::GetVertexSize(void) const{
	return m_Size;
}
/*************************************************************************//*!
		@brief			���_�������擾
		@param			None

		@return			���_�������̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::GetVertexElementCount(void) const{
	return m_ElementCount;
}
/*************************************************************************//*!
		@brief			���_�t���O�擾
		@param			None

		@return			���_�t���O�̎擾
*//**************************************************************************/
FORCE_INLINE VertexFlag CVertexBufferBase::GetVertexFlag(void) const{
	return m_Flag;
}
/*************************************************************************//*!
		@brief			���_���擾
		@param			None

		@return			���_���̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::GetVertexCount(void) const{
	return m_Count;
}

//[EOF]