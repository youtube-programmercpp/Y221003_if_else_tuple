#include <iostream>
#include <tuple>
int main()
{
	int 点数;//変数
	if (std::cin >> 点数) {
		static const std::tuple<const char*, int> 評価基準表[]
		// std::get<0>  std::get<1>
		{ {"秀"       , 90          }
		, {"優"       , 80          }
		, {"良"       , 70          }
		, {"可"       , 60          }
		, {"不可"     ,  0          }
		};
		for (const auto& 基準 : 評価基準表) {
			const auto 基準最低点 = std::get<1>(基準);
			if (基準最低点 <= 点数) {
				std::cout << std::get<0>(基準);
				const auto& 一つ上 = (&基準)[-1];
				if (&一つ上 >= 評価基準表) {
					std::cout << ", あと"
						<< std::get<1>(一つ上) - 点数
						<< "点で" << std::get<0>(一つ上)
						<< '\n';
				}
				break;
			}


		}
	}
}
