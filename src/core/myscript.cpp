#include "./myscript.h"
namespace myscript {
    MyScript::MyScript(Char* code)
    {
        

    }

    MyScript::~MyScript()
    {
    }
    int main(int size, char* arge[]) {
        setlocale(LC_CTYPE, "");

        //BaseType* a = new BaseType();
        //NullType* b = new NullType();
        
        const Char* code = L"if 2 + 18.8 * 3 elif else";
        //(*(int*)*(int*)&code);

        lex::Lex le(lex::funcs);
        

        list<lex::Mark> s = le.run((Char*)code);

        for (auto i : s) {

            for (myscript::size t = 0; t < i.len; t++) {
                std::wcout << i.start[t];
            }
            std::wcout << L"--->";
        }
        std::wcout << L"END" << endl;



        //while (true)
        //{

        //}

        
        //const Char* str = L"125#";
        //wregex re(L"^[0-9]+");
        //wcmatch cm;
        //bool status = regex_search(str, cm, re);
        //printf("%d\n", status);
        //wprintf(L"%s\n", cm.str(0));
        //try {
        //    throw Error(func_error, L"...");
        //}
        //catch (Error) {
        //    printf("error");
        //}



        //const unicode* path = L"C:/Users/PC/source/repos/MyScript/test.msrc";
        //fstream in(path);
        //istreambuf_iterator<char> begin(in), end;
        //std::string str(begin, end);
        //in.close();
        //setlocale(LC_CTYPE, "");
        //UString u_str = anslToUnicode(str.data());
        //MyScript code(u_str);
        //wcout << "path :\n" << path << "\n" << "code:\n" << anslToUnicode(str.data()).data() << endl;
        return 0;
    }
}
// MyScript.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
#ifdef  myscript_isdebug
int main(int size, char* arge[])
{
    return myscript::main(size, arge);
}
#elif
#endif //  myscript_isdebug