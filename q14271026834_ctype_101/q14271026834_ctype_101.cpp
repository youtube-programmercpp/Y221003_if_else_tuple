#include <stdio.h>
#include <ctype.h>

//変換関数
void 変換(char s[])
{
	//配列 s[]に格納した⽂字列のうち、先頭の文字を奇数番目として、
	//奇数番⽬の⽂字がアルファベット⼩⽂字だった場合は⼤⽂字に、
	//偶数番⽬の⽂字がアルファベット⼤⽂字だった場合は⼩⽂字に変換し，
	//それ以外の場合は変換せず
	for (int i = 1;; ++i) {
		const unsigned char ch = s[i - 1];//i は 1 から始まっているので添え字にするには 1 を差し引く
		if (ch == '\0') {
			//Null文字なので終わり
			break;
		}
		else {
			//偶数・奇数の判定
			//i & 1 と書くと2進数の最下位ビット（LSB）が得られる
			//LSB が 0 なら偶数であり、
			//LSB が 1 なら奇数である。
			//i % 2 と書くと２で割った余りが得られる。その答えが
			// 1 なら偶数であり、
			// 0 なら奇数である。
			//【備考】i & 1 は i % 2 に比べて高速に処理される。CPUはビット演算が得意だが割り算は苦手。

			if (i & 1) { //これは if (i & 1 != 0) の意味だが、!= 0 は省略されるのが普通。i & 1 は i の最下位ビットがオンであることを確認するという意味となる。
				//奇数番目の文字
				if (islower(ch))
					s[i - 1] = _toupper(ch);//小文字なら大文字に変換
			}
			else {
				//偶数番目の文字
				if (isupper(ch))
					s[i - 1] = _tolower(ch);//大文字なら小文字に変換
			}
		}
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
