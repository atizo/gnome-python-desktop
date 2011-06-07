#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# setup.py - distutils configuration for rsvg


'''Python Bindings for the rsvg library.

PyRsvg is a set of bindings for the rsvg library.'''


import os
import sys

from distutils.core import setup
from distutils.command.install import install

MAJOR_VERSION = 2
MINOR_VERSION = 32
MICRO_VERSION = 0
VERSION = '%d.%d.%d' % (MAJOR_VERSION, MINOR_VERSION, MICRO_VERSION)

class PyRSVGBuildAndInstall(install):
    def run(self):
        os.system('sh autogen.sh --prefix=%s --enable-rsvg && make && make install' % self.install_base)

if '--no-deps' in sys.argv:
    sys.argv.remove('--no-deps')

doclines = __doc__.split('\n')

setup(name='pyrsvg',
      url='http://www.pygtk.org/',
      version=VERSION,
      license='LGPL',
      maintainer='Gustavo J. A. M. Carneiro',
      maintainer_email='gjc@inescporto.pt',
      description=doclines[0],
      long_description='\n'.join(doclines[2:]),
      provides=['rsvg'],
      requires=['pygobject'],
      cmdclass={'install': PyRSVGBuildAndInstall,
                'develop': PyRSVGBuildAndInstall})
