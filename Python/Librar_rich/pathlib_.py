from ctypes import sizeof
from msilib.schema import Directory
from rich.console import Console
from rich.tree import Tree
import pathlib
import os

c = Console()
os.system("cls")

def get_files(directory: pathlib.Path, tree: Tree):
    paths = sorted(
        pathlib.Path(directory).iterdir(),
        key = lambda path: (path.is_file(), path.name.lower())
    )
    for path in paths:
        if path.is_dir():
            style = "dim" if path.name.startswith("__") else ""
            tree_2 = tree.add(f":open_file_folder: {path.name}", style = style)
            get_files(path, tree_2)
        else:
            file_size = 500
            text = "[b green]" + str(path.name) + "(" + str(file_size) + ")"
            icon = "📄 "
            tree.add(icon + text)
            

def __main__():
    tree = Tree(":open_file_folder:", style="bold blue")
    get_files(os.path.abspath(""), tree)
    c.print(tree)
    
if __name__ == "__main__":
    __main__()