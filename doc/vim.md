# vimrc
```conf
syntax enable
set autoindent
set nu
set hlsearch
set autoindent
set smartindent

set expandtab
set shiftwidth=4
set tabstop=4
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
```

# [Vundle](https://github.com/gmarik/Vundle.vim)
```shell
git clone https://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/Vundle.vim

vi .vimrc
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'
Plugin 'mileszs/ack.vim'
Plugin 'fatih/vim-go'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

Launch vim and run :PluginInstall
```

# plugin
- [gmarik/Vundle.vim](https://github.com/gmarik/Vundle.vim)
- [fatih/vim-go](https://github.com/fatih/vim-go)
```conf
Plugin 'fatih/vim-go'
```
- [kien/ctrlp.vim](https://github.com/kien/ctrlp.vim)
- [mileszs/ack.vim](https://github.com/mileszs/ack.vim)
```shell
:Ack 'class SalesOrder\b' src/Uco/OmsBundle/
```
