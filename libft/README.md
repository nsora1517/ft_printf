*This project has been created as part of the 42 curriculum by snagasak.*

# libft

## Description

**libft** は 42 カリキュラムの最初のプロジェクトとして、C 標準ライブラリの関数群をゼロから自前で実装するプロジェクトです。
標準ライブラリに頼らずに各関数を再実装することで、メモリ管理・文字列操作・ポインタ操作などの C の基礎を深く理解することが目標です。
完成した静的ライブラリ `libft.a` は、以降の 42 プロジェクトで個人用ツールボックスとして再利用することを想定しています。

ライブラリは以下の 5 つの機能グループで構成されています。

- **文字判定・変換** — 1 文字に対する分類チェックおよび大文字・小文字変換
- **文字列操作** — 長さ・コピー・検索・比較・分割・トリム・結合・マップ
- **メモリ操作** — メモリブロックのセット・コピー・移動・比較・ゼロ初期化
- **変換ユーティリティ** — 文字列から整数へのパース、整数から文字列へのフォーマット
- **ファイルディスクリプタ出力** — 任意の fd への文字・文字列・数値の書き込み
- **連結リストユーティリティ** — 片方向リスト（`t_list`）の生成・巡回・破棄

---

## ライブラリ詳細

### 文字判定・変換

| 関数 | 説明 |
|---|---|
| `ft_isalpha(int c)` | `c` がアルファベットなら 0 以外を返す |
| `ft_isdigit(int c)` | `c` が十進数字なら 0 以外を返す |
| `ft_isalnum(int c)` | `c` が英数字なら 0 以外を返す |
| `ft_isascii(int c)` | `c` が 7 ビット ASCII 文字なら 0 以外を返す |
| `ft_isprint(int c)` | `c` が印字可能文字なら 0 以外を返す |
| `ft_toupper(int c)` | `c` を大文字に変換する。小文字でなければそのまま返す |
| `ft_tolower(int c)` | `c` を小文字に変換する。大文字でなければそのまま返す |

### 文字列操作

| 関数 | 説明 |
|---|---|
| `ft_strlen(const char *str)` | ヌル終端を除いた `str` のバイト数を返す |
| `ft_strlcpy(char *dst, const char *src, size_t size)` | `src` から最大 `size - 1` バイトを `dst` にコピーし、ヌル終端する。`strlen(src)` を返す |
| `ft_strlcat(char *dst, const char *src, size_t size)` | `dst` に `src` を連結し、合計長を返す。常に `size - 1` 以内に収める |
| `ft_strchr(const char *s, int c)` | `s` 内で `c` が最初に現れる位置へのポインタを返す。なければ `NULL` |
| `ft_strrchr(const char *s, int c)` | `s` 内で `c` が最後に現れる位置へのポインタを返す。なければ `NULL` |
| `ft_strncmp(const char *s1, const char *s2, size_t n)` | `s1` と `s2` を最大 `n` バイト比較し、差を返す |
| `ft_strnstr(const char *big, const char *little, size_t len)` | `big` の先頭 `len` バイト内で `little` を探す。見つかればポインタ、なければ `NULL` |
| `ft_strdup(const char *s)` | `s` の複製を動的確保して返す |
| `ft_substr(char const *s, unsigned int start, size_t len)` | `s` の `start` バイト目から最大 `len` バイトの部分文字列を動的確保して返す |
| `ft_strjoin(char const *s1, char const *s2)` | `s1` と `s2` を連結した新しい文字列を動的確保して返す |
| `ft_strtrim(char const *s1, char const *set)` | `set` に含まれる文字を `s1` の先頭と末尾から除いた文字列を動的確保して返す |
| `ft_split(char const *s, char c)` | 区切り文字 `c` で `s` を分割し、ヌル終端の文字列配列を動的確保して返す |
| `ft_strmapi(char const *s, char (*f)(unsigned int, char))` | `s` の各文字に `f` を適用した新しい文字列を動的確保して返す |
| `ft_striteri(char *s, void (*f)(unsigned int, char*))` | インデックスと文字へのポインタを渡しながら `f` を各文字にインプレースで適用する |

### メモリ操作

| 関数 | 説明 |
|---|---|
| `ft_memset(void *s, int c, size_t n)` | `s` の先頭 `n` バイトをバイト値 `c` で埋める |
| `ft_bzero(void *b, size_t len)` | `b` の先頭 `len` バイトをゼロで埋める |
| `ft_memcpy(void *dest, const void *src, size_t n)` | `src` から `dest` へ `n` バイトコピーする（重複領域は未定義） |
| `ft_memmove(void *dest, const void *src, size_t n)` | 重複領域を正しく扱いながら `src` から `dest` へ `n` バイトコピーする |
| `ft_memchr(const void *s, int c, size_t n)` | `s` の先頭 `n` バイト内で `c` を探す。見つかればポインタ、なければ `NULL` |
| `ft_memcmp(const void *s1, const void *s2, size_t n)` | `s1` と `s2` の先頭 `n` バイトを比較し、差を返す |
| `ft_calloc(size_t nmemb, size_t size)` | `nmemb * size` バイトをゼロ初期化して動的確保する |

### 変換ユーティリティ

| 関数 | 説明 |
|---|---|
| `ft_atoi(const char *nptr)` | 先頭の空白・符号・十進数字を解析し、`int` を返す |
| `ft_itoa(int n)` | `n` の十進文字列表現を動的確保して返す |

### ファイルディスクリプタ出力

| 関数 | 説明 |
|---|---|
| `ft_putchar_fd(char c, int fd)` | ファイルディスクリプタ `fd` に `c` を書き込む |
| `ft_putstr_fd(char *s, int fd)` | ファイルディスクリプタ `fd` に文字列 `s` を書き込む |
| `ft_putendl_fd(char *s, int fd)` | ファイルディスクリプタ `fd` に文字列 `s` と改行を書き込む |
| `ft_putnbr_fd(int n, int fd)` | ファイルディスクリプタ `fd` に `n` の十進表現を書き込む |

### 連結リストユーティリティ

すべての関数は以下の `t_list` 型を対象とします。

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}   t_list;
```

| 関数 | 説明 |
|---|---|
| `ft_lstnew(void *content)` | `content` を持つ新しいノードを動的確保して返す。`next` は `NULL` |
| `ft_lstadd_front(t_list **lst, t_list *new)` | リストの先頭に `new` を挿入する |
| `ft_lstsize(t_list *lst)` | リストのノード数を `int` で返す |
| `ft_lstlast(t_list *lst)` | リストの最後のノードを返す |
| `ft_lstadd_back(t_list **lst, t_list *new)` | リストの末尾に `new` を追加する |
| `ft_lstdelone(t_list *lst, void (*del)(void *))` | `del` でコンテンツを解放し、1 つのノードを解放する。`next` は操作しない |
| `ft_lstclear(t_list **lst, void (*del)(void *))` | `del` を使ってリスト全体を削除・解放し、`*lst` を `NULL` に設定する |
| `ft_lstiter(t_list *lst, void (*f)(void *))` | 各ノードのコンテンツに `f` を適用する |
| `ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | 各ノードのコンテンツに `f` を適用した新しいリストを生成する。失敗時は `del` で後始末する |

---

## コンパイル・使い方

### ライブラリのビルド

リポジトリをクローンし、ルートで `make` を実行します。

```bash
git clone <repo-url>
cd libft
make
```

同ディレクトリに `libft.a` が生成されます。

### 他のプロジェクトから使う

`libft.a` と `libft.h` をプロジェクトにコピー（またはシンボリックリンク）し、以下のようにコンパイルします。

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
```

### Makefile ターゲット一覧

| ターゲット | 動作 |
|---|---|
| `make` / `make all` | 全 `.c` ファイルをコンパイルして `libft.a` を生成する |
| `make clean` | オブジェクトファイル（`*.o`）を削除する |
| `make fclean` | オブジェクトファイルと `libft.a` を削除する |
| `make re` | `fclean` の後に `all` を実行する |

---

## 参考資料
- [42 Libft subject](https://cdn.intra.42.fr/pdf/pdf/198722/en.subject.pdf) — 本プロジェクトの仕様書
- man page

### AI の活用について

本プロジェクトでは Claude（claude.ai / Claude Code CLI）を以下の用途で使用しました。

- **README の作成** — subject の要件に従い、この README を Claude に生成させ、その後手動でレビュー・修正した
- **エッジケースの確認** — 「この実装を壊すような入力は何か？」と問いかけ、空文字列・`NULL` ポインタ・`ft_atoi` の整数オーバーフローなどのケースを確認した
