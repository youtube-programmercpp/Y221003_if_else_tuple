#include <iostream>
struct Criterion {
	const char* �\����;
	int         �Œ�_;
};
bool test()
{
	int �_��;//�ϐ�
	if (std::cin >> �_��) {
		static const Criterion �]����\[]
		{ {"�G"       , 90          }
		, {"�D"       , 80          }
		, {"��"       , 70          }
		, {"��"       , 60          }
		, {"�s��"     ,  0          }
		};
		for (const auto& � : �]����\) {
			if (�.�Œ�_ <= �_��) {
				std::cout << �.�\����;
				const auto& ��� = (&�)[-1];
				if (&��� >= �]����\) {
					std::cout << ", ����"
						<< ���.�Œ�_ - �_��
						<< "�_��" << ���.�\����
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
