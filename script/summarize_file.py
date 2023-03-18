import os

# Replace "path/to/directory" with the path to your directory
directory = "."

# Get a list of all files in the given directory
files = [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

# Sort the list of files alphabetically
files.sort()

# Create a new README file
with open(os.path.join(directory, "README.md"), "w") as readme_file:
    # Write the header
    readme_file.write("# List of Files\n\n")
    
    # Write the list of files
    for f in files:
        readme_file.write(f"- {f}\n")