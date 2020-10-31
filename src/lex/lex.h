#ifndef MYSCRIPTLEX
#define MYSCRIPTLEX
#include "../core/basetype.h"
#include "../core/error.h"
#include <list>
namespace myscript {
	namespace lex {
		// �Ǻ�����
		enum class MarkType {
			_ERRROR,
			Null,// ��
			INT,// ����
			FLOAT,// ������
			ADD,// ��
			LES,// ��
			MUL,// ��
			DIV,// ��
			IF,// ���
			ELIF,// ����-���
			ELSE// ����
		};
		// �Ǻ�
		struct Mark {
			size len = 0;
			MarkType type = MarkType::_ERRROR;
			// �ڴ��������б����
			Char* start = nullptr;
		};

		typedef list<Mark> MarkList;

		static const Mark null_mark;
		/*class GetMark
		{
		public:
			GetMark();
			~GetMark();
			unsigned int line;
			char* name;
			MarkType type;
			BaseObject(*tokenbuild)(Token& self);
		private:

		};
		typedef BaseObject(*tokenbuildfunc)(Token& self);*/
		// ��üǺź��� ���ʧ�ܷ���nullptr
		typedef Mark (*getmarkfunc)(Char* s);

		// �ʷ�����
		class Lex
		{
		public:
			Lex(getmarkfunc* funcs);
			Lex(const getmarkfunc* funcs);
			~Lex();
			MarkList run(Char * code);
			MarkList run(const Char* code);
		private:
			getmarkfunc* funcs;
			size len;
		};
		static Mark add_mark = { 1, MarkType::ADD };
		static Mark les_mark = { 1, MarkType::LES };
		static Mark mul_mark = { 1, MarkType::MUL };
		static Mark div_mark = { 1, MarkType::DIV };
		static Mark if_mark = { 2, MarkType::IF };
		static Mark elif_mark = { 4, MarkType::ELIF };
		static Mark else_mark = { 4, MarkType::ELSE };


		Mark Add(Char* s);
		Mark Les(Char* s);
		Mark Mul(Char* s);
		Mark Div(Char* s);

		Mark Int(Char* s);
		Mark Float(Char* s);

		Mark If(Char* s);
		Mark Elif(Char* s);
		Mark Else(Char* s);


		static const lex::getmarkfunc funcs[] = {
			lex::Add,
			lex::Les,
			lex::Mul,
			lex::Div,
			lex::Int,
			lex::Float,
			lex::If,
			lex::Elif,
			lex::Else,
			nullptr };

	}
}
#endif