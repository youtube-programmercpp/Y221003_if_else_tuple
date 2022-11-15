//C++構造体とラムダ式の応用サンプルプログラム: 複雑な文字変換 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>
#include <mbctype.h>

//
//	単一バイト文字の文字種条件と変換処理の仕様を構造体にする
//
const struct SingleByteCharTransformOperator {
	int  (*条件)(unsigned char ch) noexcept; //文字種条件: この文字種である場合に
	void (*変換)(char        * s ) noexcept; //変換処理  : 変換処理を実施する

	bool 条件に合えば変換実施(char* s) const noexcept
	{
		if ((*条件)(*s)) {
			(*変換)(s);
			return true;
		}
		else
			return false;
	}
} 奇数番目文字用の仕様 = { [](unsigned char ch) noexcept {return islower(ch); } , [](char* s) noexcept {*s = _toupper(*s); } }
, 偶数番目文字用の仕様 = { [](unsigned char ch) noexcept {return isupper(ch); } , [](char* s) noexcept {*s = _tolower(*s); } }
;
//変換関数
void 変換(char s[]) noexcept
{
	for (bool 奇数番目の文字である = true; *s; 奇数番目の文字である = !奇数番目の文字である) {
		if ((奇数番目の文字である ? 奇数番目文字用の仕様 : 偶数番目文字用の仕様).条件に合えば変換実施(s))
			++s;
		else if (_ismbblead((unsigned char)*s))
			s += 2;
		else
			++s;
	}
}
int main()
{
	for (;;) {
		fputs("String: ", stdout);
		//キーボードから⽂字列を読み込み，配列 s[]に格納する。
		char s[80];
		if (fgets(s, sizeof s, stdin) == NULL) {
			//EOFまたはエラーなので終わり
			break;
		}
		else {
			//配列 s[]に格納した⽂字列を2 ⾏⽬のように表⽰する。
			fputs("Original: ", stdout);
			fputs(s, stdout);
			//仕様に基づいて変換を実施
			変換(s);
			//変換後の s を実⾏例の 3 ⾏⽬のように表⽰する。
			fputs("Transformed: ", stdout);
			fputs(s, stdout);
		}
	}
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q14271026834
ゆろさん

2022/11/14 22:22

2回答

char 型配列 s[]を次のように宣⾔して
char s[80];

キーボードから⽂字列を読み込み，配列 s[]に格納する。
配列 s[]に格納した⽂字列を2 ⾏⽬のように表⽰する。
配列 s[]に格納した⽂字列のうち、先頭の文字を奇数番目として、奇数番⽬の⽂字がアルファベット⼩⽂字だった場合は⼤⽂字に、偶数番⽬の⽂字がアルファベット⼤⽂字だった場合は⼩⽂字に変換し，それ以外の場合は変換せずに実⾏例の 3 ⾏⽬のように表⽰する。
以上の命令を実行するにはどんなコードを書けばいいですか？

String: Program
Original: Program
Transformed: PrOgRaM
String: 22‐November‐2022
Original: 22‐November‐2022
Transformed: 22‐nOvEmBeR‐2022

C言語関連 | プログラミング・41閲覧
*/
