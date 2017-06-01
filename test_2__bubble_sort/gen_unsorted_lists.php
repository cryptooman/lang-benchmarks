<?php
$lists = [
    100         => 'unsorted_list_100.txt',
    1000        => 'unsorted_list_1k.txt',
    10000       => 'unsorted_list_10k.txt',
    100000      => 'unsorted_list_100k.txt',
];

foreach ($lists as $len => $file) {
    $list = '';
    for ($i = 0; $i < $len; $i++) {
        $list .= mt_rand(0, 9);
    }
    if (!file_put_contents($file, $list)) {
        exit("Failed to write file: $file\n");
    }
}
