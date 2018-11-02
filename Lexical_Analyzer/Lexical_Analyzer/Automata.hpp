#pragma once
#include "Buffer.hpp"
#include "SymbolTable.hpp"
#include <fstream>
typedef int State;											//����״̬����״̬������int

enum ERROR_TYPE {											//����������������Ĵ������ͣ�����ʵ����û���ϣ����ǲ��õĻ�������ָ����״̬����ָ���Ĵ�����
	unknown,
	identifier
};

class Automata {
private:
	BufferPairs buffer_pairs;								//�ʷ�����������һ�������
	SymbolTable symbol_table;								//�ʷ���������Ҳ��һ�����ű�

	std::ofstream output_file;								//�����ļǺ����ļ�
	std::string symbol_table_file;							//�����ű������ļ�
	std::string token_file;									//�Ǻ����ļ����ļ���
	std::ofstream error_file;								//���󡢾�����Ϣ�ļ�

	State state;											//״̬����״̬����
	char ch;												//״̬�����������

	int row_ptr;											//����ͳ��ָ��
	int lexeme_ptr;											//��ǰ���ڵ�������ͳ��ָ��
	long lexeme_count = 0;									//�ܵ�������ͳ��

	int warning_count = 0;									//������ͳ��
	int error_count = 0;									//������ͳ��
	int identifier_count = 0;								//��ʶ��ͳ��

	int int_count = 0;										//���γ���ͳ��
	int float_count = 0;									//������ͳ��
	int hex_int_count = 0;									//16��������ͳ��
	int hex_float_count = 0;								//16���Ƹ�����ͳ��
	int octal_int_count = 0;								//8��������ͳ��

	int char_count = 0;										//�ַ�������ͳ��
	int string_count = 0;									//�ַ���������ͳ��
	int comment_count = 0;									//ע��ͳ��

	int punctuation_count = 0;								//��������ͳ��

	std::ofstream token_stream;								//�Ǻ����ļ���

	int warning = 0;										//������ͬһ�����ʴ������ִ����ظ�warning��һ��flag
private:
	void get_char();										//��ȡһ������
	void get_nbc();											//��������������пհ��ַ���ֱ������һ���ǿհ��ַ�Ϊֹ
	void generate_error(ERROR_TYPE error_type = unknown);	//û����

	void backward();										//����һ����ȡ���ַ�

	bool is_octal();										//�жϵ�ǰ��ȡ���ַ��Ƿ��ǰ˽������Ϸ�����
	bool is_hex();											//�жϵ�ǰ��ȡ���ַ��Ƿ���ʮ�����ƵĺϷ�����
	bool is_digit();										//�ж��Ƿ�������
	bool is_letter();										//�ж��Ƿ�����ĸ
	bool is_whitespace();									//�жϵ�ǰ��ȡ���ַ��Ƿ��ǿհ��ַ�
	bool is_float_suffix();									//�жϵ�ǰ��ȡ���ַ��Ƿ��Ǹ�������׺�Ϸ��ַ�
	bool is_except();										//�жϵ�ǰ��ȡ���ַ��Ƿ��ǻ��з��������źͷ�б��
	bool is_escape();										//�жϵ�ǰ��ȡ���ַ��Ƿ���ת���ַ�
	bool is_nonedigit();									//�жϵ�ǰ���ַ��Ƿ�����ĸ���»���

	void returnFloat();										//����һ��������
	void returnInt();										//����һ��ʮ��������
	void returnOctInt();									//����һ���˽�������	
	void returnHexFloat();									//����һ��16���Ƹ�����
	void returnHexInt();									//����һ��16��������
	void returnCharacterConstant();							//����һ���ַ��ͳ���
	
	void returnString();									//����һ���ַ�������
	void returnIdentifier();								//����һ����ʶ�����߹ؼ���
	void returnComment();									//����һ��ע��
	
	void returnPunc();										//����һ��������
	//����Ϊ���ִ����������ڶ�Ӧ��״̬����������֮����ַ���ô��
	//��Ȼ��Ҳ��һЩ����״̬�Ĵ�����
	void state2_19_20_21_22_23_24_25SuffixError();
	void state3LetterError();
	void state3_4DotError();
	void state5Error();
	void state6Error();
	void state8Error();
	void state9Error();
	void state10Error();
	void state11Error();
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
	//���캯������ʼ������Ժͷ��ű�
	Automata(std::string _input_file, std::string _output_file, std::string _error_file, std::string _symbol_table):
		buffer_pairs(_input_file), output_file(_output_file), symbol_table_file(_symbol_table), error_file(_error_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
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
	//�ʷ���������ִ��
	void run(void);
};