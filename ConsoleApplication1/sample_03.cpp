#include <iostream>
struct Criterion {
	const char* 表示名;
	int         最低点;
};
bool test()
{
	int 点数;//変数
	if (std::cin >> 点数) {
		static const Criterion 評価基準表[]
		{ {"秀"       , 90          }
		, {"優"       , 80          }
		, {"良"       , 70          }
		, {"可"       , 60          }
		, {"不可"     ,  0          }
		};
		for (const auto& 基準 : 評価基準表) {
			if (基準.最低点 <= 点数) {
				std::cout << 基準.表示名;
				const auto& 一つ上 = (&基準)[-1];
				if (&一つ上 >= 評価基準表) {
					std::cout << ", あと"
						<< 一つ上.最低点 - 点数
						<< "点で" << 一つ上.表示名
						;
				}
				std::cout << '\n';
				break;
			}
		}
		return true;
	}
	else
		return false;
}
int main()
{
	while (test())
		;
}
