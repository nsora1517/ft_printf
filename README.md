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
フォーマット文字列を1文字ずつ走査し、`%` を検出したら次の文字を見て対応する変換関数を呼び出す。それ以外の文字は直接 stdout に出力する。

### 再帰による桁出力
整数・符号なし整数の出力には再帰を使用する。`n / base` で再帰呼び出しして上位桁を先に出力し、その後 `n % base` を文字として出力する。これによりバッファを使わずに任意桁数の数値を出力できる。

### 進数変換
16進数出力はルックアップ文字列（`"0123456789abcdef"` または `"0123456789ABCDEF"`）を `n % 16` でインデックス参照する。10進数と同じ再帰アプローチを使用する。

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

- [C Standard Library - printf](https://en.cppreference.com/w/c/io/fprintf)
- [Variadic functions in C - stdarg.h](https://en.cppreference.com/w/c/variadic)
- [write(2) man page](https://man7.org/linux/man-pages/man2/write.2.html)

### AIの使用について

<!-- AIをどのタスク・どの部分に使用したか記述する -->
