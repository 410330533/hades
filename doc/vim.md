# vimrc
```conf
syntax on
set autoindent
set nu
set showmatch
set hlsearch
set autoindent
set smartindent

set expandtab
set shiftwidth=4
set tabstop=4

autocmd Filetype ruby setlocal ts=2 sts=2 sw=2
```

# command
```shell
缓冲区管理
:ls
:bn
:bp

分屏
:sp hello.php
:vs hello.php
ctrl-w [h|j|k|l]

跳转表
ctrl-o
ctrl-i

替换
%s/search/replace/g
%s/name="\w*", //cg
http://tanqisen.github.io/blog/2013/01/13/vim-search-replace-regex/

缩写
:ab asap as soon as possible
```
