import os
import sys

if sys.base_prefix != sys.prefix:
    print("we are in VM")
print(f"info: {sys.prefix}")

#  python3 -m venv path/to/venv/

# $> python3 -m venv matrix_env
# $> source matrix_env/bin/activate
# (matrix_env) $> python3 construct.py
# Should detect virtual environment and show details

print(
    f"exec: {sys.executable}\n"
    f"ve: {os.path.basename(sys.prefix)}\n"
      )
