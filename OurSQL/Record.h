#pragma once
typedef char byte;
typedef unsigned short int ushort;

class Record
{
public:
	Record(const char *);
	~Record();

	ushort getLength();

	// �������Record������ݵ��׵�ַ
	byte* getData();

private:
	byte* data;
};

