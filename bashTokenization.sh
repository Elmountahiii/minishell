#!/bin/bash

tokenize() {
    local cmd="$1"
    local output_file="$2"
    (
        trap 'echo "$BASH_COMMAND" >> "$output_file"' DEBUG
        set -x
        eval "$cmd" >/dev/null 2>&1
    )
}

# Clear the output file if it exists
> result.txt

tokenize "echo 'Single quotes $HOME' > file1.txt | echo \"Double quotes $HOME\" >> file2.txt ; cat < file1.txt | grep 'quotes' | sed 's/Single/Simple/' > file3.txt << EOF" "result.txt"

echo "Tokenization results have been written to result.txt"