import os
import sys


modules = [
    "gnomeapplet",
    "gnomeprint",
    ("gnomeprint.ui", "gnomeprint"),
    "gtksourceview",
    "wnck",
    ("totem.plparser", "totem"),
    "gtop",
    "nautilusburn",
    "mediaprofiles",
    "metacity",
    ]

import ltihooks

for item in modules:
    if isinstance(item, tuple):
        module, dirname = item
    else:
        module = item
        dirname = item
    sys.path.insert(0, os.path.join("..", dirname))
    try:
        __import__(module) # try to import the module to catch undefined symbols
    except ImportError, ex:
        if ex.args[0].startswith("No module named"):
            pass
        else:
            raise

ltihooks.uninstall()
