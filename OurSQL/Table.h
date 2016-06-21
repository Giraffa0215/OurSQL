#pragma once
typedef char byte;
typedef unsigned short int ushort;

/* Table���ļ��еĽṹ
** -------------------------------------------------------
** |                          TCB                        | 64 bytes
** -------------------------------------------------------
** |Conlum 1 data type|Conlum 1 data length|Conlum 1 name| 64 bytes
** -------------------------------------------------------
** |Conlum 2 data type|Conlum 2 data length|Conlum 2 name| 64 bytes
** -------------------------------------------------------
** |Conlum 3 data type|Conlum 3 data length|Conlum 3 name| 64 bytes
** -------------------------------------------------------
** |Conlum n data type|Conlum n data length|Conlum n name| 64 bytes
** -------------------------------------------------------
** 0                  1                    3             63
** --------------
** |Conlum Count|
** --------------
** 0            2
** data typeΪһ��byte���ͣ�data lengthΪһ��ushort����
** ����һ���С4K��Ϊ��ʹ�����ܹ�����һ����¼�����data length�ĺͲ��ܳ���4k(4084 bytes)
** �й�Block����֯�ṹ����"Block.h"
*/
class Table
{
public:
	Table(const char *);
	~Table();

	ushort getLength();

	// �������Record������ݵ��׵�ַ
	byte* getData();

private:
	byte* data;
};

