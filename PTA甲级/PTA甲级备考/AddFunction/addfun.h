#ifndef ADDFUN_H
#define ADDFUN_H
namespace StructureLine {
	int myadd(int a, int b);//��ͷ�ļ��н�������
}


class f_mod {
private:
	int val;
public:
	f_mod(int _val) :val(_val) {};
	bool operator()(int input) { return input%val == 0; };
};
#endif // !ADDFUN_H
