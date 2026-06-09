*This project has been created as part of the 42 curriculum by snagasak.*

## 説明

`ft_printf` は C 言語で標準ライブラリの `printf()` を再実装したライブラリです。
`libftprintf.a` としてコンパイルされ、以下の変換指定子に対応しています。

| 指定子 | 説明 |
|--------|------|
| `%c` | 1文字を出力する |
| `%s` | 文字列を出力する |
| `%p` | ポインタアドレスを16進数形式で出力する |
| `%d` | 10進数整数を出力する |
| `%i` | 10進数整数を出力する |
| `%u` | 符号なし10進数整数を出力する |
| `%x` | 16進数（小文字）で出力する |
| `%X` | 16進数（大文字）で出力する |
| `%%` | パーセント記号を出力する |

## アルゴリズムとデータ構造

### 可変長引数
`ft_printf` は `<stdarg.h>` の `va_list`、`va_start`、`va_arg`、`va_end` を使用して可変長引数を処理する。`va_list` はポインタで各ヘルパー関数に渡すことで、引数を消費した際に呼び出し元のリストも進む。

### フォーマット文字列の解析
フォーマット文字列を1文字ずつ走査し、`%` を検出したら `process_char` → `handle_format` の順に呼び出す。`handle_format` はさらに文字列系（`%c` `%s` `%p` `%%`）を `handle_str` へ、数値系（`%d` `%i` `%u` `%x` `%X`）を `handle_num` へ振り分ける。`%` でない文字は直接 stdout に出力する。

### 桁出力（カウントと出力の分離）
整数の出力は「桁数カウント」と「再帰出力」を分離している。

- **符号付き整数** (`ft_putnbr_p`): `count_len` で桁数を事前に計算し、再帰で上位桁から順に `writenbr` で出力する。`INT_MIN`（-2147483648）は UB を避けるためリテラル文字列で直接出力する。
- **符号なし整数** (`ft_putunsigned_p`): ループで桁数をカウントした後、再帰関数 `ft_putnbr` で出力する。
- **16進数** (`ft_puthex_p`): `count_len` で桁数を計算し、再帰関数 `ft_putnbr_16` で出力する。`n / 16` で再帰呼び出しして上位桁を先に出力し、`n % 16` をルックアップ文字列（`"0123456789abcdef"` または `"0123456789ABCDEF"`）でインデックス参照して出力する。

いずれもバッファを使わずに任意桁数の数値を出力できる。

### NULLポインタ処理
- `%s` に NULL が渡された場合は `"(null)"` を出力する。
- `%p` に NULL が渡された場合は `"(nil)"` を出力する。

### エラー処理
すべての `write()` の返り値を確認し、`-1`（書き込みエラー）が返った場合は呼び出し元へ `-1` を伝播する。これにより本家 `printf()` のエラー時の動作に準拠している。

## 使い方

### コンパイル

```bash
make        # libftprintf.a をビルド
make clean  # オブジェクトファイルを削除
make fclean # オブジェクトファイルと libftprintf.a を削除
make re     # 一からリビルド
```

### Makefile の変数

| 変数 | 値 | 説明 |
|------|----|------|
| `NAME` | `libftprintf.a` | 生成するスタティックライブラリ名 |
| `CC` | `cc` | 使用するCコンパイラ |
| `CFLAGS` | `-Wall -Werror -Wextra` | コンパイルフラグ。全警告を有効にし、警告をエラーとして扱う |
| `PF_CMD` | `ar rcs` | ライブラリ作成コマンド。`r`=追加・更新、`c`=アーカイブ新規作成、`s`=インデックス付与 |
| `RM` | `rm -f` | ファイル削除コマンド（対象がなくてもエラーを出さない） |
| `HEADER` | `ft_printf.h` | ヘッダファイル名。パターンルール `%.o : %.c $(HEADER)` により、ヘッダ更新時に全 `.o` が再ビルドされる |

### 使用例

ヘッダをインクルードし、ライブラリをリンクする：

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    return 0;
}
```

```bash
cc main.c -L. -lftprintf -o program
```

## 参考資料

- [manページ  — PRINTF](https://nxmnpg.lemoda.net/ja/3/printf)
- [C言語の可変長引数の関数の作り方 - Qiita](https://qiita.com/subaruf/items/657c67a1809515589a7c)
- [ft_printf subject (42)](https://cdn.intra.42.fr/pdf/pdf/191246/en.subject.pdf)

### AIの使用について

以下のタスクにAIを使用した。

- **README の作成** — subject の要件に従い、この README を Claude に生成させ、その後手動でレビュー・修正した
- **テストケースの案出し**: `%p`（NULLポインタ）、`%s`（NULL文字列）など、エッジケースのテストケースの洗い出しに使用した。
