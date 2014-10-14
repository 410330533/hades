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