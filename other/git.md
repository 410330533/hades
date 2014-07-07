# git
```shell
apt-get install git
git config --global user.name mahone3297
git config --global user.email 329730566@qq.com
git config --global core.editor vim
git config --global core.quotepath false
git config --global core.fileMode false
git config core.logallrefupdates
git config --global color.ui true
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.br branch
git config --global push.default matching/simple
git config --unset --global user.name
git add -u 将本地有改动的文件标记到暂存区
git add -i
git add -p
git commit --amend
git log --pretty=oneline
git log --graph
git stash list
git stash
git stash save "message..."
git stash pop
git stash apply
git stash drop [<stash>]
git stash clear
git stash branch <branch> <stash> 基于进度创建分支
git show 94af4d747e6d9856d6e827353c2072167b971d2d
git archive --format=tar v1.0 | gzip > foo-1.0.tar.gz
git archive --format=tar --prefix=git-1.4.0/ v1.4.0 | gzip > git-1.4.0.tar.gz
git archive --format=tar.gz --prefix=git-1.4.0/ v1.4.0 > git-1.4.0.tar.gz
git archive --prefix=git-1.4.0/ -o git-1.4.0.tar.gz v1.4.0
git archive -o latest.zip HEAD
git archive -o partial.tar HEAD src doc
git clean -nd
git clean -fd
git ls-files --stage
git cat-file -t 94af4d747e6d9856d6e827353c2072167b971d2d
git cat-file -p 94af4d747e6d9856d6e827353c2072167b971d2d
git rev-parse master
vi .git/logs/refs/heads/master
git reflog show master
git tag v0.1

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
