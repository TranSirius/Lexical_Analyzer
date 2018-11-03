#pragma once
#include "Buffer.hpp"
#include "SymbolTable.hpp"
#include <fstream>
typedef int State;											//定义状态机的状态类型是int

enum ERROR_TYPE {											//定义错误处理中遇到的错误类型，但在实现中没用上，我们采用的机制是在指定的状态进行指定的错误处理
	unknown,
	identifier
};

class Automata {
private:
	BufferPairs buffer_pairs;								//词法分析程序有一个缓冲对
	SymbolTable symbol_table;								//词法分析程序也有一个符号表

	std::ofstream output_file;								//产生的记号流文件
	std::string symbol_table_file;							//最后符号表的输出文件
	std::string token_file;									//记号流文件的文件名
	std::ofstream error_file;								//错误、警告信息文件

	State state;											//状态机的状态变量
	char ch;												//状态机的输入变量

	int row_ptr;											//行数统计指针
	int lexeme_ptr;											//当前行内单词数量统计指针
	long lexeme_count = 0;									//总单词数量统计

	int warning_count = 0;									//警告数统计
	int error_count = 0;									//错误数统计
	int identifier_count = 0;								//标识符统计

	int int_count = 0;										//整形常数统计
	int float_count = 0;									//浮点数统计
	int hex_int_count = 0;									//16进制整数统计
	int hex_float_count = 0;								//16进制浮点数统计
	int octal_int_count = 0;								//8进制整数统计

	int char_count = 0;										//字符常量数统计
	int string_count = 0;									//字符串常量数统计
	int comment_count = 0;									//注释统计

	int punctuation_count = 0;								//符号数量统计

	std::ofstream token_stream;								//记号流文件流

	int warning = 0;										//避免在同一个单词处，出现大量重复warning的一个flag
private:
	void get_char();										//读取一个单词
	void get_nbc();											//消灭接下来的所有空白字符，直到遇到一个非空白字符为止
	void generate_error(ERROR_TYPE error_type = unknown);	//没用上

	void backward();										//回退一个读取的字符

	bool is_octal();										//判断当前读取的字符是否是八进制数合法数字
	bool is_hex();											//判断当前读取的字符是否是十六进制的合法数字
	bool is_digit();										//判断是否是数字
	bool is_letter();										//判断是否是字母
	bool is_whitespace();									//判断当前读取的字符是否是空白字符
	bool is_float_suffix();									//判断当前读取的字符是否是浮点数后缀合法字符
	bool is_except();										//判断当前读取的字符是否是换行符，单引号和反斜杠
	bool is_escape();										//判断当前读取的字符是否是转义字符
	bool is_nonedigit();									//判断当前的字符是否是字母或下划线

	void returnFloat();										//接受一个浮点数
	void returnInt();										//接受一个十进制整数
	void returnOctInt();									//接受一个八进制整数	
	void returnHexFloat();									//接受一个16进制浮点数
	void returnHexInt();									//接受一个16进制整数
	void returnCharacterConstant();							//接受一个字符型常量
	
	void returnString();									//接受一个字符串常量
	void returnIdentifier();								//接受一个标识符或者关键字
	void returnComment();									//处理一下注释
	
	void returnPunc();										//接受一个标点符号
	//以下为各种错误处理，即：在对应的状态遇到了意料之外的字符怎么做
	//当然，也有一些接受状态的错误处理
	void state2_19_20_21_22_23_24_25SuffixError();
	void state3LetterError();
	void state3_4DotError();
	void state5Error();
	void state6Error();
	void state8Error();
	void state9Error();
	void state10Error();
	void state11Error();
	void state13_14Error();
	void state15Error();
	void state16Error();
	void state101EmptyError();
	void state101_107Error();
	void state101Error();
	void state105Warning();
	void state107Error();
	void state104_108Error();
	void state108Error();
	void constantWarning();

	void state522Error();

public:
	//构造函数，初始化缓冲对和符号表
	Automata(std::string _input_file, std::string _output_file, std::string _error_file, std::string _symbol_table):
		buffer_pairs(_input_file), output_file(_output_file), symbol_table_file(_symbol_table), error_file(_error_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		output_file << "TOKEN NAME\t\t" << "TOKEN ATTRIBUTE\n\n";
		error_file.clear();
		output_file.clear();
	};
	
	Automata(std::string _input_file, std::string _output_file, std::string _error_file) :
		buffer_pairs(_input_file), output_file(_output_file), error_file(_error_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		error_file.clear();
		output_file.clear();
	};
	
	Automata(std::string _input_file, std::string _output_file) :
		buffer_pairs(_input_file), output_file(_output_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		error_file.clear();
		token_file.clear();
		output_file.clear();
	};
	Automata(std::string _input_file) :
		buffer_pairs(_input_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
	}
	//词法分析程序执行
	void run(void);
};