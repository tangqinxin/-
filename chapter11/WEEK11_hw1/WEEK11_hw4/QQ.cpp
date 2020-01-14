#include <cmath>
#include <iostream>
#include <map>

struct Point { double x, y; };

typedef Point * PointPtr;
// 比较二个 Point 指针的 x 坐标和 y 坐标
struct PointCmp {
	bool operator()(const PointPtr &lhs, const PointPtr &rhs) const {
		return lhs->x < rhs->x;
	}
};

int main() {
	// 注意即使 x 坐标不按顺序， map 仍将按 x 坐标升序迭代
	Point points[3] = { { 2, 0 },{ 1, 0 },{ 3, 0 } };

	// mag 是将结点地址发送到其在 x-y 平面上的模的映射
	// 尽管关键是指针到 Point ，我们希望按 x 坐标顺序而非按 Point 地址的顺序。
	// 这通过使用 PointCmp 类的比较方法进行。
	std::map<Point *, double, PointCmp> mag({
		{ points,     2 },
		{ points + 1, 1 },
		{ points + 2, 3 }
	});

	// 从 0 更改每个 y 坐标为模
	for (auto iter = mag.begin(); iter != mag.end(); ++iter) {
		auto cur = iter->first; // 指向 Node 的指针
		cur->y = mag[cur]; // 亦可使用 cur->y = iter->second;
	}

	// 更新并打印每个结点的模
	for (auto iter = mag.begin(); iter != mag.end(); ++iter) {
		auto cur = iter->first;
		mag[cur] = std::hypot(cur->x, cur->y);
		std::cout << "The magnitude of (" << cur->x << ", " << cur->y << ") is ";
		std::cout << iter->second << '\n';
	}

	// 以基于范围的 for 循环重复以上内容
	for (auto i : mag) {
		auto cur = i.first;
		cur->y = i.second;
		mag[cur] = std::hypot(cur->x, cur->y);
		std::cout << "The magnitude of (" << cur->x << ", " << cur->y << ") is ";
		std::cout << mag[cur] << '\n';
		// 注意与 std::cout << iter->second << '\n'; 相反，上述的 
		// std::cout << i.second << '\n'; 不会打印更新的模
	}
}