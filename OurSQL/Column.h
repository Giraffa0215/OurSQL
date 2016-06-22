#pragma once
#define C_SIZE 64
#define TYPE_SIZE 1
#define LENGTH_SIZE 2
#define NAME_SIZE 61
typedef char byte;
typedef unsigned short int ushort;

/* table�еĽṹ
** |Conlum n data type|Conlum n data length|Conlum n name| 64 bytes
** -------------------------------------------------------
** 0                  1                    3             63
** data typeΪһ��byte���ͣ�data lengthΪһ��ushort����
** data type��v��ʾvarchar c��ʾchar  i��ʾint   d��ʾdouble   f��ʾfloat
*/
class Column
{
public:
	Column();
	Column(byte _dataType, ushort _dataLength, char* _dataName);
	byte get_dataType();
	ushort get_dataLength();
	char* get_dataName();
private:
	byte dataType;
	ushort dataLength;
	char* dataName;
};