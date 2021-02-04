#!/usr/bin/python3
import sys
import json
import os
import subprocess

DATA_DIR = "data"
VALIDATOR_DIR = "validator"

index = 0
def get_matching(subtask_score):
    global index
    index += 1

    valid_cases = []
    for f in os.listdir(DATA_DIR):
        if os.path.isfile(os.path.join(DATA_DIR, f)) and f.endswith(".in"):
            sys.stderr.write("Validating subtask %d against %s\n" % (index, f))
            # Run the validator
            p = subprocess.Popen(os.path.join(VALIDATOR_DIR, "sub%d" % index) + " < " + os.path.join(DATA_DIR, f), shell=True, stderr=subprocess.DEVNULL, stdout=subprocess.DEVNULL)
            p.wait()

            # The validator returns 0 upon success
            if p.returncode == 0:
                valid_cases.append(f[:-3])

    valid_cases_regex = "^({})$".format("|".join(valid_cases))

    # [subtask_score, subtask_regex, subtask_name]
    return [subtask_score, valid_cases_regex, "Subtask {}".format(str(index))]

subtasks = [get_matching(int(s)) for s in sys.argv[1:]]


print(json.dumps(subtasks, indent=2))
