import subprocess
import os

# Configuration
DUMP_DIR = "dump"
IN_FILE = os.path.join(DUMP_DIR, "in.txt")
OUT_MY = os.path.join(DUMP_DIR, "out1.txt")
OUT_BRUTE = os.path.join(DUMP_DIR, "out2.txt")
# Binaries
GEN_EXE = os.path.join(DUMP_DIR, "gen.exe")
MY_EXE = os.path.join(DUMP_DIR, "my.exe")
BRUTE_EXE = os.path.join(DUMP_DIR, "brute.exe")

def get_file_content(filepath):
    with open(filepath, 'r') as f:
        return f.read().strip()

def files_are_different(file1, file2):
    try:
        with open(file1, 'r') as f1, open(file2, 'r') as f2:
            return f1.read().split() != f2.read().split()
    except FileNotFoundError:
        return True

def run_stress_test():
    # Create dump directory if it doesn't exist
    if not os.path.exists(DUMP_DIR):
        os.makedirs(DUMP_DIR)
        print(f"Created directory: {DUMP_DIR}")

    # 1. Compile (Outputs sent to DUMP_DIR)
    try:
        print("Compiling...")
        subprocess.run(["g++", "gen.cpp", "-o", GEN_EXE], check=True, shell=True)
        subprocess.run(["g++", "my.cpp", "-o", MY_EXE], check=True, shell=True)
        subprocess.run(["g++", "brute.cpp", "-o", BRUTE_EXE], check=True, shell=True)
    except subprocess.CalledProcessError as e:
        print(f"Compilation failed: {e}")
        return

    # 2. Stress Test Loop
    for i in range(1, 1001):
        # Run Generator
        with open(IN_FILE, "w") as f:
            subprocess.run([GEN_EXE, str(i)], stdout=f, shell=True)

        # Run My Solution
        with open(IN_FILE, "r") as f_in, open(OUT_MY, "w") as f_out:
            subprocess.run([MY_EXE], stdin=f_in, stdout=f_out, shell=True)

        # Run Brute Force
        with open(IN_FILE, "r") as f_in, open(OUT_BRUTE, "w") as f_out:
            subprocess.run([BRUTE_EXE], stdin=f_in, stdout=f_out, shell=True)

        # 3. Compare and Show Results
        if files_are_different(OUT_MY, OUT_BRUTE):
            print(f"\n[!] Mismatch found on test {i}!")
            print("-" * 30)
            print(f"INPUT:\n{get_file_content(IN_FILE)}")
            print("-" * 30)
            print(f"MY OUTPUT:\n{get_file_content(OUT_MY)}")
            print("-" * 30)
            print(f"BRUTE OUTPUT:\n{get_file_content(OUT_BRUTE)}")
            print("-" * 30)
            break
        else:
            print(f"Test {i}: PASSED", end='\r')
    else:
        print("\nAll 100 tests passed!")

if __name__ == "__main__":
    run_stress_test()