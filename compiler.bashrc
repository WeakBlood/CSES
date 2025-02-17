I actually use a bash script for compiling directly by my shell whatever is called "code.cpp"

bac() {
    local file="code.cpp"
    local output="code"

    if [[ -f "$file" ]]; then
        g++ -std=c++17 -DLOCAL "$file" -o "$output"
        if [[ $? -eq 0 ]]; then
            echo "Compilation successful. Running the program..."
            ./"$output"
        else
            echo "Compilation failed."
        fi
    else
        echo "File '$file' not found."
    fi
}
