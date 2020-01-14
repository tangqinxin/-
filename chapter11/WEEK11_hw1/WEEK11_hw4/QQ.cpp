#include <cmath>
#include <iostream>
#include <map>

struct Point { double x, y; };

typedef Point * PointPtr;
// �Ƚ϶��� Point ָ��� x ����� y ����
struct PointCmp {
	bool operator()(const PointPtr &lhs, const PointPtr &rhs) const {
		return lhs->x < rhs->x;
	}
};

int main() {
	// ע�⼴ʹ x ���겻��˳�� map �Խ��� x �����������
	Point points[3] = { { 2, 0 },{ 1, 0 },{ 3, 0 } };

	// mag �ǽ�����ַ���͵����� x-y ƽ���ϵ�ģ��ӳ��
	// ���ܹؼ���ָ�뵽 Point ������ϣ���� x ����˳����ǰ� Point ��ַ��˳��
	// ��ͨ��ʹ�� PointCmp ��ıȽϷ������С�
	std::map<Point *, double, PointCmp> mag({
		{ points,     2 },
		{ points + 1, 1 },
		{ points + 2, 3 }
	});

	// �� 0 ����ÿ�� y ����Ϊģ
	for (auto iter = mag.begin(); iter != mag.end(); ++iter) {
		auto cur = iter->first; // ָ�� Node ��ָ��
		cur->y = mag[cur]; // ���ʹ�� cur->y = iter->second;
	}

	// ���²���ӡÿ������ģ
	for (auto iter = mag.begin(); iter != mag.end(); ++iter) {
		auto cur = iter->first;
		mag[cur] = std::hypot(cur->x, cur->y);
		std::cout << "The magnitude of (" << cur->x << ", " << cur->y << ") is ";
		std::cout << iter->second << '\n';
	}

	// �Ի��ڷ�Χ�� for ѭ���ظ���������
	for (auto i : mag) {
		auto cur = i.first;
		cur->y = i.second;
		mag[cur] = std::hypot(cur->x, cur->y);
		std::cout << "The magnitude of (" << cur->x << ", " << cur->y << ") is ";
		std::cout << mag[cur] << '\n';
		// ע���� std::cout << iter->second << '\n'; �෴�������� 
		// std::cout << i.second << '\n'; �����ӡ���µ�ģ
	}
}