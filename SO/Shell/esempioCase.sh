# append: invocazione append [dadove] adove
case $# in
    1) cat >> $1;;
    2) cat < $1 >> $2;;
    *) echo uso: append [dadove] adove;
    exit 1;;
esac