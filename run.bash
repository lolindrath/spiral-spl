#!/bin/bash
#
#
#

mkdir -p tmp
pushd tmp
rm -f *.spl *.icode *.cpp *.exe

cp ../test/templates.spl templates.spl

../program_gen/program_gen $1
if [ "$?" -ne "0" ] ; then
	echo "Program gen failed!"
	exit 1
fi

for file in ./fft*.spl ; do
	cat $file | ../spl2icode/spl $1 1> ${file}.icode
	if [ "$?" -ne "0" ] ; then
		echo "ICODE gen failed!"
		exit 1
	fi

	cat ${file}.icode | ../icode2cpp/icode2c $1 1> ${file}.icode.cpp
	if [ "$?" -ne "0" ] ; then
		echo "CPP gen failed!"
		exit 1
	fi

	g++ -o $file.exe -O3 -L/site/local/papi_64-3.7.0/lib -I/site/local/papi_64-3.7.0/include $file.icode.cpp /site/local/papi_64-3.7.0/lib/libpapi.a
	if [ "$?" -ne "0" ] ; then
		echo "COMPILE failed!"
		exit 1
	fi
done

popd
