#!/bin/bash
temph=`date | cut -c12-13`
dat=`date +"%A %d in %B of %Y (%r)"`

if [ -f  greetingmsg.txt ]
then
	rm greetingmsg.txt
fi

if [ $temph -lt 12 ]
then
    msg="Good Morning $LOGNAME, Have nice day!"
fi

if [ $temph -ge 12 -a $temph -le 16 ]
then
    msg="Good Afternoon $LOGNAME"
fi

if [ $temph -gt 16 -a $temph -le 20 ]
then
    msg="Good Evening $LOGNAME"
fi

if [ $temph -gt 20 -a $temph -le 24 ]
then
    msg="Hello, $LOGNAME"
fi

echo $msg > greetingmsg.txt

echo -e "$msg\nThis is $dat"