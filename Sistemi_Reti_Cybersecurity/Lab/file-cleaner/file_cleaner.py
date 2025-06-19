import argparse
import os
import sys

def walk(basepath:str, extension:str):
    for file in os.listdir(basepath):
        path = os.path.join(basepath, file)
        
        if os.path.isfile(path) and file.endswith(extension):
            print(f"{path} removed correctly")
            # os.remove(path)
        if os.path.isdir(path):
            walk(path, extension)

def validation(path:str, extension:str) -> bool:
    if not os.path.isabs(path):
        print(f"{path} is not an absolute path")
        sys.exit(1)
    if not os.path.exists(path):
        print(f"{path} doesn't exist")
        sys.exit(1)
    if not os.path.isdir(path):
        print(f"{path} is not a directory")
        sys.exit(1)
    if not extension.startswith("."):
        print(f"{path} doesn't start with .")
        sys.exit(1)

def parse_argument():
    parser = argparse.ArgumentParser(description="File cleaner given path and extension")
    parser.add_argument("--path", type=str, required=True, help="Absolute path of the directory to clean")
    parser.add_argument("--extension", type=str, required=True, help="File extension to remove")
    return parser.parse_args()

def main():
    args = parse_argument()
    
    if validation(args.path, args.extension):
        sys.exit(1)
    
    walk(args.path, args.extension)

if __name__ == "__main__":
    main()