#pragma once
typedef char byte;
typedef unsigned short int ushort;

class Record
{
public:
	Record();
	~Record();

	ushort getSize();

	// �������Record������ݵ��׵�ַ
	byte* getData();

private:

};

