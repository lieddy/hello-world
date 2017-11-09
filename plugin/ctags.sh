if [ $# -eq 0 ]; then
  echo "Usage ctags.sh <full_path>"
  exit 0
else
  echo "ctags find directory is "$1
fi
ctags -R --languages=c++ --langmap=c++:+.inl -h +.inl --c++-kinds=+px --fields=+aiKSz --extra=+q --exclude=lex.yy.cc --exclude=copy_lex.yy.cc $1
