#!/usr/bin/env python
import glob
import os
import sys
import unittest
import common

SKIP_FILES = ['common', 'runtests']

dir = os.path.split(os.path.abspath(__file__))[0]
os.chdir(dir)

def gettestnames():
    files = [fname[:-3] for fname in glob.glob('test*.py')
             if fname not in SKIP_FILES]
    return files
        
suite = unittest.TestSuite()
loader = unittest.TestLoader()

for name in gettestnames():
    suite.addTest(loader.loadTestsFromName(name))
    
testRunner = unittest.TextTestRunner()
testRunner.run(suite)
