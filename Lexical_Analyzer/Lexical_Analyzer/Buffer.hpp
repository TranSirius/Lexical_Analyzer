#pragma once
#include<string>
#include<iostream>
#include<istream>
#include<fstream>

const int N = 4096;									//buffer pairs�У�ÿ���������Ĵ�С
typedef char buffer[N + 1];							//����buffer pairs�е�һ��buffer�ĽṹΪ����ΪN+1���ַ�����
 

class BufferPairs {
private:
	std::ifstream _file;							//�����ļ���
	int lexeme_begin = 0;							//��������ȡָ�룬ָ�򵥴ʿ�ʼ��λ��
	int _forward = 0;								//��������ǰָ�룬ָ��ǰ������λ��
	int forward_ptr = 0;							//˫bufferָ�룬ָʾ��ǰ��ǰָ�����ڵĻ������������е���һ��
	int begin_ptr = 0;								//˫bufferָ�룬ָʾ��ǰ��ʼָ�����ڵĻ������������е���һ��
	buffer buffer_pairs[2];							//����buffer pairs�Ľṹ
	bool is_empty = true;							//��־������������ȷ��һ���Ƿ��л��˷���
private:
	void load_buffer();								//��N���ַ�������������
	bool forward_is_left_end();						//�ж���ǰָ���Ƿ��ڻ����������Ե
	bool forward_is_right_end();					//�ж���ǰָ���Ƿ��ڻ��������ұ�Ե
	char begin_word();								//���ص�ǰ״̬�£�beginָ��ָ����ַ�
public:
	BufferPairs();									//�޲ι��캯������ֹ������Ļ�����������
	BufferPairs(const std::string & file_name);		//���캯��������Ĳ���Ϊ�򿪵��ļ����ļ���
	char Forward();									//��ǰָ����ǰ��һλ
	char Backward();								//��ǰָ�����һλ
	std::string Output();							//��lexeme_begin��_forward֮����ַ����������
};