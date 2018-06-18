import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-v')
parser.add_argument('-s')
args = parser.parse_args('-v 300 -s app1,app2,app3,app4'.split())
print(args)