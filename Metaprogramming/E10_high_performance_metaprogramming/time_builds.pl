#!/usr/bin/perl

use strict;
use warnings;

if($#ARGV < 0){
	print STDERR "please specify the number of compilations";
	print STDERR "#ARGV:".$#ARGV;
	exit 1;
}

my $n_compilations = $ARGV[0];

sub trim{
	my $str = shift;
	$str =~ s/^\s+|\s+$//;
	return $str;
}


sub benchmark{
	my $compiler = shift;
	my ($baseline, $slow, $fast);

	print("========= $compiler x $n_compilations ==========\n");
	eval "\$baseline = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 2>&1`);
	printf("baseline: %.3fs\n", $baseline);

	eval "\$slow = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main_slow.cpp $n_compilations 2>&1`);
	printf("slow - baseline: %.3fs\n",$slow-$baseline);
	eval "\$fast = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main_fast.cpp $n_compilations 2>&1`);
	printf("fast - baseline: %.3fs    (%.2f x faster)\n",$fast-$baseline,(($slow-$baseline) / ($fast-$baseline)));
}

benchmark("gcc");
benchmark("clang");

`rm a.out`


