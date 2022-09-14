# import rich
from email.mime import image
import logging
from msilib.schema import Icon
from tkinter.ttk import Style
from rich.console import Console
from rich import print
from rich import inspect
from rich.logging import RichHandler
from rich.table import Table
from rich.progress import track
from rich.tree import Tree
from rich.markdown import Markdown
from rich.syntax import Syntax
import os
import random

os.system("cls")

c = Console()
def test_output():
    print("Timofey [bold]Starzhevsky[/bold]")
    c.print("[b]Where[/b] there is a [bold cyan]Will[/bold cyan] there [u]is[/u] a [i]way[/i].", style="i red")
    l = [False, True, 3.14, {"key":5, "key": 7}, "Like"]
    print(l)
    inspect(l, methods=True)

def test_log(): #Выдает время вывода в консоль
    enable = True
    var = {"pen": "white", "MGTU": "Best"}
    content = [range(0,20)]
    c.log("Test ", c, " def_log()", sep='')
    c.print("Something else", style = "i blue")
    c.log(var, log_locals=True)

def test_errors():
    FORMAT = "%(message)s"
    logging.basicConfig(
    level="NOTSET",
    format="%(message)s",
    datefmt="[%X]",
    handlers=[RichHandler(rich_tracebacks=True)]
    )
    log = logging.getLogger("rich")
    log.error("[bold red blink]Server is shutting down![/]", extra={"markup": True})
    log.error("123 Fucking error", extra={"highlighter":None})
    log.exception("FUCK YOU!")


def test_table():
    t = Table(show_header=True, header_style="bold #B0C4DE", title_justify="center")
    c = Console()
    t.add_column("Name", justify="center", style="dim")
    t.add_column("Links", justify="center")
    t.add_column("First description", justify="center", style="dim")
    t.add_column("Second description", justify="center", style="dim")
    t.add_row(
        "Rich", "[bold u blue]GitHub[/]", "Library for beutifull view text in console and more", "This library can print tables, can work with logs, with errors, with all colors like # and rgb(). I think they still it from css6"
    )
    t.add_row(
        "Rich", "[bold u blue]GitHub[/]", "Library for beutifull view text in console and more", "This library can print tables, can work with logs, with errors, with all colors like # and rgb(). I think they still it from css6"
    )
    t.add_row(
        "Rich", "[bold u blue]GitHub[/]", "Library for beutifull view text in console and more", "This library can print tables, can work with logs, with errors, with all colors like # and rgb(). I think they still it from css6"
    )
    t.add_row(
        "Rich", "[bold u blue]GitHub[/]", "Library for beutifull view text in console and more", "This library can print tables, can work with logs, with errors, with all colors like # and rgb(). I think they still it from css6"
    )
    c.print(t)

def test_track():
    c = Console()
    def hard_work(time):
        for i in range(time):
            a = i ** 5
    
    for a in track(range(100),description="I am working..."):
        hard_work(100000)

    files = [f"File {i}" for i in range(11)]
    with c.status("Downloading files...", spinner='clock') as st:
        while files:
            file = files.pop(0)
            hard_work(3000000)
            c.log(f"{file} successfully upload")
        c.log("All done")
        
def test_tree():
    c = Console()
    tree = Tree("🐍 Look on me",style="blue")

    def gen(tree:Tree, a):
        if a < 9:
            b = random.randint(1,a)
            for i in range(b):
                gen(tree.add(f"{a+1} floor",style="red"), a+1)
            
    gen(tree,1)
    # tree3 = tree.add("3rd floor", style="#B0C4DE")
    # tree3.add(tree2)
    c.log(tree)

# def test_read():#Нихуя не работает
#     os.system("chcp 65001")
#     c = Console()
#     with open("README.ru.md") as rools:
#         markdown = Markdown(rools.read())
#     c.print(markdown)

def test_syntax():
    code = '''
    def test_read():#Нихуя не работает
    os.system("chcp 65001")
    c = Console()
    with open("README.ru.md") as rools:
        markdown = Markdown(rools.read())
    c.print(markdown)
    '''
    c = Console()
    c.log(code)
    c.log(Syntax(code,"python", theme="monokai", line_numbers=True))

# test_output()
# test_log()
# test_errors()
# test_table()  
test_track()  
# test_tree()
# test_read() Не работает
# test_syntax()

print() 