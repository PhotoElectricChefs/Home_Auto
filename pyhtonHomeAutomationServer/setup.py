from distutils.core import setup

setup(
    name='Automation Server',
    version='0.0.1',
    author='Varun Bhat',
    author_email='varunbhat@thegeektronics.in',
    packages=['AutomationServer'],
    scripts=[],
    url='http://pypi.python.org/pypi/rPiAutomationSerer/',
    license='LICENSE.txt',
    description='This package is used to control the Bluetooth Devices',
    long_description=open('README.txt').read(),
    install_requires=[
        "python-bluez",
    ],
)