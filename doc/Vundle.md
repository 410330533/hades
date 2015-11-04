# [Vundle](https://github.com/gmarik/Vundle.vim)
```shell
git clone https://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/Vundle.vim
```

vi .vimrc
```conf
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
Plugin 'Tabular'
Plugin 'scrooloose/nerdtree'
Plugin 'ctrlp.vim'
" Plugin 'Shougo/neocomplete.vim'
Plugin 'Shougo/neocomplcache.vim'
Plugin 'Lokaltog/vim-easymotion'

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
```

# plugin
- [mileszs/ack.vim](https://github.com/mileszs/ack.vim)
```shell
:Ack 'class SalesOrder\b' src/Uco/OmsBundle/
```

- [scrooloose/nerdtree](https://github.com/scrooloose/nerdtree)
```conf
autocmd vimenter * NERDTree
```

- [Shougo/neocomplcache.vim](https://github.com/Shougo/neocomplcache.vim)
```conf
:NeoComplCacheEnable
let g:neocomplcache_enable_at_startup = 1
```

- https://github.com/Valloric/YouCompleteMe
```conf
apt-get install build-essential cmake
apt-get install python-dev
cd ~/.vim/bundle/YouCompleteMe
./install.py --clang-completer
```
