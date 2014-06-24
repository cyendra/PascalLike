#pragma once
#include "../std.h"

// 词法单元的基类，是抽象类
class Token
{

public:
	
	// 词法单元的枚举类型，有数字、字符串、标识符、记号
	enum Type { Unknown, Number, String, Identifier, Sign };

	// 具体的标签
	enum Tag { 
		None, Integer, Real, Boolean,
		Reserved, Operator,
		Eof, Eol
	};

	// 获取词法单元的类型(Number, String, Identifier)
	Type getType();
	// 获取标签
	Tag getTag();

	// 测试词法单元的类型(Number, String, Identifier)
	bool isType(Type t);
	// 测试标签
	bool isTag(Tag t);
	// 测试字符串
	

	Token();
	virtual ~Token();
	
	// 获取词法单元的哈希值，哈希函数由子类自行决定
	virtual unsigned long long hashCode() = 0;
	
	// 获取词法单元的字面书写字符串
	virtual std::string getText() = 0;

	virtual int getInt();
	virtual double getDouble();
	virtual std::string getString();

	// 对字符串进行测试
	virtual bool isWord(const char* s);

	
	static bool inReserved(const char* s);

protected:

	// 词法单元的类型
	Type type;

	// 标签
	Tag tag;
private:
	static std::set<std::string> words;
};

