# refactor_bsq

42 Reloaded Subject

First Circle

# what should we do?(どんな課題？)

Refactoring codes from CPiscine Subject, BSQ.

# Directory Structure(ファイル構成)

```
refactor_bsq
|-- README.md
`-- ref_bsq
    |-- bsq_base
    |   |-- Makefile
    |   |-- ft.h
    |   |-- ft_atoi.c
    |   |-- ft_info.c
    |   |-- ft_puts.c
    |   |-- ft_split.c
    |   |-- ft_strdup.c
    |   |-- ft_strjoin.c
    |   |-- ft_utility.c
    |   |-- ft_validate_map.c
    |   |-- helpmakesquare.c
    |   |-- main.c
    |   `-- makesquare2.c
    |-- make_map.pl
    |-- map
    `-- memo.md
```

# Status(課題の進捗)

👷 Inprogress!

[![hkikuchi's 42Project Score](https://badge42.herokuapp.com/api/project/hkikuchi/refactor_bsq)](https://github.com/JaeSeoKim/badge42)


# HOW TO MOVE IT?(ENGLISH)
日本語での使用方法の説明は[こちら](#%E3%81%A9%E3%81%86%E3%82%84%E3%81%A3%E3%81%A6%E5%8B%95%E3%81%8B%E3%81%99%E3%81%8B)



1. Git clone this repository to your rocal environment. (If you already git user and could reach here, then you know this command.)

```
git clone git@github.com:HinataKikuchi/refactor_bsq.git
```

2. JUST DO MAKE.

```
$ cd ./refactor_bsq
$ make -C ./ref_bsq/bsq_base
```


5. FIN.


# どうやって動かすか？

1. このレポジトリをクローンしてください。

```
git clone git@github.com:HinataKikuchi/refactor_bsq.git
```

2. メイクしてもろて

```
$ cd ./ft_printf
$ make -C ./srcs
```

3. コンパイルに成功するとアーカイブファイル(```libprintf.a```って名前のやつ)がsrcs下にできます。

4. もしft_printf関数を自分のファイルで使いたいときは以下の例のように使ってください。

```
$ gcc -I./ft_printf/srcs -L./ft_printf/srcs -lprintf <your_source_name>
```

5. おーわり！
