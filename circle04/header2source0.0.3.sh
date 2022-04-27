#!/bin/bash

FILENAME=$(basename -- $1) && FILENAME=${FILENAME%.*}
FILEPATH=$(dirname $1)
DESTFILE=${FILEPATH}/${FILENAME}.cpp

CLASS_OPEN_SPECIFIER="^\s*(class)\s*([^{]+)\s*[:]?([^{]+).*$"
CLASS_CLOSE_SPECIFIER="^\s*}\s*;\s*$"
FUNCTIONS_NOT_IMPLEMENTED="^\s*.*\((.*)\)\s*[^{}]*;$"
VIRTUAL_STATIC=".*(virtual|static).*"
COMMENT_ONELINE_CHAR='//'
COMMENT_START_CHAR='/*'
COMMENT_END_CHAR='*/'
SEMICOLON=';'
SEMICOLON_AT_END='^.*;\s*'

lineidx=0
inClass=0
echo -e "#include \"${FILENAME}.hpp\"\n" > ${DESTFILE}
while read -r line; do
	if [[ $line =~ $CLASS_OPEN_SPECIFIER ]]; then
		inClass=1
	elif [[ $line =~ $CLASS_CLOSE_SPECIFIER ]]; then
		inClass=0
	fi
	if [[ $inClass -eq 1 && $line == "" ]]; then
		echo $line >> ${DESTFILE}
		continue
	fi
	commentline=0;
 	if [[ $line =~ "^.*($COMMENT_START_CHAR).*$" ]]; then
 		commentline=1
 	fi
 	if [[ $line =~ "^.*($COMMENT_END_CHAR).*$" ]]; then
 		commentline=0
 	fi
	if [[ $commentline -eq 0 && $line =~ $FUNCTIONS_NOT_IMPLEMENTED ]]; then
		commentpart=0
		for token in $line; do
			if [[ $token =~ ^${COMMENT_ONELINE_CHAR}.*$ ]]; then
				commentpart=1
			fi
			if [[ $commentpart -eq 1 ]]; then
				continue
			fi
			# Check Range Operator(::) Position
			rangeregex=".*\(.*"
			if [[ $inClass -eq 1 && "$token" =~ .*\(.* ]]; then
				coloned=0
				attheend=0
				typeregex="[\&\*]"
				for (( i=0; i<${#token}; i++ )); do
					x=${token:$i:1}
					if [[ $coloned -eq 0 && "$x" =~ [\&\*] ]]; then 
						echo -n "$x" >> ${DESTFILE}
					elif [[ $coloned -eq 0  && ! "$x" =~ "$typeregex" ]]; then
						echo -n "${FILENAME}::$x" >> ${DESTFILE}
						coloned=1
					else
						if [[ $x =~ $SEMICOLON ]]; then
							echo -n "$x" | sed 's/;/ {}/g' >> ${DESTFILE}
							attheend=1
						else
							echo -n "$x" >> ${DESTFILE}
						fi
					fi
				done
				if [[ $attheend -eq 0 ]]; then
					echo -n " " >> "${DESTFILE}"
				fi
				continue;
			fi
			if [[ $token =~ $VIRTUAL_STATIC ]]; then
				continue;
			fi
			if [[ $token =~ $SEMICOLON_AT_END ]]; then
				echo -n "$token" | sed 's/;/ {}/g' >> "${DESTFILE}"
			else
				echo -n "$token " >> ${DESTFILE}
			fi
		done
		commentpart=0
		echo >> "${DESTFILE}"
	fi
done < "${1}"


###############################
## v0.0.0
###############################
# virtual 키워드는 제거해서 넣기
# static 키워드는 제거해서 넣기

###############################
## v0.0.1
###############################
# class 여는 괄호가 아래 올 수도 있음 

###############################
## v0.0.2
###############################
# include 아래로 한 줄 띄움

###############################
## v0.0.3
###############################
# 코멘트는 모두 소스파일로 들어가지 않도록 함
