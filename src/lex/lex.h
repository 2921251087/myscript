#ifndef MYSCRIPTLEX
#define MYSCRIPTLEX
#include "../core/basetype.h"
#include "../core/error.h"
#include <list>
namespace myscript {

}
namespace myscript {
	namespace lex {
		// �Ǻ�����
		enum class MarkType {
			_ERRROR,
			PASS,// ��
			INT,// ����
			FLOAT,// ������
			ADD,// ��
			LES,// ��
			MUL,// ��
			DIV// ��
		};
		// �Ǻ�
		struct Mark {
			size len = 0;
			MarkType type = MarkType::_ERRROR;
			// �ڴ��������б����
			Char* start = nullptr;
		};

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
			list<Mark> run(Char * code);
			list<Mark> run(const Char* code);
		private:
			getmarkfunc* funcs;
			size len;
		};
		static Mark add_mark = { 1, MarkType::ADD };
		static Mark les_mark = { 1, MarkType::LES };
		static Mark mul_mark = { 1, MarkType::MUL };
		static Mark div_mark = { 1, MarkType::DIV };

		Mark Int(Char* s);
		Mark Float(Char* s);
		Mark Add(Char* s);
		Mark Les(Char* s);
		Mark Mul(Char* s);
		Mark Div(Char* s);
	}
}
#endif