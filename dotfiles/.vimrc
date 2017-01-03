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


set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'vim-ruby/vim-ruby'
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
nnoremap <F12> :exe 'NERDTreeToggle'<CR>
nnoremap <F10> :tabp<CR>
nnoremap <F11> :tabn<CR>
