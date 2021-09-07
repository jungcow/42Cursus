#! /bin/bash

function execute_program() {
	./account > mine.log;
}

function split_content() {
	cat mine.log | awk '{ print $2 }' > mine;
	cat test.log | awk '{ print $2 }' > test;
}

function clear_file() {
	rm -rf mine.log mine test;
	make clean;
}

function compare_log() {
	diff mine test | tee result.txt;
	echo -e "\n[You can also see through result.txt file]\n\n";
}

execute_program;
split_content;
compare_log;
clear_file;
