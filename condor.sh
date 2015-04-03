#!/bin/bash
# created by Genie
# email address should be changed into yours. 

dir=`pwd`
idir=$1
outfile=$2_output_`date +"%Y%m%d"`

subfile=subfile_$outfile

#echo $subfile
mkdir -p $idir

cat > $subfile << EOF

Universe     = vanilla

Notification = Always
Executable   = $dir/$2
Arguments    = $3 $4 $5 $6 $7 $8 $9
Request_cpus = 1
GetEnv       = True

Initialdir   = $dir/$idir
#Input        = WHEN_YOU_HAVE_INPUT_FILES
Output       = $outfile.out
Error        = $outfile.err
Log          = $outfile.log
Notify_user  = CHANGE_THIS_TO_YOUR_EMAIL

Queue
EOF

sleep 0
#cat $subfile

echo " "
echo Executable   = $dir/$2
echo Arguments    = $3 $4 $5 $6 $7 $8 $9
echo " "
condor_submit $subfile
echo " "
sleep 0
rm $subfile
