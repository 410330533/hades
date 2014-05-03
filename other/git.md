# git
```shell
apt-get install git
git config --global user.name mahone3297
git config --global user.email 329730566@qq.com
git config --global core.editor vim
git config --global core.quotepath false
git config --global core.fileMode false
git config --global color.ui true
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.br branch
git config --global push.default matching/simple
git config --unset --global user.name
git add -p
git commit --amend
git stash
git stash pop
git ls-files --stage
git cat-file -p 264b73
git archive master | tar -x -C src
[remote "origin"]
    fetch = +refs/heads/*:refs/remotes/origin/*
    url = https://github.com/u-cosmetics/oms.git
[branch "develop"]
    remote = origin
    merge = refs/heads/develop
[branch "master"]
    remote = origin
    merge = refs/heads/master
[remote "localpc"]
    url = git@localhost:oms.git
    fetch = +refs/heads/*:refs/remotes/localpc/*
[remote "all"]
    url = https://github.com/u-cosmetics/oms.git
    url = git@localhost:oms.git
```

# git repo
```shell
mkdir test_repo.git
cd test_repo.git
git init --bare

git clone username@host:/path/to/git/repo
```

# github
```shell
185.31.17.184 github.global.ssl.fastly.net
```
