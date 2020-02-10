#!/bin/sh

EFT_PATH_=~/Github/Corewar_42/debug

download_static_analyzer()
{
	printf "\e[32m----------\nDownloading clang static analyzer into $EFT_PATH_/static_analyzer\e[39m\n"
	curl -o checker-279.tar.bz2 https://clang-analyzer.llvm.org/downloads/checker-279.tar.bz2
	printf "\e[32m----------\nExtracting clang static analyzer...\e[39m\n"
	tar -jxf checker-279.tar.bz2
	rm -rf checker-279.tar.bz2
	mv checker-279 $EFT_PATH_/static_analyzer
}

do_static_analyzer()
{
	printf "\e[32m----------\nChecking with scan-build...\e[39m\n"
	rm -rf $EFT_PATH_/reports/*
	$EFT_PATH_/static_analyzer/bin/scan-build -o $EFT_PATH_/reports --status-bugs make debug -j9
	static_analyzer_errors=$(echo $?)
	printf "\e[32mDone.\e[39m\nPress enter to continue"
	read
}

show_report()
{
	$EFT_PATH_/static_analyzer/bin/scan-view $EFT_PATH_/reports/$(ls $EFT_PATH_/reports/)
}

download_static_analyzer
do_static_analyzer
show_report
