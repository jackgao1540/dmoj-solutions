import os
import json

# Read the JSON data
with open("info.json", 'r') as f:
    data = json.load(f)

# Loop through each file in the directory
for filename in os.listdir('.'):
    # Get the file extension
    file_ext = os.path.splitext(filename)[-1].lower()

    # If the file is a number and has a relevant extension
    if filename[:-len(file_ext)].isdigit() and file_ext in ['.cpp', '.py', '.java']:
        # Get the problem name from the JSON data
        problem_name = data.get(filename[:-len(file_ext)], {}).get('problem', None)
        
        if problem_name:
            # Rename the file
            os.rename(filename, f"{problem_name}{file_ext}")

