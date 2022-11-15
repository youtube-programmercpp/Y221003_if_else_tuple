//C言語ポインタ練習サンプルプログラム: ポインタを使って複雑な文字変換 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>
#include <ctype.h>

//変換関数
void 変換(char s[])
{
	//配列 s[]に格納した⽂字列のうち、先頭の文字を奇数番目として、
	//奇数番⽬の⽂字がアルファベット⼩⽂字だった場合は⼤⽂字に、
	//偶数番⽬の⽂字がアルファベット⼤⽂字だった場合は⼩⽂字に変換し，
	//それ以外の場合は変換せず

	//先頭の文字を指す first ポインタを用意（const で固定する）
	for (const char* const first = s;*s; ++s) {
		if (*s == '\0') {
			//Null文字なので終わり
			break;
		}
		else {
			//現状の s から first を差し引くと s が何番目の文字を指しているかが分かる
			//ただし、これだと先頭は 0 番目という扱いとなる
			if ((s - first) & 1) {
				//先頭を 0 番目としたときは奇数番目の文字
				//先頭を 1 番目としたときは偶数番目の文字
				if (isupper((unsigned char)*s))
					*s = _tolower(*s);//大文字なら小文字に変換
			}
			else {
				//先頭を 0 番目としたときは偶数番目の文字
				//先頭を 1 番目としたときは奇数番目の文字
				if (islower((unsigned char)*s))
					*s = _toupper(*s);//小文字なら大文字に変換
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
