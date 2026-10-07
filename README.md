# Transfer to External

This script accomplishes a simple task: Transfer the local files on my Mac to an external drive by running a single command.

## Installation

```bash
git clone https://github.com/crdcamp/transfer-to-external-drive.git
cd transfer-to-external-drive
clang main.c -o main
```

## Usage

Incredibly simple. Just run the script with the only argument being the name of your external drive.

**Note** that you will have to adjust `input_directory_path` found in `main.c` to get the desired source for your files. 

```bash
./main <name-of-external-drive>
```
