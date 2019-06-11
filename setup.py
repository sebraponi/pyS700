from distutils.core import setup, Extension

setup(
    name                = 'pyS700',
    version             = '0.1.0',
    author              = 'Asko Promm',
    author_email        = '',
    description         = 'Python module for S700 GPIO',
    ext_modules         = [Extension('pyS700', ['source/gpio_lib.c', 'source/pyowl.c'])],
    package_dir={'': 'source'},
    packages=[''],                          
)
