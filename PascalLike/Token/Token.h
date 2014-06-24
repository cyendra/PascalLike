#pragma once
#include "../std.h"

// �ʷ���Ԫ�Ļ��࣬�ǳ�����
class Token
{

public:
	
	// �ʷ���Ԫ��ö�����ͣ������֡��ַ�������ʶ�����Ǻ�
	enum Type { Unknown, Number, String, Identifier, Sign };

	// ����ı�ǩ
	enum Tag { 
		None, Integer, Real, Boolean,
		Reserved, Operator,
		Eof, Eol
	};

	// ��ȡ�ʷ���Ԫ������(Number, String, Identifier)
	Type getType();
	// ��ȡ��ǩ
	Tag getTag();

	// ���Դʷ���Ԫ������(Number, String, Identifier)
	bool isType(Type t);
	// ���Ա�ǩ
	bool isTag(Tag t);
	// �����ַ���
	

	Token();
	virtual ~Token();
	
	// ��ȡ�ʷ���Ԫ�Ĺ�ϣֵ����ϣ�������������о���
	virtual unsigned long long hashCode() = 0;
	
	// ��ȡ�ʷ���Ԫ��������д�ַ���
	virtual std::string getText() = 0;

	virtual int getInt();
	virtual double getDouble();
	virtual std::string getString();

	// ���ַ������в���
	virtual bool isWord(const char* s);

	
	static bool inReserved(const char* s);

protected:

	// �ʷ���Ԫ������
	Type type;

	// ��ǩ
	Tag tag;
private:
	static std::set<std::string> words;
};

