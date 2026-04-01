import os
from dotenv import load_dotenv

load_dotenv(".env.example")

print(os.getenv("MATRIX_MODE"))