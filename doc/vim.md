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

# plugin
- [kien/ctrlp.vim](https://github.com/kien/ctrlp.vim)
- [mileszs/ack.vim](https://github.com/mileszs/ack.vim)

# [Vundle](https://github.com/gmarik/Vundle.vim)
```shell
git clone https://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/Vundle.vim
vi .vimrc
Launch vim and run :PluginInstall
```

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

nnoremap <F2> :set invpaste paste?<CR>
imap <F2> <C-O>:set invpaste paste?<CR>
set pastetoggle=<F2>
```
