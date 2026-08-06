# Libft Function List

## 対象範囲

この一覧は次の実装ディレクトリを対象にする。

| ディレクトリ | 内容 |
|---|---|
| `srcs/` | libft 本体、追加ユーティリティ、`get_next_line` |
| `libarith/srcs/` | 数値・クォータニオン系の追加ライブラリ |

`static` 関数、コメントアウトされたテスト用関数は一覧対象外。

## 目次

- [Libft Function List](#libft-function-list)
	- [対象範囲](#対象範囲)
	- [目次](#目次)
	- [srcs/](#srcs)
		- [文字判定・文字変換](#文字判定文字変換)
		- [メモリ操作](#メモリ操作)
		- [文字列操作](#文字列操作)
		- [変換・メモリ確保](#変換メモリ確保)
		- [出力・エラー補助](#出力エラー補助)
		- [連結リスト](#連結リスト)
		- [読み込み](#読み込み)
	- [libarith/srcs/](#libarithsrcs)
		- [高速逆平方根](#高速逆平方根)
		- [クォータニオン](#クォータニオン)
	- [補足](#補足)

---

## srcs/

### 文字判定・文字変換

| 関数 | ソース | 概要 |
|---|---|---|
| `ft_isalnum` | `srcs/ft_isalnum.c` | 英数字判定 |
| `ft_isalpha` | `srcs/ft_isalpha.c` | アルファベット判定 |
| `ft_isascii` | `srcs/ft_isascii.c` | ASCII 範囲判定 |
| `ft_isdigit` | `srcs/ft_isdigit.c` | 数字判定 |
| `ft_islower` | `srcs/ft_islower.c` | 小文字判定 |
| `ft_isprint` | `srcs/ft_isprint.c` | 印字可能文字判定 |
| `ft_isspace` | `srcs/ft_isspace.c` | 空白文字判定 |
| `ft_isupper` | `srcs/ft_isupper.c` | 大文字判定 |
| `ft_isvalue` | `srcs/ft_isvalue.c` | 文字列が数値として扱えるか判定 |
| `ft_tolower` | `srcs/ft_tolower.c` | 大文字を小文字へ変換 |
| `ft_toupper` | `srcs/ft_toupper.c` | 小文字を大文字へ変換 |

### メモリ操作

| 関数 | ソース | 概要 |
|---|---|---|
| `ft_bzero` | `srcs/ft_bzero.c` | 指定領域をゼロクリア |
| `ft_memchr` | `srcs/ft_memchr.c` | メモリ領域から指定バイトを検索 |
| `ft_memcmp` | `srcs/ft_memcmp.c` | メモリ領域をバイト単位で比較 |
| `ft_memcpy` | `srcs/ft_memcpy.c` | メモリ領域をコピー |
| `ft_memmove` | `srcs/ft_memmove.c` | 重複を考慮してメモリ領域をコピー |
| `ft_memset` | `srcs/ft_memset.c` | 指定バイトでメモリ領域を埋める |

### 文字列操作

| 関数 | ソース | 概要 |
|---|---|---|
| `ft_split` | `srcs/ft_split.c` | 区切り文字で文字列を分割 |
| `ft_split_toi` | `srcs/ft_split_toi.c` | 区切り文字で分割した文字列を `int` 配列へ変換 |
| `ft_strchr` | `srcs/ft_strchr.c` | 文字列から最初の指定文字を検索 |
| `ft_strcmp` | `srcs/ft_strcmp.c` | 文字列を比較 |
| `ft_strdup` | `srcs/ft_strdup.c` | 文字列を複製 |
| `ft_striteri` | `srcs/ft_striteri.c` | 文字列の各文字に関数を適用 |
| `ft_strjoin` | `srcs/ft_strjoin.c` | 2 つの文字列を連結して新規確保 |
| `ft_strlcat` | `srcs/ft_strlcat.c` | サイズ制限付き文字列連結 |
| `ft_strlcpy` | `srcs/ft_strlcpy.c` | サイズ制限付き文字列コピー |
| `ft_strlen` | `srcs/ft_strlen.c` | 文字列長を取得 |
| `ft_strmapi` | `srcs/ft_strmapi.c` | 各文字への関数適用結果で新しい文字列を作成 |
| `ft_strncmp` | `srcs/ft_strncmp.c` | 最大 `n` 文字まで文字列を比較 |
| `ft_strnstr` | `srcs/ft_strnstr.c` | 長さ制限付き部分文字列検索 |
| `ft_strrchr` | `srcs/ft_strrchr.c` | 文字列から最後の指定文字を検索 |
| `ft_strtrim` | `srcs/ft_strtrim.c` | 先頭・末尾から指定文字集合を削除 |
| `ft_substr` | `srcs/ft_substr.c` | 部分文字列を新規確保 |

### 変換・メモリ確保

| 関数 | ソース | 概要 |
|---|---|---|
| `ft_atoi` | `srcs/ft_atoi.c` | 文字列を `int` に変換 |
| `ft_calloc` | `srcs/ft_calloc.c` | ゼロ初期化済みメモリを確保 |
| `ft_itoa` | `srcs/ft_itoa.c` | `int` を文字列へ変換 |
| `ft_strtol` | `srcs/ft_strtol.c` | 基数指定付きで文字列を `long` に変換 |

### 出力・エラー補助

| 関数 | ソース | 概要 |
|---|---|---|
| `ft_putchar_fd` | `srcs/ft_putchar_fd.c` | 文字をファイルディスクリプタへ出力 |
| `ft_putstr_fd` | `srcs/ft_putstr_fd.c` | 文字列をファイルディスクリプタへ出力 |
| `ft_putendl_fd` | `srcs/ft_putendl_fd.c` | 文字列と改行をファイルディスクリプタへ出力 |
| `ft_putnbr_fd` | `srcs/ft_putnbr_fd.c` | 整数をファイルディスクリプタへ出力 |
| `ft_putbit` | `srcs/ft_putbit.c` | 整数をビット列として標準出力へ出力 |
| `print_bits` | `srcs/ft_putbit.c` | 任意メモリ領域をビット列として標準出力へ出力 |
| `perrturn` | `srcs/perrturn.c` | `perror` を呼び、指定ステータスを返す |
| `ret_errmsg` | `srcs/ret_errmsg.c` | メッセージを標準エラーへ出し、指定コードを返す |

### 連結リスト

| 関数 | ソース | 概要 |
|---|---|---|
| `ft_lstadd_back` | `srcs/ft_lstadd_back.c` | リスト末尾にノードを追加 |
| `ft_lstadd_front` | `srcs/ft_lstadd_front.c` | リスト先頭にノードを追加 |
| `ft_lstclear` | `srcs/ft_lstclear.c` | リスト全体を削除 |
| `ft_lstdelone` | `srcs/ft_lstdelone.c` | 単一ノードを削除 |
| `ft_lstiter` | `srcs/ft_lstiter.c` | 各ノードに関数を適用 |
| `ft_lstlast` | `srcs/ft_lstlast.c` | 末尾ノードを取得 |
| `ft_lstmap` | `srcs/ft_lstmap.c` | 各ノードを変換して新しいリストを作成 |
| `ft_lstnew` | `srcs/ft_lstnew.c` | 新しいノードを作成 |
| `ft_lstsize` | `srcs/ft_lstsize.c` | リストのノード数を取得 |

### 読み込み

| 関数 | ソース | 概要 |
|---|---|---|
| `get_next_line` | `srcs/get_next_line.c` | ファイルディスクリプタから 1 行ずつ読み込む |

---

## libarith/srcs/

### 高速逆平方根

| 関数 | ソース | 概要 |
|---|---|---|
| `q_rsqrtf` | `libarith/srcs/q_rsqrt.c` | `1 / sqrtf(number)` の近似値を高速計算 |

### クォータニオン

| 関数 | ソース | 概要 |
|---|---|---|
| `quater_normalize` | `libarith/srcs/quaternion.c` | クォータニオンを正規化 |
| `quater_multiply` | `libarith/srcs/quaternion.c` | 2 つのクォータニオンを乗算 |
| `quater_conjugate` | `libarith/srcs/quaternion.c` | 共役クォータニオンを取得 |
| `quater_rotate` | `libarith/srcs/quaternion.c` | クォータニオンで 3D ベクトルを回転 |
| `quater_axis_angle` | `libarith/srcs/quaternion.c` | 軸と角度からクォータニオンを生成 |

---

## 補足

| 種別 | ヘッダ |
|---|---|
| libft 本体 | `libft.h`, `ft/ctype.h`, `ft/string.h`, `ft/stdlib.h`, `ft/stdio.h` |
| get_next_line | `get_next_line.h` |
| libarith | `libarith.h` |

`srcs/ft_strtol.c` には `__ft_strtol` も定義されているが、公開ヘッダに載る通常利用 API は `ft_strtol`。
