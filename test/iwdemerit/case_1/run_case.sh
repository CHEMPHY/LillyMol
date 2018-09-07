#! /bin/bash
if [[ -z "$BIN_DIR" ]]
then
# undefined BIN_DIR
    BIN_DIR="../../../bin/Linux-gcc-7.2.1"
fi
command=$BIN_DIR/iwdemerit
case_id="Case 1"
echo "Testing:  $command"

name1=foo.demerit
name1_out=out/foo.demerit
name2=err.txt
name3=log.txt
diff_tool=../../fileDiff.sh
$command -A D -A I -S foo -G - -f 99999  -t -W imp2exp -W maxe=1 -E autocreate -q F:in/PAINS/queries_latest -O hard -W dnv=0 -W slist  -i smi in/pubchem_example.smi>>log.txt 2>>err.txt

$diff_tool $name1 $name1_out
ret1=$?

if [ $ret1 -eq 1 ]
then
    echo "$case_id : TEST PASS"
else
    echo "$case_id : TEST FAIL"
fi
rm $name1 $name2 $name3
