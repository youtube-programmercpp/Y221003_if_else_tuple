#include <iostream>
#include <tuple>
int main()
{
	int �_��;//�ϐ�
	if (std::cin >> �_��) {
		static const std::tuple<const char*, int> �]����\[]
		// std::get<0>  std::get<1>
		{ {"�G"       , 90          }
		, {"�D"       , 80          }
		, {"��"       , 70          }
		, {"��"       , 60          }
		, {"�s��"     ,  0          }
		};
		for (const auto& � : �]����\) {
			const auto ��Œ�_ = std::get<1>(�);
			if (��Œ�_ <= �_��) {
				std::cout << std::get<0>(�);
				const auto& ��� = (&�)[-1];
				if (&��� >= �]����\) {
					std::cout << ", ����"
						<< std::get<1>(���) - �_��
						<< "�_��" << std::get<0>(���)
						<< '\n';
				}
				break;
			}


		}
	}
}
