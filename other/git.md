# git
```shell
apt-get install git
git config --global user.name mahone3297
git config --global user.email 329730566@qq.com
git config --global core.autocrlf true
git config --global core.editor vim
git config --global core.quotepath false
git config --global core.fileMode false
git config core.logallrefupdates
git config --global color.ui true
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.br branch
git config --global alias.rb rebase
git config --global push.default matching/simple
git config --unset --global user.name
git add -u 将本地有改动的文件标记到暂存区
git add -i
git add -p
git archive --format=tar v1.0 | gzip > foo-1.0.tar.gz
git archive --format=tar --prefix=git-1.4.0/ v1.4.0 | gzip > git-1.4.0.tar.gz
git archive --format=tar.gz --prefix=git-1.4.0/ v1.4.0 > git-1.4.0.tar.gz
git archive --prefix=git-1.4.0/ -o git-1.4.0.tar.gz v1.4.0
git archive -o latest.zip HEAD
git archive -o partial.tar HEAD src doc
git branch
git branch <branchname>
git branch <branchname> <start-point>
git branch -d <branchname>
git branch -D <branchname>
git branch -m <oldbranch> <newbranch>
git branch -M <oldbranch> <newbranch>
git branch -r
git cat-file -t 94af4d747e6d9856d6e827353c2072167b971d2d
git cat-file -p 94af4d747e6d9856d6e827353c2072167b971d2d
git cherry-pick b57692276cc23a0a81f06e208ff2f96274adb45a
git checkout -b develop origin/develop
git checkout --track -b develop_1 develop
git check-attr foo bar -- filename
git clone <repository> <directory>
git clone --bare <repository> <directory.git>
git clone --mirror <repository> <directory.git>
git commit --amend
git clean -nd
git clean -fd
git diff <commit1> <commit2> -- <paths>
git diff <path1> <path2>
git diff --word-diff
git fetch origin
git format-patch -s HEAD~3..HEAD
git send-email *.patch
git am mail-archive-patch
git fsck
git fsck --no-reflogs
git gc
git gc --prune=now
git init --bare /path/to/repo.git
git ls-files --stage
git log -p
git log --stat
git log --pretty=oneline
git log --graph
git prune
git push [<remote-repos> [<refspec>]]
git pull [<remote-repos> [<refspec>]]
git rebase --onto <newbase> <since> <till>
git rebase -i D^
git remote add origin git@github.com:mahone3297/hades.git
git remote set-url origin git@github.com:mahone3297/hades.git
git remote set-url --push origin git@github.com:mahone3297/hades.git
git remote rename origin newOrigin
git remote update
git remote rm origin
git revert 94af4d747e6d9856d6e827353c2072167b971d2d
git rev-parse master
git reflog
git reflog show master
git reflog expire --all
git reflog expire --expire=now --all
git show-rev
git stash list
git stash
git stash save "message..."
git stash pop
git stash apply
git stash drop [<stash>]
git stash clear
git stash branch <branch> <stash> 基于进度创建分支
git show 94af4d747e6d9856d6e827353c2072167b971d2d
git submodule add /path/to/repos/libA.git lib/lib_a
git submodule status
git submodule init
git submodule update
git svn clone file:///path/to/svn/repos/demo git-svn-demo
git svn fetch
git svn rebase
git svn dcommit
git tag
git tag <tagname> [<commit>]
git tag -a <tagname> [<commit>]
git tag -m <msg> <tagname> [<commit>]
git tag -s <tagname> [<commit>]
git tag -u <key-id> <tagname> [<commit>]
git tag -d mytag
git push origin mytag
git push origin refs/tags/*
git push origin :mytag
git pull origin refs/tags/mytag:refs/tags/mytag 远程tag有更新，需显示指定拉回

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

# github
```shell
185.31.17.184 github.global.ssl.fastly.net
```
